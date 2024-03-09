#pragma once

#include "npc.h"
#include "bear.h"
#include "orc.h"

class Squirrel : public NPC
{
    public:
        Squirrel(std::string name, int x, int y);
        Squirrel(std::istream& is);
        virtual ~Squirrel() = default;

        int getDistMove() override;
        int getDistFight() override;

        bool accept(std::shared_ptr<NPC> visitor) override;

    protected:
        int dist_move = 50;
        int dist_fight = 10;
};
