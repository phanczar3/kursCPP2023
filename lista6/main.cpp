#include <iostream>
#include <fstream>
using namespace std;
#include "wyrazenie.hpp"
#include "operandy.hpp"
#include "operatory.hpp"
#include "operatory2.hpp"
int main() {
    
    wyrazenie *pi2 = new fi();
    cout << pi2->zapis() << " " << pi2->oblicz() << "\n";

    wyrazenie *sin2 = new sinus(new liczba(1));
    cout << sin2->zapis() << " " << sin2->oblicz() << "\n";

    wyrazenie *dod = new dodaj(new liczba(1), new liczba(2));
    wyrazenie *od = new odejmij(new liczba(2), new liczba(4));
    wyrazenie *exp1 = new dodaj(dod, od);
    wyrazenie *exp2 = new dodaj(dod, dod);
    wyrazenie *exp3 = new odejmij(dod, od);
    wyrazenie *exp4 = new odejmij(od, od);
    auto debug = [](wyrazenie *e1,wyrazenie *e2 ,wyrazenie *e3,wyrazenie *e4)
    {
        cout << e1->zapis() << " " << e1->oblicz() << "\n";
        cout << e2->zapis() << " " << e2->oblicz() << "\n";
        cout << e3->zapis() << " " << e3->oblicz() << "\n";
        cout << e4->zapis() << " " << e4->oblicz() << "\n";
    };
    debug(exp1, exp2, exp3, exp4);
    wyrazenie *mno = new mnoz(new liczba(1), new liczba(2));
    wyrazenie *dzi = new dziel(new liczba(2), new liczba(4));
    exp1 = new mnoz(mno, dzi);
    exp2 = new mnoz(dzi, mno);
    exp3 = new dziel(dzi, dzi);
    exp4 = new dziel(dzi, mno);
    debug(exp1, exp2, exp3, exp4);
    wyrazenie *mod = new modulo(new liczba(3), new liczba(2));
    exp1 = new mnoz(mno, mod);
    exp2 = new mnoz(mod, mno);
    exp3 = new modulo(mod, mod);
    exp4 = new modulo(mod, mno);
    debug(exp1, exp2, exp3, exp4);
    wyrazenie *pot = new potega(new liczba(2), new liczba(3));
    wyrazenie *lo = new logarytm(new liczba(25), new liczba(625));
    exp1 = new potega(pot, lo);
    exp2 = new logarytm(pot, lo);
    exp3 = new potega(pot, pot);
    exp4 = new potega(pot, mno);
    debug(exp1, exp2, exp3, exp4);
    
    wyrazenie *w1 = new dziel(
        new mnoz(new odejmij(new zmienna("x"), new liczba(1)), new zmienna("x")),
        new liczba(2));
    wyrazenie *w2 = new dziel(
        new dodaj(new liczba(3), new liczba(5)),
        new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7)))
    );
    wyrazenie *w3 = new odejmij(
        new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7))),
        new dodaj(new mnoz(new zmienna("y"), new liczba(3)), new liczba(5))
    );
    wyrazenie *w4 = new dziel(
        new cosinus(new mnoz(new dodaj(new zmienna("x"), new liczba(1)), new pi())),
        new potega(new e(), new potega(new zmienna("x"), new liczba(2)))
    );
    cout << w1->zapis() << "\n";
    cout << w2->zapis() << "\n";
    cout << w3->zapis() << "\n";
    cout << w4->zapis() << "\n";
    zmienna::dodaj("x", 0);
    zmienna::dodaj("y", 0);
    ofstream wyj;
    wyj.open("wyniki.txt");
    for(int i = 0; i <= 100; i++) {
        zmienna::modyfikuj("x", (double)i/100);
        for(int j = 0; j <= 100; j++) {
            zmienna::modyfikuj("y", (double)j/100);
            wyj << "x: " << (double)i/100 << " y: " << (double)j/100 << " ";
            wyj << "w1: " << w1->oblicz() << " ";
            wyj << "w2: " << w2->oblicz() << " ";
            wyj << "w3: " << w3->oblicz() << " ";
            wyj << "w4: " << w4->oblicz() << "\n";
        }
    }
    zmienna::usun("x");
    zmienna::usun("y");
    wyj.close();
    
    return 0;
}