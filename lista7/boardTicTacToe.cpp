#include "boardTicTacToe.hpp"
#include <stdexcept>
#include <utility>
using std::invalid_argument;
using boardTicTacToe::board;
using std::pair;
board::board() {
    xTurn = true;
    userTurn = true;
    gameEnded = false;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) 
            b[i][j] = '#';
}
char board::getBoardSpace(int x, int y) {
    if(x < 0 || x > 3 || y < 0 || y > 3)
        throw invalid_argument("złe wsplrzedne");
    return b[x][y];
}
bool board::isUserTurn() {
    return userTurn;
}
void board::update(pair<char, int> curInput) {
    if(curInput.first < 'a' || curInput.first > 'd' ||
    curInput.second < 1 || curInput.second > 4)
        throw invalid_argument("złe wspolrzedne");
    int x = curInput.first - 'a';
    int y = curInput.second - 1;
    if(b[x][y] != '#')
        throw invalid_argument("zajęte pole");
    b[x][y] = (xTurn? 'X' : 'O');
    xTurn = !xTurn;
    userTurn = !userTurn;
}
pair<bool,int> board::checkEndGame() {
    bool end = false, userWon = false;
    for(int i = 0; i < 4 && !end; i++) {
        char x = b[i][0];
        if(x == '#') continue;
        bool ans = true;
        for(int j = 1; j < 4; j++) 
            if(b[i][j] != x) ans = false;
        if(ans) end = true, userWon = (x == 'X'? true : false);
    }
    for(int j = 0; j < 4 && !end; j++) {
        char x = b[j][0];
        if(x == '#') continue;
        bool ans = true;
        for(int i = 1; i < 4; i++) 
            if(b[i][j] != x) ans = false;
        if(ans) end = true, userWon = (x == 'X'? true : false);
    }
    for(int rep = 0; rep < 2; rep++) {
        int curx = (rep == 0? 0 : 3), cury = 0;
        char x = b[curx][cury];
        if(x == '#') continue;
        bool ans = true;
        for(int i = 1; i < 4; i++) {
            curx += (rep == 0? 1 : -1);
            cury++;
            if(b[curx][cury] != x) ans = false;
        }
        if(ans) end = true, userWon = (x == 'X'? true : false);
    }
    if(end) {
        gameEnded = true;
        return {end, userWon};
    }
    int cnt = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(b[i][j] == '#') cnt++;
    if(cnt == 0) {
        gameEnded = true;
        return {true, 2};
    }
    return {false, 0};
}
