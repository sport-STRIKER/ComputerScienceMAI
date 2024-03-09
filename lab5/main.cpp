#include <iostream>

#include "include/allocator.h"
#include "include/iterator.h"
#include "include/list.h"

#include <map>
#include <vector>

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int main() {
    // std::map<int, int, std::less<int>, Allocator<std::pair<const int,int>>> map1;
    // for (int i = 0; i < 10; ++i) {
    //     map1[i] = factorial(i);
    // }

    // for(auto& elem: map1) {
    //     std::cout << elem.first << " " << elem.second << std::endl;
    // }

    // std::map<int, int, std::less<int>, Allocator<std::pair<const int,int>>> map2;
    // for (int i = 0; i < 1e4; ++i) {
    //     map2[i] = i;
    // }

    // for(auto& elem: map2) {
    //     std::cout << elem.first << " " << elem.second << std::endl;
    // }

    // List<int, Allocator<Node<int>>> list;
    
    // list.push_back(10);
    // list.push_back(20);
    // list.push_back(30);
    // for (auto it = list.begin(); it != list.end(); ++it) {
    //     std::cout << *it << ' ';
    // }
    // std::cout << std::endl;

    // List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    // auto it = list.end();
    // --it;
    // auto it2 = list.begin();
    // it2++;

    // std::cout << *(--it) << *(it--);

    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    list.pop_back();

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}
