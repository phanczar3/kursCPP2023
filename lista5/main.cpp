#include <iostream>

using namespace std;
#include "kolor.hpp"
#include "piksel.hpp"
int main() {
    {
        kolor k1, k2(123, 123, 123);
        cout << k1 << "\n" << k2 << "\n";
        k2.setR(69);
        cout << k2 << "\n";
        kolortransparentny k3(12, 12, 12, 123);
        cout << k3;
        cout << k3.getAlfa() << "\n";
        kolornazwany k4, k5(111, 222, 123), k6(1, 2, 3, "prawieczarny");
        cout << k4 << " " << k4.getName() 
        << "\n" << k5 << " " << k5.getName() <<
        "\n" << k6 << " " << k6.getName() << "\n";
        kolornt k7, k8(1, 11, 111), k9(1, 11, 111, 100), k10(111, 11, 1, 254, "jakis");
        cout << k7 << " " << k7.getAlfa() << " " << k7.getName() << "\n";
        cout << k8 << " " << k8.getAlfa() << " " << k8.getName() << "\n";
        cout << k9 << " " << k9.getAlfa() << " " << k9.getName() << "\n";
        cout << k10 << " " << k10.getAlfa() << " " << k10.getName() << "\n";
    }
    {
        piksel p1(12, 13);
        cout << p1 << "\n";
        cout << p1.upDist() << " " << p1.downDist() << " "
        << p1.leftDist() << " " << p1.rightDist() << "\n";
        kolortransparentny k2(12, 13, 14, 245);
        try {
            pikselkolorowy p2(2000, 2000, k2);
        } catch (const out_of_range &e) {
            cerr << e.what() << "\n";
        }
        pikselkolorowy p3(1000, 1000, k2);
        cout << p3 << "\n";
        p3.moveVector(60,60);
        cout << p3 << "\n";
        try {
            p3.moveVector(200,200);
        } catch (const out_of_range &e) {
            cerr << e.what() << "\n";
        }
        piksel p4(2, 0), p5(0, 3);
        cout << odleglosc(p4, p5) << "\n";
    }

    return 0;
}