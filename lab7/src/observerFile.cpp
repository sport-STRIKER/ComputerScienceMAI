#include "../include/observerFile.h"

void ObserverFile::update(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender)
{
    std::ofstream file(fileOutput, std::ios_base::app);
    file << std::endl << attacker->getType() << ' ' << attacker->getName() << " убил " << defender->getType() << ' ' << defender->getName() << std::endl;
    file.close();
}
