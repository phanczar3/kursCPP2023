class tab_bit{
    typedef uint64_t slowo;
    static const int rozmiarSlowa;
    friend istream & operator >> (istream &we, tab_bit &tb);
    friend ostream & operator << (ostream &wy, const tab_bit &tb);
    void friend swap(tab_bit &tb1, tab_bit &tb2);
    protected:
        int dl;
        slowo *tab;
        class ref{
            private:
                int idx;
                tab_bit &tab2;
            public:
                ref(int i, tab_bit &tb);
                operator bool() const;
                ref & operator = (bool b);
                ref & operator = (ref &r);
        };
    public:
        explicit tab_bit(int rozm);
        explicit tab_bit(slowo tb);
        explicit tab_bit(initializer_list<bool> l);
        tab_bit(const tab_bit &tb);
        tab_bit(tab_bit &&tb);
        tab_bit & operator = (const tab_bit &tb);
        tab_bit & operator = (tab_bit &&tb);
        ~tab_bit();
    private:
        bool czytaj(int i) const;
        bool pisz(int i, bool b);
        void sprawdz(const tab_bit &tb);
    public:
        bool operator[] (int i) const;
        ref operator[] (int i);
        inline int rozmiar() const;
        tab_bit operator | (const tab_bit &tb);
        tab_bit & operator |= (const tab_bit &tb);
        tab_bit operator & (const tab_bit &tb);
        tab_bit & operator &= (const tab_bit &tb);
        tab_bit operator ^ (const tab_bit &tb);
        tab_bit & operator ^= (const tab_bit &tb);
        tab_bit & operator ! ();

};