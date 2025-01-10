#ifndef __WYRAZENIE_INCLUDED__
#define __WYRAZENIE_INCLUDED__
#include <string>
using std::string;
class wyrazenie {
    public:
        virtual double oblicz() = 0;
        virtual string zapis() = 0;
        virtual int pr() = 0;
};

#endif