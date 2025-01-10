#include <stdint.h>
#include <iostream>
#include <exception>
using namespace std;
#include "tabbit.hpp"


int main() {
    {
        tab_bit b(45ull), c(23);
        cout << b << "\n" << c << "\n";
    }
    {
        tab_bit c{0, 0, 1, 1, 0, 1, 0, 0};
        tab_bit d(c);
        cout << c << "\n" << d << "\n";
    }
    {
        tab_bit c{0, 0, 1, 1, 0, 1, 0, 0};
        tab_bit d = c;
        cout << c << "\n" << d << "\n";
    }
    {
        tab_bit c{0, 0, 1, 1, 0, 1, 0, 0};
        tab_bit d(move(c));
        cout << c << "\n" << d << "\n";
    }
    {
        tab_bit c{0, 0, 1, 1, 0, 1, 0, 0};
        tab_bit d = move(c);
        cout << c << "\n" << d << "\n";
    }
    {
        tab_bit const c{0, 0, 1, 1};
        cout << c[1] << " " << c[2] << "\n";
    }
    {
        tab_bit a{0, 0, 1, 1}, b{0, 1, 1, 1}, c{0, 0, 0, 0};
        cout << a << "\n" << b << "\n" << c << "\n";
        a[3] = b[3] = c[3];
        cout << a << "\n" << b << "\n" << c << "\n";
        a[3] = b[3] = c[3] = 1;
        cout << a << "\n" << b << "\n" << c << "\n";
        bool d = b[2];
        cout << d << "\n";    
    }
    {
        tab_bit a(5);
        cin >> a;
        cout << a << "\n";
    }
    {
        tab_bit a{1, 1, 0, 0};
        tab_bit b{1, 0, 0, 1};
        cout << (a | b) << "\n";
    }
    {
        tab_bit a{1, 1, 0, 0};
        tab_bit b{1, 0, 0, 1};
        a |= b;
        cout << a << "\n";
    }
    {
        tab_bit a{1, 1, 0, 0};
        tab_bit b{1, 0, 0, 1};
        cout << (a & b) << "\n";
    }
    {
        tab_bit a{1, 1, 0, 0};
        tab_bit b{1, 0, 0, 1};
        a &= b;
        cout << a << "\n";
    }
    {
        tab_bit a{1, 1, 0, 0};
        tab_bit b{1, 0, 0, 1};
        cout << (a ^ b) << "\n";
    }
    {
        tab_bit a{1, 1, 0, 0};
        tab_bit b{1, 0, 0, 1};
        a ^= b;
        cout << a << "\n";
    }
    {
        tab_bit a{1, 1, 0, 0};
        cout << !a << "\n";
    }
    return 0;
}