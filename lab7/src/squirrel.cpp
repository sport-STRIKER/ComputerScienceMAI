#include "../include/squirrel.h"

Squirrel::Squirrel(std::string name, int x, int y) : NPC(SquirrelType, name, x, y) {}

Squirrel::Squirrel(std::istream& is) : NPC(SquirrelType, is) {}

int Squirrel::getDistMove()
{
    return dist_move;
}

int Squirrel::getDistFight()
{
    return dist_fight;
}

bool Squirrel::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Squirrel>(this,[](Squirrel*){}));
}