#ifndef SQUIRREL_H
#define SQUIRREL_H

#include "npc.h"
#include "bear.h"
#include "orc.h"

class Squirrel : public NPC
{
    public:
        Squirrel(std::string name, int x, int y);
        Squirrel(std::istream& is);
        virtual ~Squirrel() = default;

        bool accept(NPC &visitor) override;
};

#endif