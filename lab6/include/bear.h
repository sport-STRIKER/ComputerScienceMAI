#pragma once

#include "npc.h"
#include "squirrel.h"
#include "orc.h"

class Bear : public NPC 
{
    public:
        Bear(std::string name, int x, int y);
        Bear(std::istream& is);
        virtual ~Bear() = default;

        bool accept(NPC &visitor) override;
        bool visit(Squirrel &monster) override;
};
