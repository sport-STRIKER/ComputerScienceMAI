#include <iostream>
#include "octal.h"


int main(){

    try {
        Octal o1 {'5', '7', '3'};
        Octal o2 {'5', '1', '6'};
        Octal o3 {'5', '5'};

        o1.remove(o2);
        std::string s;
        o1.convertToString(s);

        if (!o1.equals(o3))
            std::cout << "NE RAVNO\n";

        std::cout << s << std::endl;
        std::cout << o1.size() << std::endl;

        Octal o4("124");

        Octal o5(4, '2');
    } catch(std::exception &ex){
        std::cerr << "exception: " << ex.what() << std::endl;
    }

    return 1;
}
