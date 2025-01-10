class liczba {
    private:
        static const int dh;    
        double * h;
        int idx;
        int rh;
    public:
        liczba();
        liczba(double x);
        ~liczba();
        liczba(const liczba &l);
        liczba(liczba &&l);
        liczba& operator=(liczba &l);
        liczba& operator=(liczba &&l);
        double operator=(double &&x);
        double pokaz() const;
        void cofnij();
};