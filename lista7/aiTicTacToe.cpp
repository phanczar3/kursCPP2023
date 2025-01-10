#include "aiTicTacToe.hpp"
#include <utility>
#include <vector>
#include <cstdlib>
#include <time.h>
using std::time;
using std::srand;
using std::rand;
using std::vector;
using std::pair;
using aiTicTacToe::ai;

ai::ai(board &b) : b(b) {
    srand(time(0));
}
int ai::heatmap[4][4]= {{1, 2, 2, 1},
                        {2, 4, 4, 2},
                        {2, 4, 4, 2},
                        {1, 2, 2, 1}};
pair<char,int> ai::getMove() {
    vector<pair<char,int>> possible;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(b.getBoardSpace(i, j) == '#') {
                for(int rep = 0; rep < heatmap[i][j]; rep++)
                    possible.push_back({(char)('a'+i), j+1});
            }
        }
    }
    int randomIdx = rand() % possible.size();
    return possible[randomIdx];
}
