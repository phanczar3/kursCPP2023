#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "streams.hpp"
void myproc(std::istream& is) {
    std::vector<std::pair<std::string, int>> v;
    int cnt = 1;
    while(!is.eof()) {
        std::string s;
        getline(is, s);
        v.push_back({s, cnt++});
    }
    sort(v.begin(), v.end());
    for(auto p : v) {
        std::cout << myindex(p.second, 1) << p.first << "\n";
    }
}
int main() {

    // std::string s;
    // std::cin >> clearline >> s;
    // std::cout << s << "\n";
    std::string s2;
    std::cin >> ignore(3) >> s2;
    std::cout << s2 << "\n";

    std::cout << comma << "HALO1\n";
    std::cout << colon << "HALO2\n";
    std::cout << myindex(123, 4) << "HALO3\n";

    std::ifstream wej;
    wej.open("test.txt");
    myproc(wej);


    return 0;
}