#ifndef __PIKSEL_INCLUDED__
#define __PIKSEL_INCLUDED__

#include "kolor.hpp"
class piksel{
    friend ostream & operator << (ostream &wy, const piksel &p);
    protected:
        static int width;
        static int height;
        int x;
        int y;
        bool outOfBounds(int a, int b) const;
    public:
        piksel(int a, int b);
        int leftDist() const;
        int rightDist() const;
        int upDist() const;
        int downDist() const;
};
int odleglosc(const piksel &p, const piksel &q);
class pikselkolorowy : public piksel {
    protected:
        kolortransparentny k;
    public:
        pikselkolorowy(int a, int b, kolortransparentny k0);
        void moveVector(int dx, int dy);
};
#endif