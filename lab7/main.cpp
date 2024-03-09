#include "include/declaration.h"
#include "include/npc.h"
#include "include/bear.h"
#include "include/squirrel.h"
#include "include/orc.h"
#include "include/observerConsole.h"
#include "include/observerFile.h"
#include "include/factory.h"
#include "include/fight.h"

int main()
{
    std::set<std::shared_ptr<NPC>> array; // монстры

    int n = 1;
    for (size_t i = 0; i < 50; ++i)
    {
        array.insert(factory(NpcType(std::rand() % 3 + 1),
                            std::to_string(n),
                            std::rand() % 100,
                            std::rand() % 100));
        ++n;
    }

    ObserverConsole obc;
    ObserverFile obv;

    for (auto &monster : array)
    {
        // monster->subscribe(std::make_shared<ObserverConsole>(obc));
        monster->subscribe(std::make_shared<ObserverFile>(obv));
    }

    const int MAX_X{100};
    const int MAX_Y{100};
    bool stop = false;

    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y, &stop]()
    {
        time_t start_time = time(0);

        while (true)
        {
            if (time(0) - start_time > STOP) 
            {
                stop = true;
                break;
            }
            for (std::shared_ptr<NPC> npc : array)
            {
                    if(npc->isAlive()){
                        int distMove = npc->getDistMove();
                        int shift_x = (std::rand() % distMove) * (std::rand() % 3 - 1);
                        int shift_y;
                        if (shift_x >= 0) shift_y = (distMove - shift_x) * (std::rand() % 3 - 1);
                        else shift_y = (distMove + shift_x) * (std::rand() % 3 - 1);
                        npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                    }
            }
            
            for (std::shared_ptr<NPC> npc : array)
                for (std::shared_ptr<NPC> other : array)
                    if (other != npc)
                        if (npc->isAlive())
                        if (other->isAlive())
                        if (npc->isClose(other))
                            FightManager::get().add_event({npc, other});

            std::this_thread::sleep_for(30ms);
        }});

    while (true)
    {
        if (stop) break;

        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        
        std::array<char, grid * grid> fields{0};
        for (std::shared_ptr<NPC> npc : array)
        {
            auto [x, y] = npc->position();
            int i = x / step_x;
            int j = y / step_y;
            if (i >= grid) --i;
            if (j >= grid) --j;
            
            if (npc->isAlive())
            {
                switch (npc->getIntType())
                {
                case BearType:
                    fields[i + grid * j] = 'B';
                    break;
                case SquirrelType:
                    fields[i + grid * j] = 'S';
                    break;
                case OrcType:
                    fields[i + grid * j] = 'O';
                    break;
                default:
                    break;
                }
            }
        }

        std::lock_guard<std::shared_mutex> lck(print_mutex);
        for (int j = 0; j < grid; ++j)
        {
            for (int i = 0; i < grid; ++i)
            {
                char c = fields[i + j * grid];
                if (c != 0)
                    std::cout << "[" << c << "]";
                else
                    std::cout << "[ ]";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::this_thread::sleep_for(1s);
    };

    move_thread.join();
    fight_thread.join();

    std::cout << std::endl;

    int count = 0;
    for (auto &monster : array)
    {
        if (monster->isAlive())
        {
            std::cout << *monster;
            ++count;
        }
    }

    std::cout << "Survivors: " << count << std::endl;

    return 0;
}