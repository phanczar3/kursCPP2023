#include <math.h>
#include <string>
#include <exception>
using std::string;
using std::invalid_argument;
#include "wyrazenie.hpp"
#include "operatory.hpp"
op1::op1(wyrazenie *v) {
    w = v;
}
int op1::pr() {
    return 4;
}
double sinus::oblicz() {
    return sin(w->oblicz());
}
string sinus::zapis() {
    return "sin(" + w->zapis() + ")";
}
double cosinus::oblicz() {
    return cos(w->oblicz());
}
string cosinus::zapis() {
    return "cos("+w->zapis()+")";
}
double bezwzg::oblicz() {
    return abs(w->oblicz());
}
string bezwzg::zapis() {
    return "|"+w->zapis()+"|";
}
double eksponens::oblicz() {
    return exp(w->oblicz());
}
string eksponens::zapis() {
    return "exp("+w->zapis()+")";
}
double logn::oblicz() {
    double arg = w->oblicz();
    if(arg <= 0)
        throw invalid_argument("argument logn nie moze byc niedodatni");
    return log(arg);
}
string logn::zapis() {
    return "logn("+w->zapis()+")";
}
double przeciw::oblicz() {
    return -w->oblicz();
}
string przeciw::zapis() {
    if(w->pr() > 1) return "-"+w->zapis();
    else return "-("+w->zapis()+")";
}
double odwrot::oblicz() {
    double arg = w->oblicz();
    if(arg == 0)
        throw invalid_argument("dzielenie prze 0");
    return 1/arg; 
}
string odwrot::zapis() {
    if(w->pr() > 2) return "1/"+w->zapis();
    else return "1/("+w->zapis()+")";
}
