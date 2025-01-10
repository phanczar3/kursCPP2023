wejscie::wejscie(const char* filename) {
    wej.exceptions(std::ios::failbit | std::ios::badbit);
    wej.open(filename, std::ios::in | std::ios::binary);
}
wejscie::~wejscie() {
    wej.close();
}
template<typename T>
T wejscie::wczytaj() {
    T v;
    wej.read(reinterpret_cast<char*>(&v), sizeof(T));
    return v;
}
wyjscie::wyjscie(const char* filename){
    wyj.exceptions(std::ios::failbit | std::ios::badbit);
    wyj.open(filename, std::ios::out | std::ios::binary);
};
wyjscie::~wyjscie() {
    wyj.close();
}
template <typename T>
void wyjscie::zapisz(T x) {
    wyj.write(reinterpret_cast<char*>(&x), sizeof(T));
}