#include "CheckStr.h"

bool CheckStr(std::string line)
{
    int level = 0;
    for (int i = 0; i < line.length(); ++i)
    {
        if (line[i] == '(')
            ++level;
        else if (line[i] == ')')
            --level;
        else
            return false;
    }
    
    if (level != 0)
        return false;

    return true;
}
