#include "../include/fight.h"

std::set<std::shared_ptr<NPC>> fight(const std::set<std::shared_ptr<NPC>> &array, size_t distance)
{
    std::set<std::shared_ptr<NPC>> dead_list;

    for (auto &attacker : array)
        for (auto &defender : array)
            if ((attacker != defender) && (attacker->distance(*defender) <= distance))
            {
                bool success{false};
                success = defender->accept(*attacker);
                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}