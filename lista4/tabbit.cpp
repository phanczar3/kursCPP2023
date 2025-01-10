#include <stdint.h>
#include <iostream>
#include <exception>
using namespace std;
#include "tabbit.hpp"


const int tab_bit::rozmiarSlowa = 64;
istream & operator >> (istream &we, tab_bit &tb) {
    for(int i = 0; i < tb.rozmiar(); i++) {
        char x;
        we >> x;
        if(x != '0' && x != '1')
            throw invalid_argument("podany element nie jest ani 0 ani 1");
        tb.pisz(i, x-'0');
    }
    return we;
}
ostream & operator << (ostream &wy, const tab_bit &tb) {
    wy << tb.dl << "\n";
    for(int i = 0; i < tb.rozmiar(); i++) wy << tb.czytaj(i);
    return wy;
}
void swap(tab_bit &tb1, tab_bit &tb2) {
    std::swap(tb1.dl, tb2.dl);
    std::swap(tb1.tab, tb2.tab);
}
tab_bit::ref::ref(int i, tab_bit &tb) : tab2(tb) {
    idx = i;
}
tab_bit::ref::operator bool() const {
    return tab2.czytaj(idx);
}
tab_bit::ref & tab_bit::ref::operator = (bool b) {
    tab2.pisz(idx, b);
    return *this;
}
tab_bit::ref & tab_bit::ref::operator = (ref &r) {
    if(this == &r) return *this;
    bool b = r.operator bool();
    tab2.pisz(idx, b);
    return *this;
}
tab_bit::tab_bit(int rozm) {
    if(rozm < 0)
        throw invalid_argument("rozmiar tablicy nie moze byc ujemny");
    dl = rozm;
    if(rozm == 0) tab = nullptr;
    else tab = new slowo[dl/rozmiarSlowa+(dl % rozmiarSlowa != 0? 1 : 0)]{};
}
tab_bit::tab_bit(slowo tb) {
    if(tb < 0)
        throw invalid_argument("niepoprawne slowo maszynowe");
    dl = rozmiarSlowa;
    tab = new slowo[1]{tb};
}
tab_bit::tab_bit(initializer_list<bool> l) : tab_bit((int)l.size()) {
    int i = 0;
    for(bool b : l) {
        pisz(i++, b);
    }
}
tab_bit::tab_bit(const tab_bit &tb) : tab_bit(tb.dl) {
    for(int i = 0; i < dl; i++) {
        pisz(i, tb.czytaj(i));
    }
}
tab_bit::tab_bit(tab_bit &&tb) : tab_bit(0) {
    swap(*this, tb);
}
tab_bit& tab_bit::operator = (const tab_bit &tb) {
    tab_bit tmp(tb);
    swap(*this, tmp);
    return *this;
}
tab_bit& tab_bit::operator = (tab_bit &&tb) {
    swap(*this, tb);
    return *this;
}
tab_bit::~tab_bit() { 
    delete [] tab; 
}
bool tab_bit::czytaj(int i) const {
    slowo cur = tab[i/rozmiarSlowa];
    return (cur >> (i%rozmiarSlowa)) & 1;
}
bool tab_bit::pisz(int i, bool b) {
    if(b)
        tab[i/rozmiarSlowa] |= (1 << (i%rozmiarSlowa));
    else
        tab[i/rozmiarSlowa] &= ~(1 << (i%rozmiarSlowa));
    return tab;
}
void tab_bit::sprawdz(const tab_bit &tb) {
    if(this->rozmiar() != tb.rozmiar())
        throw invalid_argument("tablice sa roznej dlugosci");
}
bool tab_bit::operator [] (int i) const {
    if(i < 0 || i >= dl)
        throw invalid_argument("indeks poza zakresem");
    return czytaj(i);
}
tab_bit::ref tab_bit::operator [] (int i) {
    if(i < 0 || i >= dl)
        throw invalid_argument("indeks poza zakresem");
    ref r(i, *this);
    return r;
}
int tab_bit::rozmiar() const {
    return dl;
}
tab_bit tab_bit::operator | (const tab_bit &tb) {
    sprawdz(tb);
    tab_bit wyn(this->rozmiar());
    for(int i = 0; i < wyn.rozmiar(); i++)
        wyn.pisz(i, this->czytaj(i) | tb.czytaj(i));
    return wyn;
}
tab_bit & tab_bit::operator |= (const tab_bit &tb) {
    sprawdz(tb);
    for(int i = 0; i < this->rozmiar(); i++) 
        this->pisz(i, this->czytaj(i) | tb.czytaj(i));
    return *this;
}
tab_bit tab_bit::operator & (const tab_bit &tb) {
    sprawdz(tb);
    tab_bit wyn(this->rozmiar());
    for(int i = 0; i < wyn.rozmiar(); i++)
        wyn.pisz(i, this->czytaj(i) & tb.czytaj(i));
    return wyn;
}
tab_bit & tab_bit::operator &= (const tab_bit &tb) {
    sprawdz(tb);
    for(int i = 0; i < this->rozmiar(); i++) 
        this->pisz(i, this->czytaj(i) & tb.czytaj(i));
    return *this;
}
tab_bit tab_bit::operator ^ (const tab_bit &tb) {
    sprawdz(tb);
    tab_bit wyn(this->rozmiar());
    for(int i = 0; i < wyn.rozmiar(); i++)
        wyn.pisz(i, this->czytaj(i) ^ tb.czytaj(i));
    return wyn;
}
tab_bit & tab_bit::operator ^= (const tab_bit &tb) {
    sprawdz(tb);
    for(int i = 0; i < this->rozmiar(); i++) 
        this->pisz(i, this->czytaj(i) ^ tb.czytaj(i));
    return *this;
}
tab_bit & tab_bit::operator ! () {
    for(int i = 0; i < this->rozmiar(); i++)
        this->pisz(i, !(this->czytaj(i)));
    return *this;
}
