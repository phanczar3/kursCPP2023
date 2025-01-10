#ifndef __BOARDTICTACTOE_INCLUDED
#define __BOARDTICTACTOE_INCLUDED
#include <utility>
using std::pair;
namespace boardTicTacToe {
    class board {
        private:
            char b[4][4];
            bool xTurn;
            bool userTurn;
        public:
            board();
            char getBoardSpace(int x, int y);
            bool isUserTurn();
            void update(pair<char, int> curInput);
            bool gameEnded;
            pair<bool,int> checkEndGame();
    };
}
#endif