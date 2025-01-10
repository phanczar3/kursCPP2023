#include "kalkulator.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <queue>
using namespace kalkulator;
int main() {
    zmienna::forbiddenNamesInit();
    std::string s;
    while(true) {
        getline(std::cin, s);
        std::stringstream ss(s);
        std::vector<std::string> v;
        while(ss >> s) {
            v.push_back(s);
        }
        try {
            if(v.front() == "print") {
                v.erase(v.begin());
                std::queue<symbol*> q = parseExp(v);
                double val = evalONP(q);
                std::cout << "Value of this ONP: " << val << "\n";
            } else if(v.front() == "set"){
                if(v.size() < 4 || v[2] != "to")
                    throw std::invalid_argument("invalid set syntax");
                std::string name = v[1];
                zmienna tmp(name);
                v.erase(v.begin(), v.begin()+3);
                std::queue<symbol*> q = parseExp(v);
                double val = evalONP(q);
                std::cout << "Variable " << name << " set to: " << val << "\n";
                zmienna::setVarVal(name, val);
            } else if(v.front() == "clear") {
                if(v.size() != 1)
                    throw std::invalid_argument("invalid clear syntax");
                zmienna::clearVariables();
            } else if(v.front() == "exit") {
                if(v.size() != 1)
                    throw std::invalid_argument("invalid exit syntax");
                break;
            } else {
                throw std::invalid_argument("unknown command");
            }
        } catch (const std::invalid_argument &e) {
            std::clog << e.what() << "\n";
        }
    }

    

    return 0;
}