#pragma once

#include "observer.h"

class ObserverConsole : public Observer
{
    public :
        void update(NPC &attacker, NPC &defender) override;
};
