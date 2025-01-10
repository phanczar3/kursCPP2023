#include <iostream>
#include <math.h>
using namespace std;
#include "piksel.hpp"
int piksel::width = 1920;
int piksel::height = 1080;
ostream & operator << (ostream &wy, const piksel &p) {
    wy << p.x << " " << p.y;
    return wy;
}
bool piksel::outOfBounds(int a, int b) const {
    if(a >= 0 && a < width && b >= 0 && b < height)
        return false;
    return true;
}
int piksel::leftDist() const {
    return x;
}
int piksel::rightDist() const {
    return width - x - 1;
}
int piksel::upDist() const {
    return y;
}
int piksel::downDist() const {
    return height - y - 1;
}
piksel::piksel(int a, int b) {
    if(outOfBounds(a, b))
        throw out_of_range("piksel poza ekranem");
    x = a;
    y = b;
}
int odleglosc(const piksel &p, const piksel &q) {
    float distx = abs(p.leftDist() - q.leftDist());
    float disty = abs(p.upDist() - q.upDist());
    return (int)(sqrt(distx*distx+disty*disty)+0.5);
}
pikselkolorowy::pikselkolorowy(int a, int b, kolortransparentny k0)
: piksel(a, b) { 
    k = k0; 
}
void pikselkolorowy::moveVector(int dx, int dy) {
    if(outOfBounds(x+dx, y+dy))
        throw out_of_range("piksel poza ekranem");
    x = x+dx;
    y = y+dy;

}