#ifndef ORC_H
#define ORC_H

#include "npc.h"
#include "bear.h"
#include "squirrel.h"

class Orc : public NPC
{
    public:
        Orc(std::string name, int x, int y);
        Orc(std::istream& is);
        virtual ~Orc() = default;

        int getDistMove() override;
        int getDistFight() override;

        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Bear> monster) override;
        bool visit(std::shared_ptr<Orc> monster) override;  

    protected:
        int dist_move = 5;
        int dist_fight = 20;
};

#endif