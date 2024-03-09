#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <set>
#include <memory>

#define fileOutput "log.txt"


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
