#pragma once

#include "npc.h"
#include "bear.h"
#include "squirrel.h"
#include "orc.h"

std::shared_ptr<NPC> factory(std::istream &is);
std::shared_ptr<NPC> factory(NpcType type, std::string name, int x, int y);