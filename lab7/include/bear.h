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

        int getDistMove() override;
        int getDistFight() override;

        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Squirrel> monster) override;

    protected:
        int dist_move = 5;
        int dist_fight = 5;
};