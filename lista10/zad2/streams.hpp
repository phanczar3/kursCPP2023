#ifndef __STREAMS_INCLUDED_
#define __STREAMS_INCLUDED_
#include <iostream>
#include <fstream>
class wejscie {
    private:
        std::ifstream wej;
    public:
        wejscie(const char* filename);
        ~wejscie();
        template<typename T>
        T wczytaj();
};
class wyjscie {
    private:
        std::ofstream wyj;
    public:
        wyjscie(const char* filename);
        ~wyjscie();
        template <typename T>
        void zapisz(T x);
};

#include "streams.tpp"

#endif