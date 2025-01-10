#ifndef __STREAMS_INCLUDED_
#define __STREAMS_INCLUDED_
#include <iostream>

std::istream& clearline(std::istream& is);
class ignore {
    friend std::istream& operator >> (std::istream& is, const ignore ig);
    public:
        int num;
        ignore(int x);
};
class myindex {
    friend std::ostream& operator << (std::ostream& os, const myindex in);
    public:
        int x;
        int w;
        myindex(int myx, int myw);
};
std::ostream& comma(std::ostream& os);
std::ostream& colon(std::ostream& os);



#endif