#include "../include/npc.h"

NPC::NPC(NpcType _type, std::string _name, int _x, int _y) : type(_type), name(_name), x(_x), y(_y) {}

NPC::NPC(NpcType _type, std::istream& is) : type(_type)
{
    is >> name >> x >> y;
}

std::string NPC::getName()
{
    return this->name;
}

std::string NPC::getType()
{
    switch (type)
    {
    case 1 :
        return "BearType";
        break;
    case 2 :
        return "SquirrelType";
        break;
    case 3 :
        return "OrcType";
        break;
    default:
        return "Unknown";
        break;
    }
}

float NPC::distance(NPC &other)
{
    return sqrt(pow((x - other.x), 2) + pow((y - other.y), 2));
}

bool NPC::visit(Bear &monster) 
{
    return false;
}

bool NPC::visit(Squirrel &monster) 
{
    return false;
}

bool NPC::visit(Orc &monster) 
{
    return false;
}

size_t NPC::countObservers()
{
    return observers.size();
}

void NPC::subscribe(std::shared_ptr<Observer> observer)
{
    observers.insert(observer);
}

void NPC::unsubscribe(std::shared_ptr<Observer> observer)
{
    std::cout << observers.size() << std::endl;
    observers.erase(observer);
    std::cout << observers.size() << std::endl;
}

void NPC::notify(NPC &attacker, NPC &defender)
{
    for (auto observer : observers) {
        observer->update(attacker, defender);
    }
}

std::ostream &operator<<(std::ostream &os, NPC &npc) 
{
    os << "Type : " << npc.getType() << ", name : " << npc.name << ", x : " << npc.x << ", y : " << npc.y << std::endl;
    return os;
}