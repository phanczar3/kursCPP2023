#include <iostream>
#include <utility>
#include "iohandlerTicTacToe.hpp"

using std::pair;
using std::cout;
using std::cin;
using iohandlerTicTacToe::iohandler;
iohandler::iohandler() {
    cout << "Witaj w grze kolko i krzyzyk\n";
}
pair<char,int> iohandler::getInput() {
    cout << "Podaj swoj ruch (najpierw litera potem cyfra):\n";
    char x;
    int y;
    cin >> x >> y;
    return {x, y};
}
void iohandler::wrongInput(const char* s) {
    if(strcmp(s, "złe wspolrzedne"))
        cout << "Podales bledne wspolrzedne" << 
        "(pierwsza powinna byc literą a-d a druga cyfrą 1-4)\n"
        "Sprobuj ponownie:\n";
    else if(strcmp(s, "zajęte pole"))
        cout << "Podane pole jest juz zajete\n" <<
        "Sprobuj ponownie:\n";
}
void iohandler::oponentMove(pair<char, int> curInput) {
    cout << "Przeciwnik zakreślił O na " << 
    curInput.first << " " << curInput.second << "\n";
}
void iohandler::finalResult(int x) {
    if(x == 0) {
        cout << "Przeciwnik wygrał, moze nastepnym razem sie uda ;)\n";
    } else if(x == 1) {
        cout << "Brawo wygrałeś!\n";
    } else {
        cout << "Remis, moze nastepnym razem sie uda ;)\n";
    }
}


