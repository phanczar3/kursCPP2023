#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
#include "figury.hpp"


using namespace std;
const double pi = 3.1415926535897932386426433832795; 
const double eps = 1e-6;
wektor::wektor() { x = y = 0; }
wektor::wektor(double a, double b) { x = a, y = b; }
double wektor::wspx() const { return x; }
double wektor::wspy() const { return y; }
punkt::punkt() { x = y = 0; }
punkt::punkt(double a, double b) { x = a, y = b; }
punkt::punkt(const punkt& p) { x = p.wspx(), y = p.wspy(); }
punkt& punkt::operator=(const punkt &p) {
    if( &p != this) {
        x = p.wspx();
        y = p.wspy();
    }
    return *this;
}
double punkt::wspx() const { return x; }
double punkt::wspy() const { return y; }
void punkt::pokaz() const {cout << "(" << x << "," << y << ")\n"; }
void punkt::przesun(const wektor v) {
    x += v.wspx(), y += v.wspy();
} 
void punkt::obroc(const punkt p, const double alfa) {
    x -= p.wspx(), y -= p.wspy();
    double newx = x*cos(alfa)-y*sin(alfa);
    double newy = x*sin(alfa)+y*cos(alfa);
    newx += p.wspx(), newy += p.wspy();
    x = newx, y = newy;
}
void punkt::symetriawzgp(const punkt p) {
    x -= p.wspx(), y -= p.wspy();
    x = -x, y = -y;
    x += p.wspx(), y += p.wspy();
}
void punkt::symetriawzgox() { y = -y; }
void punkt::symetriawzgoy() { x = -x; }
double odleglosc(const punkt p1, const punkt p2) {
    return sqrt( (p1.wspx()-p2.wspx())*(p1.wspx()-p2.wspx()) + 
    (p1.wspy()-p2.wspy())*(p1.wspy()-p2.wspy()));
}
double det(const punkt p1, const punkt p2, const punkt p3) {
    return p1.wspx()*p2.wspy()+p1.wspy()*p3.wspx()+p2.wspx()*p3.wspy()
    -p3.wspx()*p2.wspy()-p3.wspy()*p1.wspx()-p2.wspx()*p1.wspy();
}
bool wspoliniowosc(const punkt p1, const punkt p2, const punkt p3) {
    double val = det(p1, p2, p3);
    return abs(val) < eps;
}
odcinek::odcinek() { 
    punkt x, y(1, 0);
    p1 = x, p2 = y;
}
odcinek::odcinek(const punkt a, const punkt b) {
    if(a.wspx() == b.wspx() && a.wspy() == b.wspy()) {
        throw invalid_argument("punkt nie jest odcinkiem");
    }
    p1 = a;
    p2 = b;
}
odcinek::odcinek(const odcinek &o) { p1 = o.p1, p2 = o.p2; }
odcinek& odcinek::operator=(const odcinek &o) {
    if( &o != this) {
        p1 = o.pkt1();
        p2 = o.pkt2();
    }
    return *this;
}
punkt odcinek::pkt1() const { return p1; }
punkt odcinek::pkt2() const { return p2; }
void odcinek::pokaz() const { 
   cout << "(" << p1.wspx() << "," << p1.wspy() << ")-(" << p2.wspx() << "," << p2.wspy() << ")\n";
}
void odcinek::przesun(const wektor v) {
    p1.przesun(v);
    p2.przesun(v);
} 
void odcinek::obroc(const punkt p, const double alfa) {
    p1.obroc(p, alfa), p2.obroc(p, alfa);
}
void odcinek::symetriawzgp(const punkt p) {
    p1.symetriawzgp(p), p2.symetriawzgp(p);
}
void odcinek::symetriawzgox() {
    p1.symetriawzgox(), p2.symetriawzgox();
}
void odcinek::symetriawzgoy() {
    p1.symetriawzgoy(), p2.symetriawzgoy();
}
double odcinek::dlugosc() const {
    return odleglosc(p1, p2);
}
bool odcinek::czylezy(const punkt p) const {
    if(wspoliniowosc(p1, p, p2) &&
    min(p1.wspx(), p2.wspx()) <= p.wspx() &&
    p.wspx() <= max(p1.wspx(), p2.wspx()) &&
    min(p1.wspy(), p2.wspy()) <= p.wspy() &&
    p.wspy() <= max(p1.wspy(), p2.wspy())) return true;
    else return false;
}
bool czyrownolegle(const odcinek o1, const odcinek o2) {
    double x = o1.pkt1().wspx() - o2.pkt1().wspx();
    double y = o1.pkt1().wspy() - o2.pkt1().wspy();
    wektor w(x, y);
    odcinek o3(o2);
    o3.przesun(w);
    if(wspoliniowosc(o1.pkt1(), o1.pkt2(), o3.pkt2())) return true;
    return false;

}
bool czyprostopadle(const odcinek o1, const odcinek o2) {
    odcinek o3(o2);
    o3.obroc(o3.pkt1(), pi/2);
    if(czyrownolegle(o1, o3)) return true;
    return false;
}
bool czyprzeciecie(const odcinek o1, const odcinek o2) {
    if(o1.czylezy(o2.pkt1()) || o1.czylezy(o2.pkt2()) ||
    o2.czylezy(o1.pkt1()) || o2.czylezy(o1.pkt1())) return true;
    double det1 = det(o1.pkt1(), o1.pkt2(), o2.pkt1()),
    det2 = det(o1.pkt1(), o1.pkt2(), o2.pkt2()),
    det3 = det(o2.pkt1(), o2.pkt2(), o1.pkt1()),
    det4 = det(o2.pkt1(), o2.pkt2(), o1.pkt2());
    if(det1*det2 < 0 && det3*det4 < 0) return true;
    return false;
}

trojkat::trojkat() {
    punkt x, y(1,0), z(0,1);
    p1 = x, p2 = y, p3 = z;
}
trojkat::trojkat(const punkt a, const punkt b, const punkt c) {
    if(wspoliniowosc(a, b, c)) {
        throw invalid_argument("podane punkty sa wspoliniowe");
    }
    p1 = a, p2 = b, p3 = c;
}
trojkat::trojkat(const trojkat &t) {
    p1 = t.p1, p2 = t.p2, p3 = t.p3;
}
void trojkat::pokaz() const {
    cout << "(" << p1.wspx() << "," << p1.wspy() << "),"; 
    cout << "(" << p2.wspx() << "," << p2.wspy() << "),"; 
    cout << "(" << p3.wspx() << "," << p3.wspy() << ")\n"; 
}
trojkat& trojkat::operator=(const trojkat &t) {
    if( &t != this) {
        p1 = t.p1;
        p2 = t.p2;
        p3 = t.p3;
    }
    return *this;
}
punkt trojkat::pkt1() const { return p1; }
punkt trojkat::pkt2() const { return p2; }
punkt trojkat::pkt3() const { return p3; }
void trojkat::przesun(const wektor v) {
    p1.przesun(v), p2.przesun(v), p3.przesun(v);
}
void trojkat::obroc(const punkt p, const double alfa) {
    p1.obroc(p, alfa), p2.obroc(p, alfa), p3.obroc(p, alfa);
}
void trojkat::symetriawzgp(const punkt p) {
    p1.symetriawzgp(p), p2.symetriawzgp(p), p3.symetriawzgp(p);
}
void trojkat::symetriawzgox() {
    p1.symetriawzgox(), p2.symetriawzgox(), p3.symetriawzgox();
}
void trojkat::symetriawzgoy() {
    p1.symetriawzgoy(), p2.symetriawzgoy(), p3.symetriawzgoy();
}
double trojkat::pole() const{
    double b1 = odleglosc(p1, p2), b2 = odleglosc(p2, p3), b3 = odleglosc(p3, p1);
    double d = (b1+b2+b3)/2;
    return sqrt(d*(d-b1)*(d-b2)*(d-b3));
}
double trojkat::obwod() const{
    double b1 = odleglosc(p1, p2), b2 = odleglosc(p2, p3), b3 = odleglosc(p3, p1);
    return b1+b2+b3;
}
bool trojkat::czypwewnatrz(const punkt p) const {
    odcinek b1(p1, p2), b2(p2, p3), b3(p3, p1);
    if(b1.czylezy(p) || b2.czylezy(p) || b3.czylezy(p)) return true;
    if(wspoliniowosc(p1, p2, p) || wspoliniowosc(p1, p3, p) || wspoliniowosc(p2, p3, p)) return false;
    trojkat t1(p1, p2, p), t2(p2, p3, p), t3(p3, p1, p); 
    if(abs(t1.pole()+t2.pole()+t3.pole()-this->pole()) < eps) return true;
    return false;
}
bool czyrozlaczne(const trojkat t1, const trojkat t2) {
    odcinek b1(t1.pkt1(), t1.pkt2()), b2(t1.pkt2(), t1.pkt3()), b3(t1.pkt3(), t1.pkt1());
    odcinek b4(t2.pkt1(), t2.pkt2()), b5(t2.pkt2(), t2.pkt3()), b6(t2.pkt3(), t2.pkt1());
    if(czyprzeciecie(b1,b4) || czyprzeciecie(b1,b5) || czyprzeciecie(b3,b6) ||
    czyprzeciecie(b2,b4) || czyprzeciecie(b2,b5) || czyprzeciecie(b2,b6) ||
    czyprzeciecie(b3,b4) || czyprzeciecie(b3,b5) || czyprzeciecie(b3,b6))
        return false;
    return true;
}
bool czyzawiera(const trojkat t2, const trojkat t1) {
    if(t2.czypwewnatrz(t1.pkt1()) && t2.czypwewnatrz(t1.pkt2()) &&
    t2.czypwewnatrz(t1.pkt3())) return true;
    return false;
}