#include "obliczenia.hpp"
#include <math.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <map>

typedef long long ll;
using obliczenia::wymierna;
using obliczenia::wyjatek_wymierny;
using obliczenia::dzielenie_przez_0;
using obliczenia::przekroczenie_zakresu;
using std::cout;
using std::ostream;
using std::min;
using std::logic_error;
ll mygcd(int a, int b) {
    return (b == 0? a : mygcd(b, a%b));
}
bool myzakresy(long long a) {
    return (ll)INT_MIN <= a && a <= (ll)INT_MAX;
}
wymierna obliczenia::operator+(const wymierna &w, const wymierna &w2) noexcept(false) {
    ll mian = (ll)w2.pm()*w.pm();
    ll g = mygcd(w2.pm(), w.pm());
    mian /= g;
    ll licz = (ll)w2.pl()*(mian/w2.pm()) + (ll)w.pl()*(mian/w.pm());
    if(!myzakresy(licz) || !myzakresy(mian))
        throw przekroczenie_zakresu("wynik dodawania nie moze zostac zapisany w postaci int/int");
    return wymierna(licz, mian);
}
int wymierna::gcd(int a, int b) noexcept(true) {
    return (b == 0? a : gcd(b, a%b));
}
void wymierna::skroc(int &a, int &b) noexcept(true) {
    bool min = (a < 0 && b > 0) || (a > 0 && b < 0);
    a = abs(a), b = abs(b);
    int g = gcd(a, b);
    a /= g, b /= g;
    if(min) a = -a;
}
bool wymierna::zakresy(long long a) const noexcept(true) {
    return (ll)INT_MIN <= a && a <= (ll)INT_MAX;
}
wymierna::wymierna(int a, int b) {
    if(b == 0)
        throw dzielenie_przez_0("mianownik nie moze byc zerowy");
    skroc(a, b);
    licz = a;
    mian = b;
}
wymierna::wymierna(int a) noexcept(true) : wymierna(a, 1) {}
wymierna::wymierna() noexcept(true) : wymierna(0, 1) {}
int wymierna::pl() const noexcept(true) {
    return licz;
}
int wymierna::pm() const noexcept(true) {
    return mian;
}
/*wymierna wymierna::operator+(const wymierna &w) noexcept(false) {
    ll mian = (ll)this->mian*w.pm();
    ll g = gcd(this->mian, w.pm());
    mian /= g;
    ll licz = (ll)this->licz*(mian/this->mian) + (ll)w.pl()*(mian/w.pm());
    if(!zakresy(licz) || !zakresy(mian))
        throw przekroczenie_zakresu("wynik dodawania nie moze zostac zapisany w postaci int/int");
    return wymierna(licz, mian);
}*/
wymierna wymierna::operator-(const wymierna &w) noexcept(false) {
    wymierna wyn;
    try{
        wyn = *this + (-w);
    } catch(const przekroczenie_zakresu &e) {
        throw przekroczenie_zakresu("wynik odejmowania nie moze zostac zapisany w postaci int/int");
    }
    return wyn;
}
wymierna wymierna::operator*(const wymierna &w) noexcept(false) {
    ll licz = (ll)this->licz*w.pl();
    ll mian = (ll)this->mian*w.pm();
    if(!zakresy(licz) || !zakresy(mian))
        throw przekroczenie_zakresu("wynik mnozenia nie moze zostac zapisany w postaci int/int");
    return wymierna(licz, mian);
}
wymierna wymierna::operator/(const wymierna &w) noexcept(false) {
    wymierna wyn;
    try{
        wyn = *this * (!w);
    } catch(const dzielenie_przez_0 &e) {
        throw dzielenie_przez_0("dzielnik nie moze byc rowny 0");
    } catch(const przekroczenie_zakresu &e) {
        throw przekroczenie_zakresu("wynik dzielenia nie moze zostac zapisany w postaci int/int");
    }
    return wyn;
}
wymierna wymierna::operator-() const noexcept(false) {
    ll x = -(ll)this->licz;
    if(!zakresy(x))
        throw przekroczenie_zakresu("ulamek przeciwny do podanego nie moze zostac zapisany w postaci int/int");
    return wymierna(-this->licz, this->mian);
}
wymierna wymierna::operator!() const noexcept(false) {
    wymierna wyn;
    try{
        wyn = wymierna(this->mian, this->licz);
    } catch(const dzielenie_przez_0 &e) {
        throw dzielenie_przez_0("nie mozna odwrocic ulamka rownego 0");
    }
    return wyn;
}
wymierna::operator double() const noexcept(true) {
    double wyn = (double) this->licz / this->mian;
    return wyn;
}
wymierna::operator int() const noexcept(true) {
    int wyn = (int) this->licz / this-> mian;
    if(abs((double)wyn - double(*this)) <= 0.5)
        return wyn;
    return wyn + (double(*this) < 0? -1 : 1);
}
ostream& obliczenia::operator<< (ostream &wyj, const wymierna &w) noexcept(true) {
    int m = w.pm(), cnt2 = 0, cnt5 = 0;
    while(m % 2 == 0) m /= 2, cnt2++;
    while(m % 5 == 0) m /= 5, cnt5++;
    if(m == 1) wyj << double(w);
    else {
        using std::string;
        using std::to_string;
        using std::map;
        int calk = abs(w.pl()) / w.pm();
        string wyn = to_string(calk);
        wyn += ".";
        ll res = (ll)abs(w.pl()) - (ll)calk * w.pm();
        map<ll,int> mp;
        for(int i = wyn.size(); ; i++) {
            if(mp[res] != 0) 
                break;
            mp[res] = i;
            res *= 10;
            ll divv = res / w.pm();
            res -= divv*w.pm();
            wyn += to_string(divv);
        }
        wyn = wyn.substr(0, mp[res]) + "(" + wyn.substr(mp[res]) + ")";
        if(w.pl() < 0)
            wyn = "-" + wyn;
        wyj << wyn;
    }
    return wyj;
}
wyjatek_wymierny::wyjatek_wymierny(const string& what_arg) noexcept(false) : logic_error(what_arg) {}

dzielenie_przez_0::dzielenie_przez_0(const string& what_arg) noexcept(false) : wyjatek_wymierny(what_arg) {}
przekroczenie_zakresu::przekroczenie_zakresu(const string& what_arg) noexcept(false) : wyjatek_wymierny(what_arg) {}

