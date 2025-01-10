#include <math.h>
#include <cmath>
#include <string>
#include <exception>
using std::string;
using std::invalid_argument;
using std::pow;
#include "operatory2.hpp"
op2::op2(wyrazenie *v, wyrazenie *v2) : op1(v) {
    w2 = v2;
}
string bracket(string s) {
    return "(" + s + ")";
}
double dodaj::oblicz() {
    return w->oblicz()+w2->oblicz();
}
string dodaj::zapis() {
    string s = w->zapis(), s2 = w2->zapis();
    return s + "+" + s2;
}
int dodaj::pr() {
    return 1;
}
double odejmij::oblicz() {
    return w->oblicz()-w2->oblicz();
}
string odejmij::zapis() {
    bool rb = false;
    //dynamic_cast<dodaj*>(w2) != nullptr || dynamic_cast<odejmij*>(w2) != nullptr
    if(w2->pr() == 1) rb = true;
    string s = w->zapis(), s2 = w2->zapis();
    if(rb) s2 = bracket(s2);
    return s + "-" + s2;
}
int odejmij::pr() {
    return 1;
}
double mnoz::oblicz() {
    return w->oblicz()*w2->oblicz();
}
string mnoz::zapis() {
    bool lb = false, rb = false;
    if(w->pr() == 1) lb = true;
    if(w2->pr() == 1) rb = true;
    string s = w->zapis(), s2 = w2->zapis();
    if(lb) s = bracket(s);
    if(rb) s2 = bracket(s2);
    return s+"*"+s2;
}
int mnoz::pr() {
    return 2;
}
double dziel::oblicz() {
    double v = w->oblicz(), v2 = w2->oblicz();
    if(v2 == 0)
        throw invalid_argument("dzielenie przez 0");
    return v / v2;
}
string dziel::zapis() {
    bool lb = false, rb = false;
    if(w->pr() == 1) lb = true;
    if(w2->pr() <= 2) rb = true;
    string s = w->zapis(), s2 = w2->zapis();
    if(lb) s = bracket(s);
    if(rb) s2 = bracket(s2);
    return s+"/"+s2;
}
int dziel::pr() {
    return 2;
}
double modulo::oblicz() {
    double arg1 = w->oblicz(), arg2 = w2->oblicz();
    if(arg2 == 0)
        throw invalid_argument("dzielenie przez 0");
    return fmod(arg1, arg2);
}
string modulo::zapis() {
    bool lb = false, rb = false;
    if(w->pr() == 1) lb = true;
    if(w2->pr() == 1 || w2->pr() == 2) rb = true;
    string s = w->zapis(), s2 = w2->zapis();
    if(lb) s = bracket(s);
    if(rb) s2 = bracket(s2);
    return s+"%"+s2;
}
int modulo::pr() {
    return 2;
}
double potega::oblicz() {
    return pow(w->oblicz(), w2->oblicz());
}
string potega::zapis() {
    bool lb = false, rb = false;
    if(w->pr() <= 2) lb = true;
    if(w2->pr() <= 2) rb = true;
    if(dynamic_cast<potega*>(w) != nullptr) lb = true;
    string s = w->zapis(), s2 = w2->zapis();
    if(lb) s = bracket(s);
    if(rb) s2 = bracket(s2);
    return s+"^"+s2;
}
int potega::pr() {
    return 3;
}
double logarytm::oblicz() {
    double arg1 = w->oblicz(), arg2 = w2->oblicz();
    if(arg1 == 1)
        throw invalid_argument("podstawa logarytmu nie moze byc rowna 1");
    if(arg1 <= 0)
        throw invalid_argument("podstawa logarytmu musi byc dodatnia");
    if(arg2 <= 0)
        throw invalid_argument("liczba logarytmowana musi byc dodatnia");
    return log(arg2)/log(arg1);
}
string logarytm::zapis() {
    return "log_"+w->zapis()+"_("+w2->zapis()+")";
}
int logarytm::pr() {
    return 3;
}

