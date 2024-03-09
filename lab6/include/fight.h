#pragma once

#include "declaration.h"
#include "npc.h"


std::set<std::shared_ptr<NPC>> fight(const std::set<std::shared_ptr<NPC>> &array, size_t distance);