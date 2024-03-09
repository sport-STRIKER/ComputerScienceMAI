#pragma once

#include "observer.h"

class ObserverFile : public Observer
{
    public :
        void update(NPC &attacker, NPC &defender) override;
};
