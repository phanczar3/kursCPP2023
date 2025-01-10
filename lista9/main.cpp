#include "calc.hpp"
#include <iostream>
int main() {
    using calc::list;
    {
    list<int> l1;
    l1.insert(0, 5);
    std::cout << l1 << "\n";
    l1.insert(1, 2);
    std::cout << l1 << "\n";
    l1.push_front(4);
    std::cout << l1 << "\n";
    l1.insert(1, 6);
    std::cout << l1 << "\n";
    l1.push_back(7);
    std::cout << l1 << "\n";
    l1.erase(0);
    std::cout << l1 << "\n";
    l1.erase(3);
    std::cout << l1 << "\n";
    l1.erase(1);
    std::cout << l1 << "\n";
    l1.erase(0);
    std::cout << l1 << "\n";
    l1.erase(0);
    std::cout << l1 << "\n";
    l1.insert(0, 1);
    std::cout << l1 << "\n";
    }
    {
    list<int> l2{0, 1, 2, 3, 4};
    list<int> l3{1, 0};
    std::cout << issorted(l2) << "\n";
    std::cout << issorted(l3) << "\n";
    }
    // {
    // list<int> l{1, 2, 3};
    // list<int> l2 = l;
    // std::cout << l << "\n";
    // std::cout << l2 << "\n";
    // l2.erase_val(1);
    // std::cout << l << "\n";
    // std::cout << l2 << "\n";
    // }
    {
    const char* a = "aaa";
    const char* b = "bbb";
    const char* c = "ccc";
    list<const char*> l1{a, b, c};
    list<const char*> l2{b, a, c};
    std::cout << issorted(l1) << "\n";
    std::cout << issorted(l2) << "\n";
    }
    {
    list<int> l2{0, 3, 5, -2, 4};
    std::cout << l2 << "\n";
    sort(l2);
    std::cout << l2 << "\n";
    }
    return 0;
}