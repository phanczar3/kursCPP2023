#ifndef __OBLICZENIA_INCLUDED_
#define __OBLICZENIA_INCLUDED_
#include <iostream>
namespace obliczenia {
    using std::ostream;
    using std::logic_error;
    using std::string;
    class wymierna {
        friend ostream& operator<< (ostream &wyj, const wymierna &w) noexcept(true);
        private:
            int licz, mian;
            void skroc(int &a, int &b) noexcept(true);
            bool zakresy(long long a) const noexcept(true);
            int gcd(int a, int b) noexcept(true);
        public:
            wymierna() noexcept(true);
            wymierna(int a) noexcept(true);
            wymierna(int a, int b) noexcept(false);
            int pl() const noexcept(true);
            int pm() const noexcept(true);
            wymierna operator+(const wymierna& w) noexcept(false);
            wymierna operator-(const wymierna& w) noexcept(false);
            wymierna operator*(const wymierna& w) noexcept(false);
            wymierna operator/(const wymierna& w) noexcept(false);
            wymierna operator-() const noexcept(false);
            wymierna operator!() const noexcept(false);
            explicit operator int () const noexcept(true);
            operator double () const noexcept(true);
    };
    class wyjatek_wymierny : public logic_error{
        protected:
            string msg;
        public:
            wyjatek_wymierny(const string &what_arg) noexcept(false);
            const char * what() const noexcept(true) override;
    };
    class dzielenie_przez_0 : public wyjatek_wymierny {
        public:
            dzielenie_przez_0(const string &what_arg) noexcept(false);
    };
    class przekroczenie_zakresu : public wyjatek_wymierny {
        public:
            przekroczenie_zakresu(const string &what_arg) noexcept(false);
    };
}
#endif