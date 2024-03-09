#include "../include/bear.h"

Bear::Bear(std::string name, int x, int y) : NPC(BearType, name, x, y) {}

Bear::Bear(std::istream &is) : NPC(BearType, is) {}

int Bear::getDistMove()
{
    return dist_move;
}

int Bear::getDistFight()
{
    return dist_fight;
}

bool Bear::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Bear>(this,[](Bear*){}));
}

bool Bear::visit(std::shared_ptr<Squirrel> monster) 
{
    if (win()) 
    {
        notify(std::shared_ptr<Bear>(this,[](Bear*){}), monster);
        return true;
    }
    return false;
}