#include <iostream>
#include "liczba.hpp"

// [x] definicja klasy liczba, opakowania dla typu double
// [x] przywracanie wartości poprzednich pobranych z historii
// [x] max. długośc historii określona za pomocą zmiennej statycznej w klasie liczba
// [x] historia ma być przechowywana na stercie przy użyciu operatora new[]
// [x] zwalnianie pamięci przydzielonej do historii w destruktorze przy użyciu delete[]
// [x] przy przekroczeniu długości historii najstarsze wpisy mają być tracone
// [x] przywracanie historii przy tylko jednym wpisie w historii ma nic nie robić
// [x] konstruktor z zadaną wartością
// [x] konstruktor bezparametrowy i jednocześnie delegatowy (przekazana do poprzedniego konstruktora wartość to 0)
// [x] konstruktor kopiujący (pobierana jest tylko bieżąca wartość ze wzorca bez historii)
// [x] konstruktor przenoszący
// [x] Aby uzupełnić semantykę kopiowania i przenoszenia zdefiniuj opowiednie operatory przypisania (przypisanie kopiujące i przenoszące)
// [x] testy

using namespace std;
const int liczba::dh = 3;
liczba::liczba() : liczba(0) {  }
liczba::liczba(double x) { h = new double[dh], rh = 1, idx = 0, h[0] = x; }
liczba::~liczba() { if (h != nullptr) delete [] h; }
liczba::liczba(const liczba &l) : liczba(l.pokaz()) { }
liczba::liczba(liczba &&l) {
    h = l.h, l.h = nullptr, idx = l.idx, rh = l.rh;
}
liczba& liczba::operator=(liczba &l) {
    if(this == &l) 
        return *this;
    h[0] = l.pokaz(), rh = 1, idx = 0;
    /*
    *this = l.pokaz();
    */
    return *this;
}
liczba& liczba::operator=(liczba &&l) {
    // https://stackoverflow.com/questions/9322174/move-assignment-operator-and-if-this-rhs
    if(h != nullptr)
        delete [] h;
    h = l.h, l.h = nullptr, idx = l.idx, rh = l.rh;
    return *this;
}

double liczba::operator=(double &&x) { idx++, rh = min(rh+1, dh), idx = idx%dh, h[idx] = x; return x; }
double liczba::pokaz() const { return h[idx]; }
void liczba::cofnij() {
    if(rh > 1) rh--, idx = (idx-1 >= 0?idx-1:dh-1); 
}
