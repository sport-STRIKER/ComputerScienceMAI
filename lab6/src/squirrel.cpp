#include "../include/squirrel.h"

Squirrel::Squirrel(std::string name, int x, int y) : NPC(SquirrelType, name, x, y) {}

Squirrel::Squirrel(std::istream& is) : NPC(SquirrelType, is) {}

bool Squirrel::accept(NPC &visitor) 
{
    return visitor.visit(*this);
}
