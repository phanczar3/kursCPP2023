#ifndef __AITICTACTOE_INCLUDED_
#define __AITICTACTOE_INCLUDED_
#include "boardTicTacToe.hpp"
#include <utility>
using std::pair;
namespace aiTicTacToe {
    using namespace boardTicTacToe;
    class ai {
        private:
            board &b;
            static int heatmap[4][4];
        public:
            ai(board &b);
            pair<char,int> getMove();

    };
}

#endif