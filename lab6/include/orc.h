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

        bool accept(NPC &visitor) override;
        bool visit(Bear &monster) override;
        bool visit(Orc &monster) override;
};

#endif