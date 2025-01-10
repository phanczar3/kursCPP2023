#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <utility>

using namespace std;
const vector<pair<int, string>> rzym = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, 
    {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};
string bin2rzym (int x) {
    if(x < 1 || x > 3999) throw domain_error("Liczba spoza dziedziny");
    
    string res = "";
    for(auto p : rzym) {
        while(x >= p.first) x -= p.first, res += p.second;
    }
    return res;
    
}

int main(int argc, const char* argv[]) {
    
    if(argc < 2) {
        cout << "Niepoprawna liczba argumentow\n";
        exit(0);
    }
    for(int i = 1; i < argc; i++) {
        int num = 0;
        try {
            num = stoi(argv[i]);
            cout << bin2rzym(num) << "\n";
        } catch (invalid_argument const &ex) {
            ;    
        } catch (domain_error const &ex) {
            ;
        }
        
    }
    
    
    return 0;
}