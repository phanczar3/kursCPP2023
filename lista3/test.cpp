#include <iostream>
#include "liczba.hpp"

using namespace std;

int main() {
    {
    liczba x;
    cout << x.pokaz() << "\n";
    x = 6;
    cout << x.pokaz() << "\n";
    x = 7;
    cout << x.pokaz() << "\n";
    x = 8;
    cout << x.pokaz() << "\n";
    x.cofnij();
    cout << x.pokaz() << "\n";
    x.cofnij();
    cout << x.pokaz() << "\n";
    x.cofnij();
    cout << x.pokaz() << "\n";
    x.cofnij();
    cout << x.pokaz() << "\n";
    }
    {
    liczba y(5);
    y = 6;
    liczba z(y);
    cout << y.pokaz() << " " << z.pokaz() << "\n";
    y.cofnij(), z.cofnij();
    cout << y.pokaz() << " " << z.pokaz() << "\n";
    }
    {
    liczba y(5);
    y = 6;
    liczba z = y;
    cout << y.pokaz() << " " << z.pokaz() << "\n";
    y.cofnij(), z.cofnij();
    cout << y.pokaz() << " " << z.pokaz() << "\n";
    }
    {
    liczba y(5);
    y = 6;
    liczba z(move(y));
    cout << z.pokaz() << "\n";
    y.cofnij(), z.cofnij();
    cout << z.pokaz() << "\n";
    }
    {
    liczba y(5);
    y = 6;
    liczba z = move(y);
    cout << z.pokaz() << "\n";
    y.cofnij(), z.cofnij();
    cout << z.pokaz() << "\n";
    }
    
    try{
        liczba x;
        x = x;
    } catch(const exception &e) {
        clog << e.what() << "\n";
    }

    return 0;
}