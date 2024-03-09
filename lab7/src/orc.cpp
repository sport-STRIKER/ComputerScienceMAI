#include "../include/orc.h"

Orc::Orc(std::string name, int x, int y) : NPC(OrcType, name, x, y) {}

Orc::Orc(std::istream& is) : NPC(OrcType, is) {}

int Orc::getDistMove()
{
    return dist_move;
}

int Orc::getDistFight()
{
    return dist_fight;
}

bool Orc::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Orc>(this,[](Orc*){}));
}

bool Orc::visit(std::shared_ptr<Bear> monster)
{
    if (win()) 
    {
        notify(std::shared_ptr<Orc>(this,[](Orc*){}), monster);
        return true;
    }
    return false;
}

bool Orc::visit(std::shared_ptr<Orc> monster)
{
    if (win()) 
    {
        notify(std::shared_ptr<Orc>(this,[](Orc*){}), monster);
        return true;
    }
    return false;
}