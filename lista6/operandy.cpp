#include "operandy.hpp"
#include <iostream>
#include <exception>
#include <string>
#include <math.h>
#include <vector>
#include <utility>
#include <cmath>
using std::string;
using std::to_string;
using std::invalid_argument;
using std::vector;
using std::pair;
using std::modf;

liczba::liczba() : liczba(0) {}
liczba::liczba(double v) {
    val = v;
}
double liczba::oblicz() {
    return val;
}
string liczba::zapis() {
    if(trunc(val) == val)
        return to_string((int)val);
    else
        return to_string(val);
}
int liczba::pr() {
    return 4;
}
vector<pair<string,double>> zmienna::dic = {};
bool zmienna::jest(string s) {
    bool res = false;
    for(int i = 0; i < dic.size(); i++)
        if(dic[i].first == s)
            res = true;
    return res;
}
int zmienna::znajdz(string s) {
    int idx = -1;
    for(int i = 0; i < dic.size(); i++) {
        if(dic[i].first == s) idx = i;
    }
    return idx;
}
void zmienna::dodaj(string s, double val) {
    if(jest(s))
        throw invalid_argument("zmienna jest juz obecna");
    dic.push_back({s, val});
}
void zmienna::modyfikuj(string s, double val) {
    if(!jest(s))
        throw invalid_argument("zmienna nie jest obecna");
    int idx = znajdz(s);
    dic[idx].second = val;
}
void zmienna::usun(string s) {
    if(!jest(s))
        throw invalid_argument("zmienna nie jest obecna");
    int idx = znajdz(s);
    dic.erase(dic.begin()+idx);
}
zmienna::zmienna(string s) {
    nam = s;
}
double zmienna::oblicz() {
    if(!jest(nam))
        throw invalid_argument("zmienna nie ma zdefiniowanej wartosc");
    int idx = znajdz(nam);
    return dic[idx].second;
}
string zmienna::zapis() {
    return nam;
}
int zmienna::pr() {
    return 4;
}
stala::stala(string s, double v) {
    nam = s;
    val = v;
}
double stala::oblicz() {
    return val;
}
string stala::zapis() {
    return nam;
}
int stala::pr() {
    return 4;
}
pi::pi() : stala("pi", acos(-1)) {}
e::e() : stala("e", exp(1)) {}
fi::fi() : stala("fi", (1+sqrt(5))/2) {}