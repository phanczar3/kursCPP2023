#include <iostream>
using namespace std;
#include "kolor.hpp"

ostream & operator << (ostream &wy, const kolor &k) {
    wy << k.r << " " << k.g << " " << k.b;
    return wy;
}
void kolor::isValid(int x) {
    if( x < 0 || x > 255)
        throw invalid_argument("liczba spoza zakresu 0-255");
}
kolor::kolor() : kolor(0, 0, 0) { }
kolor::kolor(int x, int y, int z) {
    isValid(min({x, y, z}));
    isValid(max({x, y, z}));
    r = x;
    g = y;
    b = z;
}
int kolor::getR() const {
    return r;
}
int kolor::getG() const {
    return g;
}
int kolor::getB() const {
    return b;
}
void kolor::setR(int x) {
    isValid(x);
    r = x;
}
void kolor::setG(int x) {
    isValid(x);
    g = x;
}
void kolor::setB(int x) {
    isValid(x);
    b = x;
}
kolortransparentny::kolortransparentny() : kolortransparentny(0, 0, 0, 255) {}
kolortransparentny::kolortransparentny(int x, int y, int z) : kolortransparentny(x, y, z, 255) {}
kolortransparentny::kolortransparentny(int x, int y, int z, int a) : kolor(x, y, z) {
    isValid(a);
    alfa = a;
}
int kolortransparentny::getAlfa() const {
    return alfa;
}
void kolortransparentny::setAlfa(int x) {
    isValid(x);
    alfa = x;
}
void kolornazwany::rightName(string s) {
    for(char x : s)
        if(x < 'a' || x > 'z')
            throw invalid_argument("niepoprawna nazwa");
}
kolornazwany::kolornazwany() : kolornazwany(0, 0, 0, "") { }
kolornazwany::kolornazwany(int x, int y, int z) : kolornazwany(x, y, z, "") { }
kolornazwany::kolornazwany(int x, int y, int z, string s) : kolor(x, y, z) {
    rightName(s);
    name = s;
}
string kolornazwany::getName() const {
    return name;
}
void kolornazwany::setName(string s) {
    name = s;
}
kolornt::kolornt() : kolornt(0, 0, 0, 255, "") {}
kolornt::kolornt(int x, int y, int z) : kolornt(x, y, z, 255, "") {}
kolornt::kolornt(int x, int y, int z, int a) : kolornt(x, y, z, a, "") {}
kolornt::kolornt(int x, int y, int z, int a, string s) 
: kolor(x, y, z) {
    rightName(s);
    name = s;
    isValid(a);
    alfa = a;
}
