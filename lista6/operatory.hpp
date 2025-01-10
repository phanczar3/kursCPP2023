#ifndef __OPERATORY_INCLUDED__
#define __OPERATORY_INCLUDED__
#include "wyrazenie.hpp"
class op1 : public wyrazenie {
    protected:
        wyrazenie *w;
    public:
        op1(wyrazenie *v);
        int pr() override;
};
class sinus : public op1 {
    using op1::op1;
    public:
        double oblicz() override;
        string zapis() override;
};
class cosinus : public op1 {
    using op1::op1;
    public:
        double oblicz() override;
        string zapis() override;
};
class bezwzg : public op1 {
    using op1::op1;
    public:
        double oblicz() override;
        string zapis() override;
};
class eksponens : public op1 {
    using op1::op1;
    public:
        double oblicz() override;
        string zapis() override;
};
class logn : public op1 {
    using op1::op1;
    public:
        double oblicz() override;
        string zapis() override;
};
class przeciw : public op1 {
    using op1::op1;
    public:
        double oblicz() override;
        string zapis() override; // TO DO
};
class odwrot : public op1 {
    using op1::op1;
    public:
        double oblicz() override;
        string zapis() override; // TO DO
};
#endif