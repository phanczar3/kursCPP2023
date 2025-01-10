#ifndef __OPERATORY2_INCLUDED_
#define __OPERATORY2_INCLUDED_
#include "wyrazenie.hpp"
#include "operandy.hpp"
#include "operatory.hpp"
class op2 : public op1 {
    protected:
        wyrazenie *w2;
    public:
        op2(wyrazenie *v, wyrazenie *v2);
};
string bracket(string s);
class dodaj : public op2 {
    using op2::op2;
    public:
        double oblicz() override;
        string zapis() override;
        int pr() override;
};
class odejmij : public op2 {
    using op2::op2;
    public:
        double oblicz() override;
        string zapis() override;
        int pr() override;
};
class mnoz : public op2 {
    using op2::op2;
    public:
        double oblicz() override;
        string zapis() override;
        int pr() override;
};
class dziel : public op2 {
    using op2::op2;
    public:
        double oblicz() override;
        string zapis() override;
        int pr() override;
};
class modulo : public op2 {
    using op2::op2;
    public:
        double oblicz() override;
        string zapis() override;
        int pr() override;
};
class potega : public op2 {
    using op2::op2;
    public:
        double oblicz() override;
        string zapis() override;
        int pr() override;
};
class logarytm : public op2 {
    using op2::op2;
    public:
        double oblicz() override;
        string zapis() override;
        int pr() override;
};


#endif