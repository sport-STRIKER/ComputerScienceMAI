#include <iostream>
#include "CheckStr.h"

using namespace std;


void Output()
{    
    cout << "Start check" << endl;
    
    string line;
    cin >> line;
        
    if (CheckStr(line))
        cout << "Ok" << endl;
    else
        cout << "Not ok" << endl;
    
    
}

int main() 
{
    Output();    

    return 0;
}
