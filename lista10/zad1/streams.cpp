#include "streams.hpp"
#include <iomanip>
#include <vector>
std::istream& clearline(std::istream& is) {
    while(!is.eof() && is.get() != '\n') {}
    return is;
}

std::istream& operator >> (std::istream& is, const ignore ig) {
    int cnt = 0;
    while(cnt++ < ig.num && !is.eof() && is.get() != '\n' ) {}
    return is;
}
ignore::ignore(int x) : num(x) {}

std::ostream& comma(std::ostream& os) {
    os << ", ";
    return os;
}
std::ostream& colon(std::ostream& os) {
    os << ": ";
    return os;
}

std::ostream& operator << (std::ostream& os, const myindex in) {
    os << "[" << std::setw(in.w) << in.x << "]";
    return os;
}
myindex::myindex(int myx, int myw) : x(myx), w(myw) {}

