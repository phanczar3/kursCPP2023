#include "iohandlerTicTacToe.hpp"
#include "boardTicTacToe.hpp"
#include "boardviewTicTacToe.hpp"
#include <utility>
#include <stdexcept>
#include "aiTicTacToe.hpp"
#include <unistd.h>
#include <iostream>
using std::invalid_argument;
using std::pair;
using iohandlerTicTacToe::iohandler;
using boardTicTacToe::board;
using boardviewTicTacToe::boardview;
using aiTicTacToe::ai;
int main() {
    iohandler ioh = iohandler();
    board b = board();
    boardview bv = boardview(b);
    ai oponent = ai(b);
    while(!b.gameEnded) {
        bv.show();
        if(b.isUserTurn()) {
            pair<char,int> curInput = ioh.getInput();
            try {
                b.update(curInput);
            } catch(invalid_argument &e) {
                ioh.wrongInput(e.what());
            }
        } else {
            pair<char,int> curInput = oponent.getMove();
            std::cout << curInput.first << " " << curInput.second << "\n";
            b.update(curInput);
            ioh.oponentMove(curInput);
        }
        pair<bool, int> curState = b.checkEndGame();
        if(curState.first) {
            bv.show();
            ioh.finalResult(curState.second);
        }
        sleep(1);
    }

    return 0;
}