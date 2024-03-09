#include "../include/factory.h"

std::shared_ptr<NPC> factory(NpcType type, std::string name, int x, int y)
{
    switch (type)
    {
        case BearType :
            return std::make_shared<Bear>(name, x, y);
            break;
        case SquirrelType :
            return std::make_shared<Squirrel>(name, x, y);
            break;
        case OrcType :
            return std::make_shared<Orc>(name, x, y);
            break;
        default:
            std::cout << "unexpected type : " << type << std::endl;
            break;
    }
    return nullptr;
}

std::shared_ptr<NPC> factory(std::istream &is)
{
    int type;
    is >> type;
    switch (type)
    {
        case BearType :
            return std::make_shared<Bear>(is);
            break;
        case SquirrelType :
            return std::make_shared<Squirrel>(is);
            break;
        case OrcType :
            return std::make_shared<Orc>(is);
            break;
        default:
            std::cout << "unexpected type : " << type << std::endl;
            break;
    }
    return nullptr;
}