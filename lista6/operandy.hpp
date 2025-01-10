#ifndef __OPERANDY_INCLUDED_
#define __OPERANDY_INCLUDED_
#include "wyrazenie.hpp"
#include <string>
#include <vector>
#include <utility>
using std::string;
using std::vector;
using std::pair;
class liczba final : public wyrazenie {
    private:
        double val;
    public:
        liczba();
        liczba(double v);
        double oblicz() override;
        string zapis() override;
        int pr() override;
};
class zmienna final : public wyrazenie {
    private:
        static vector<pair<string,double>> dic;
        static bool jest(string s);
        static int znajdz(string s);
        string nam;
    public:
        static void dodaj(string s, double val);
        static void modyfikuj(string s, double val);
        static void usun(string s);
        zmienna(string s);
        double oblicz() override;
        string zapis() override;
        int pr() override;
    
};
class stala : public wyrazenie {
    private:
        string nam;
        double val;
    public:
        stala(string s, double v);
        double oblicz() override;
        string zapis() override;
        int pr() override;
};
class pi final : public stala {
    public:
        pi();
};
class e final : public stala {
    public:
        e();
};
class fi final : public stala {
    public:
        fi();
};

#endif

