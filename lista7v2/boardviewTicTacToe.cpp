#include <iostream>
#include "boardviewTicTacToe.hpp"
#include "boardTicTacToe.hpp"
using boardTicTacToe::board;
using boardviewTicTacToe::boardview;
using std::cout;
boardview::boardview(board &b) : b(b) {}
void boardview::show() {
    cout << "  1   2   3   4\n";
    for(int i = 0; i < 4; i++) {
        cout << (char)('a'+i) << " ";
        for(int j = 0; j < 4; j++) {
            cout << (b.getBoardSpace(i, j) == '#'? ' ' : b.getBoardSpace(i, j));
            if(j < 3) cout << " | ";
        }
        cout << "\n";
        if(i < 3) {
            cout << " --------------\n";
        }
    }
}

