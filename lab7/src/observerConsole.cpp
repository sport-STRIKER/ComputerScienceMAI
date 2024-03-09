#include "../include/observerConsole.h"

void ObserverConsole::update(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender)
{
    std::lock_guard<std::shared_mutex> lck(print_mutex);
    std::cout << attacker->getType() << ' ' << attacker->getName() << " убил " << defender->getType() << ' ' << defender->getName() << std::endl;
}