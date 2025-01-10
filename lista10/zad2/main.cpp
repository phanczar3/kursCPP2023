#include "streams.hpp"
#include <iostream>
#include <fstream>

int main() {
    srand(time(nullptr));
    const int M = 5;
    {
        wyjscie wyj("test.bin");
        for(int i = 0; i < M; i++) {
            int x = rand() % 10 + 1;
            std::cout << "zapisuję: " << x << "\n";
            wyj.zapisz<int>(x);
        }
    }
    {
        wejscie wej("test.bin");
        for(int i = 0; i < M; i++) {
            std::cout << "odczytuję: " << wej.wczytaj<int>() << "\n";
        }
    }
    const int N = 2;
    {
        wyjscie wyj("test2.bin");
        for(int i = 0; i < N; i++) {
            int x = rand() % 100000000 + 1;
            std::cout << "zapisuję: " << x << "\n";
            wyj.zapisz<int>(x);
        }
    }
    {
        wejscie wej("test2.bin");
        for(int i = 0; i < N*4; i++) {
            char x = wej.wczytaj<char>();
            std::cout << "odczytuję: " << std::hex << int(x) << " = " 
            << std::dec << int(x) << "\n";
        }
    }





    return 0;
}