#ifndef __KOLOR_INCLUDED__
#define __KOLOR_INCLUDED__
class kolor{
    friend ostream & operator << (ostream &wy, const kolor &k);
    protected:
        int r, g, b;
        void isValid(int x);
    public:
        kolor();
        kolor(int x, int y, int z);
        int getR() const;
        int getG() const;
        int getB() const;
        void setR(int x);
        void setG(int x);
        void setB(int x);
};
class kolortransparentny : public virtual kolor {
    protected:
        int alfa;
    public:
        kolortransparentny();
        kolortransparentny(int x, int y, int z);
        kolortransparentny(int x, int y, int z, int a);
        int getAlfa() const;
        void setAlfa(int x);
};
class kolornazwany : public virtual kolor {
    protected:
        string name = "";
        void rightName(string s);
    public:
        kolornazwany();
        kolornazwany(int x, int y, int z);
        kolornazwany(int x, int y, int z, string s);
        string getName() const;
        void setName(string s);
};
class kolornt : public kolornazwany, public kolortransparentny {
    public:
        kolornt();
        kolornt(int x, int y, int z);
        kolornt(int x, int y, int z, int a);
        kolornt(int x, int y, int z, int a, string s);
};
#endif