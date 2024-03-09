#include "include/declaration.h"
#include "include/npc.h"
#include "include/bear.h"
#include "include/squirrel.h"
#include "include/orc.h"
#include "include/observerConsole.h"
#include "include/observerFile.h"
#include "include/factory.h"
#include "include/fight.h"

int main() {
    std::ofstream file(fileOutput);
    file.close();

    std::set<std::shared_ptr<NPC>> monsters;

    int count = 1;
    for (size_t i = 0; i < 10; ++i)
    {
        monsters.insert(factory(NpcType(std::rand() % 3 + 1),
                            std::to_string(count),
                            std::rand() % 100,
                            std::rand() % 100));
        ++count;
    }

    ObserverConsole observer1;
    ObserverFile observer2;

    std::shared_ptr<ObserverConsole> observer11 = std::make_shared<ObserverConsole>(observer1);
    std::shared_ptr<ObserverFile> observer22 = std::make_shared<ObserverFile>(observer2);

    for (auto &monster : monsters)
    {
        std::cout << *monster;
        monster->subscribe(observer11);
        monster->subscribe(observer22);
    }
    std::cout << std::endl;
    for (size_t distance = 20; (distance <= 100) && !monsters.empty(); distance += 10)
    {
        auto dead_list = fight(monsters, distance);
        for (auto &d : dead_list)
            monsters.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;

    }

    std::cout << "Survivors: " << monsters.size() << std::endl;
    for (auto &monster : monsters)
    {
        std::cout << *monster;
    }

    return 0;
}