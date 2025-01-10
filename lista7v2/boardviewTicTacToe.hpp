#ifndef __BOARDVIEWTICTACTOE_INCLUDED_
#define __BOARDVIEWTICTACTOE_INCLUDED_
#include "boardTicTacToe.hpp"
namespace boardviewTicTacToe {
    using namespace boardTicTacToe;
    class boardview {
        private:
            board &b;
        public:
            boardview(board &b);
            void show();
    };
}

#endif