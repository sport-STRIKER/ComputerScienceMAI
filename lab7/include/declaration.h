#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <set>
#include <memory>
#include <mutex>
#include <sstream>
#include <thread>
#include <shared_mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

#define fileOutput "log.txt"
#define STOP 7

using namespace std::chrono_literals;

extern std::shared_mutex print_mutex;

enum NpcType 
{
    Unknown = 0,
    BearType = 1, // медведь
    SquirrelType = 2, // выпь
    OrcType = 3 // выхухоль
};

class Observer;

class ObserverConsole;
class ObserverFile;


class NPC;

class Bear;
class Squirrel;
class Orc;