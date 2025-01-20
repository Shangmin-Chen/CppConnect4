#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board(int rows, int cols);
    void printBoard();
    bool dropPiece(int col, int player);
    void removePiece(int col);
    bool checkWin();
    bool isFull();
    int getCols() const;
    bool isValidMove(int col) const;
    bool isWinFor(int player);

private:
    std::vector<std::vector<int>> grid;
    int rows, cols;

    bool checkDirection(int startRow, int startCol, int dRow, int dCol, int player);
};

#endif