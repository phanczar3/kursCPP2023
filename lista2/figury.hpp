class wektor{
    private:
        double x, y;
    public:
        wektor();
        wektor(double a, double b);
        double wspx() const;
        double wspy() const;
};
class punkt{
    private:
        double x, y;
    public:
        punkt();
        punkt(double a, double b);
        punkt(const punkt &p);
        punkt& operator=(const punkt &p);
        double wspx() const;
        double wspy() const;
        void pokaz() const;
        void przesun(const wektor v);
        void obroc(const punkt p, const double alfa);
        void symetriawzgp(const punkt p);
        void symetriawzgox();
        void symetriawzgoy();
};
double odleglosc(const punkt a, const punkt b);
double det(const punkt a, const punkt b, const punkt c);
bool wspoliniowosc(const punkt a, const punkt b, const punkt c);
class odcinek{
    private:
        punkt p1, p2;
    public:
        odcinek();
        odcinek(const punkt a, const punkt b);
        odcinek(const odcinek &o);
        odcinek& operator=(const odcinek &o);
        punkt pkt1() const;
        punkt pkt2() const;
        void pokaz() const;
        void przesun(const wektor v);
        void obroc(const punkt p, const double alfa);
        void symetriawzgp(const punkt p);
        void symetriawzgox();
        void symetriawzgoy();
        double dlugosc() const;
        bool czylezy(const punkt p) const;
};
bool czyrownolegle(const odcinek o1, const odcinek o2);
bool czyprostopadle(const odcinek o1, const odcinek o2);
bool czyprzeciecie(const odcinek o1, const odcinek o2);
class trojkat{
    private:
        punkt p1, p2, p3;
    public:
        trojkat();
        trojkat(const punkt a, const punkt b, const punkt c);
        trojkat(const trojkat &t);
        trojkat& operator=(const trojkat &t);
        punkt pkt1() const;
        punkt pkt2() const;
        punkt pkt3() const;
        void pokaz() const;
        void przesun(const wektor v);
        void obroc(const punkt p, const double alfa);
        void symetriawzgp(const punkt p);
        void symetriawzgox();
        void symetriawzgoy();
        double pole() const;
        double obwod() const;
        bool czypwewnatrz(const punkt p) const;
};
bool czyrozlaczne(const trojkat t1, const trojkat t2);
bool czyzawiera(const trojkat t1, const trojkat t2);
