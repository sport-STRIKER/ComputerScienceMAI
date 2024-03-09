#include "../include/observerConsole.h"

void ObserverConsole::update(NPC &attacker, NPC &defender)
{
    std::cout << attacker.getType() << ' ' << attacker.getName() << " убил " << defender.getType() << ' ' << defender.getName() << std::endl;
}