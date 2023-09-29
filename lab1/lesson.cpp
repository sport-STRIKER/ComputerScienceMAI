#include <iostream>
using namespace std;

bool CheckStr(string s)
{
    int level = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
            ++level;
        else if (s[i] == ')')
            --level;
        else
            return false;
    }
    
    if (level != 0)
        return false;

    return true;
}

void Output()
{
    string s;
    cin >> s;

    cout << "Check is over\n";
    
    if (CheckStr(s))
        cout << "Ok" << endl;
    else
        cout << "Not ok" << endl;
}

int main() 
{
    Output();    

    return 0;
}
