#ifndef __KALKULATOR_INCLUDED_
#define __KALKULATOR_INCLUDED_
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
namespace kalkulator { 
    class symbol {
        public: 
            virtual double returnVal(std::stack<double> &s) = 0;
    };
    class operand : public symbol {
    };
    class funkcja1arg : public symbol {
        private:
            std::function<double(double)> f;
        public:
            funkcja1arg(std::string s);
            double returnVal(std::stack<double> &s) override;
    };
    class funkcja2arg : public symbol {
        private:
            std::function<double(double, double)> f;
        public:
            funkcja2arg(std::string s);
            double returnVal(std::stack<double> &s) override;
    };
    class liczba : public operand {
        private:
            double val;
        public:
            liczba(double x);
            double returnVal(std::stack<double> &s) override;
    };
    class zmienna : public operand {
        private:
            std::string name;
            static std::map<std::string, double> mp;
            static std::set<std::string> forbiddenNames;
        public:
            zmienna(std::string s);
            double returnVal(std::stack<double> &s) override;
            static bool isForbidden(std::string s);
            static void setVarVal(std::string s, double val);
            static void clearVariables();
            static void forbiddenNamesInit();
    };
    class stala : public operand {
        private:
            std::string name;
            double val;
        public:
            stala(std::string s, double x);
            double returnVal(std::stack<double> &s) override;
    };
    class e : public stala {
        public:
            e();
    };
    class pi : public stala {
        public:
            pi();
    };
    class fi : public stala {
        public:
            fi();
    };
    std::queue<symbol*> parseExp(std::vector<std::string> v);
    symbol* parseSymbol(std::string s);
    double evalONP(std::queue<symbol*> q);
}


#endif