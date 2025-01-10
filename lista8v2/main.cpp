#include "obliczenia.hpp"
#include <iostream>
#include <limits.h>

using std::cout;
using obliczenia::wymierna;
using obliczenia::dzielenie_przez_0;
using obliczenia::przekroczenie_zakresu;
int main() {
    auto debug = [](wymierna w) {
        cout << w.pl() << " " << w.pm() << "\n";
    };
    auto sep = []() {
        cout << "------------------------\n";
    };

    wymierna w[4];
    w[0] = wymierna(1, 2);
    w[1] = wymierna(-1, 2);
    w[2] = wymierna(1, -2);
    w[3] = wymierna(4, -2);

    for(auto x : w) debug(x);
    sep();

    wymierna w2[4];
    w2[0] = w[0] + w[3];
    w2[1] = wymierna(INT_MAX) + wymierna(1, -1);
    w2[2] = w[0] + w[2];
    w2[3] = wymierna(INT_MAX) + wymierna(INT_MIN);
    for(auto x : w2) debug(x);
    sep();

    wymierna w3[4];
    w3[0] = w[0] * w[3];
    w3[1] = wymierna(5, 2) * wymierna(3, 2);
    w3[2] = wymierna(3, 2) / wymierna(3, 2);
    w3[3] = wymierna(32, 24) / wymierna(-6, 5);
    for(auto x : w3) debug(x);
    sep();

    for(auto x : w3) cout << double(x) << " " << int(x) << "\n";
    sep();

    wymierna w4[4];
    w4[0] = wymierna(-2359348, 99900);
    w4[1] = wymierna(1234, 425);
    w4[2] = wymierna(100, 400);
    w4[3] = wymierna(100000000, 189871);
    for(int i = 0; i < 4; i++) cout << w4[i] << "\n";
    sep();
    
    try{
        wymierna p = wymierna(INT_MAX, 0);
    } catch(const dzielenie_przez_0 &e) {
        cout << e.what() << "\n";
    }
    try{
        wymierna p = wymierna(INT_MAX, 1) + wymierna(INT_MAX, 1);
    } catch(const przekroczenie_zakresu &e) {
        cout << e.what() << "\n";
    }
    try{
        wymierna p = wymierna(INT_MAX, 1) * wymierna(INT_MAX, 1);
    } catch(const przekroczenie_zakresu &e) {
        cout << e.what() << "\n";
    }
    try{
        wymierna p = wymierna(INT_MAX, 1) / wymierna(1, INT_MAX);
    } catch(const przekroczenie_zakresu &e) {
        cout << e.what() << "\n";
    }
    try{
        wymierna p = wymierna(1, 1) / wymierna();
    } catch(const dzielenie_przez_0 &e) {
        cout << e.what() << "\n";
    }
    try{
        wymierna p = !wymierna();
    } catch(const dzielenie_przez_0 &e) {
        cout << e.what() << "\n";
    }

    wymierna q1 = 5 + wymierna(2, 1);
    cout << q1 << "\n";
    wymierna q2 = wymierna(2,1) + 5;
    cout << q2 << "\n";
    wymierna q3 = 5 + wymierna(2,3);
    cout << q3 << "\n";
    return 0; 
}