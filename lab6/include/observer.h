#pragma once

#include "declaration.h"
#include "npc.h"

class Observer
{
    public :
        virtual void update(NPC &attacker, NPC &defender) = 0;
};
