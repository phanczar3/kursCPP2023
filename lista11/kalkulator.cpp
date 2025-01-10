#include "kalkulator.hpp"
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <math.h>
#include <tuple>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
using namespace kalkulator;
funkcja1arg::funkcja1arg(std::string s) {
    if(s == "abs")
        f = [](double x) {return abs(x);};
    else if(s == "sgn")
        f = [](double x) { if(x < 0) return -1;
        else if(x == 0) return 0;
        else return 1;};
    else if(s == "floor")
        f = [](double x) {return floor(x);};
    else if(s == "ceil")
        f = [](double x) {return ceil(x);};
    else if(s == "frac")
        f = [](double x) {return x-floor(x);};
    else if(s == "sin")
        f = [](double x) {return sin(x);};
    else if(s == "cos")
        f = [](double x) {return cos(x);};
    else if(s == "atan")
        f = [](double x) {return atan(x);};
    else if(s == "acot")
        f = [](double x) {if(x == 0) throw std::invalid_argument("acot undefined");
        else return atan((double)1/x);};
    else if(s == "ln")
        f = [](double x) {return log(x);};
    else if(s == "exp")
        f = [](double x) {return exp(x);};
    else
        throw std::invalid_argument("unknown function"); 
}
double funkcja1arg::returnVal(std::stack<double> &s) {
    if(s.empty()) 
        throw std::invalid_argument("empty stack but argument is needed");
    double x = s.top();
    s.pop();
    return std::apply(f, std::make_tuple(x));
}
funkcja2arg::funkcja2arg(std::string s) {
    if(s == "modulo")
        f = [](double x, double y) {return fmod(x, y);};
    else if(s == "min") 
        f = [](double x, double y) {return std::min(x, y);};
    else if(s == "max")
        f = [](double x, double y) {return std::max(x, y);};
    else if(s == "log")
        f = [](double x, double y) {if(x > 0 && y > 0 && log(y) != 0) return log(x)/log(y);
        else throw std::invalid_argument("log undefined");};
    else if(s == "pow")
        f = [](double x, double y) {if(pow(x, y)==pow(x, y)) return pow(x, y);
        else throw std::invalid_argument("pow undefined");};
    else if(s == "+")
        f = [](double x, double y) {return x + y;};
    else if(s == "-")
        f = [](double x, double y) {return x - y;};
    else if(s == "*")
        f = [](double x, double y) {return x * y;};
    else if(s == "/")
        f = [](double x, double y) {return x / y;};
    else
        throw std::invalid_argument("unknown function");
}
double funkcja2arg::returnVal(std::stack<double> &s) {
    if(s.empty()) 
        throw std::invalid_argument("empty stack but argument is needed");
    double x = s.top();
    s.pop();
    if(s.empty()) 
        throw std::invalid_argument("empty stack but argument is needed");
    double y = s.top();
    s.pop();
    return std::apply(f, std::make_tuple(y, x));
}
std::map<std::string, double> zmienna::mp;
std::set<std::string> zmienna::forbiddenNames;
zmienna::zmienna(std::string s) {
    if(s.length() > 7)
        throw std::invalid_argument("invalid name: length must be <= 7");
    else if(isForbidden(s))
        throw std::invalid_argument("invalid name: name has a special meaning");
    //std::cout << s << "\n";
    name = s;
}
double zmienna::returnVal(std::stack<double> &s) {
    std::map<std::string, double>::iterator it = mp.find(name);
    if(it == mp.end())
        throw std::invalid_argument("undefined variable");
    return it->second;
}
bool zmienna::isForbidden(std::string s) {
    return forbiddenNames.find(s) != forbiddenNames.end();
}
void zmienna::setVarVal(std::string s, double val) {
    mp[s] = val;
}
void zmienna::forbiddenNamesInit() {
    std::ifstream wej("forbiddenNames.txt");
    while(!wej.eof()) {
        std::string s;
        wej >> s;
        forbiddenNames.insert(s);
    }
    wej.close();
}
void zmienna::clearVariables() {
    mp.clear();
}
liczba::liczba(double x) : val(x) {}
double liczba::returnVal(std::stack<double> &s) {
    return val;
}
stala::stala(std::string s, double x) {
    name = s, val = x;
}
double stala::returnVal(std::stack<double> &s) {
    return val;
}
e::e() : stala("e", 2.718281828459) {}
pi::pi() : stala("pi", 3.141592653589) {}
fi::fi() : stala("fi", 1.618033988750) {}
std::queue<symbol*> kalkulator::parseExp(std::vector<std::string> v) {
    std::queue<symbol*> vparsed;
    for(auto it = v.begin(); it != v.end(); it++) 
        vparsed.push(parseSymbol(*it));
    return vparsed;
}
symbol* kalkulator::parseSymbol(std::string s) {
    if(s == "e") return (symbol*) new e();
    if(s == "pi") return (symbol*) new pi();
    if(s == "fi") return (symbol*) new fi();        
    try {
        symbol* ptr = new liczba(std::stod(s));
        return ptr;
    } catch(const std::invalid_argument &e) {
        try {
            symbol* f = new funkcja1arg(s);
            return f;
        } catch(const std::invalid_argument &e) {
            try {
                symbol* f =  new funkcja2arg(s);
                return f;
            } catch(const std::invalid_argument &e) {
                try {
                    symbol* z = new zmienna(s);
                    return z;
                } catch(const std::invalid_argument &e) {
                    throw e;
                }
            }
        }
    }
}
double kalkulator::evalONP(std::queue<symbol*> q) {
    std::stack<double> s;
    while(!q.empty()) {
        symbol* cur = q.front();
        q.pop();
        double curVal;
        try {
            curVal = cur->returnVal(s);
        } catch(std::invalid_argument &e) {
            throw e;
        }
        s.push(curVal);
    }
    if(s.size() != 1)
        throw std::invalid_argument("invalid ONP expression");
    return s.top();
}