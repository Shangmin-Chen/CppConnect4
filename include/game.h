#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "ai.h"

class Game {
public:
    Game(int rows, int cols, bool aiEnabled, int lookahead);
    void start();

private:
    Board board;
    int currentPlayer;
    bool aiEnabled;
    int lookahead;

    void switchPlayer();
    bool isGameOver();
    bool isDraw();
};

#endif