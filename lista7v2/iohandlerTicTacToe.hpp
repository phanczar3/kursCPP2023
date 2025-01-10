#ifndef __IOHANDLERTICTACTOE_INCLUDED
#define __IOHANDLERTICTACTOE_INCLUDED
#include <utility>
using std::pair;
namespace iohandlerTicTacToe {
    class iohandler {
        public:
            iohandler();
            pair<char,int> getInput();
            void wrongInput(const char *s);
            void oponentMove(pair<char, int> curInput);
            void finalResult(int x);

    };
}
#endif