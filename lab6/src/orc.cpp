#include "../include/orc.h"

Orc::Orc(std::string name, int x, int y) : NPC(OrcType, name, x, y) {}

Orc::Orc(std::istream& is) : NPC(OrcType, is) {}

bool Orc::accept(NPC &visitor) 
{
    return visitor.visit(*this);
}

bool Orc::visit(Bear &monster)
{
    notify(*this, monster);
    return true;
}

bool Orc::visit(Orc &monster) 
{
    notify(*this, monster);
    return true;
}
