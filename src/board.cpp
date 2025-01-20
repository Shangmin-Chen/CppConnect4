#include "board.h"
#include <iostream>

Board::Board(int rows, int cols) : rows(rows), cols(cols) {
    grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
}

void Board::printBoard() {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell ? (cell == 1 ? "X" : "O") : ".") << " ";
        }
        std::cout << std::endl;
    }
}

bool Board::dropPiece(int col, int player) {
    if (col < 0 || col >= cols) {
        std::cout << "Invalid column. Please choose a column between 0 and " << cols - 1 << ".\n";
        return false;
    }

    for (int row = rows - 1; row >= 0; --row) {
        if (grid[row][col] == 0) {
            grid[row][col] = player;
            return true;
        }
    }

    std::cout << "Column is full. Try a different column.\n";
    return false;
}

void Board::removePiece(int col) {
    for (int row = 0; row < rows; ++row) {
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            break;
        }
    }
}

bool Board::checkWin() {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (grid[row][col] != 0) {
                int player = grid[row][col];
                // Check all directions: horizontal, vertical, diagonal down-right, diagonal up-right
                if (checkDirection(row, col, 0, 1, player) || // Horizontal
                    checkDirection(row, col, 1, 0, player) || // Vertical
                    checkDirection(row, col, 1, 1, player) || // Diagonal down-right
                    checkDirection(row, col, -1, 1, player)) { // Diagonal up-right
                    return true;
                }
            }
        }
    }
    return false;
}

bool Board::checkDirection(int startRow, int startCol, int dRow, int dCol, int player) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        int row = startRow + i * dRow;
        int col = startCol + i * dCol;

        if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == player) {
            ++count;
        } else {
            break;
        }

        if (count == 4) {
            return true;
        }
    }
    return false;
}

bool Board::isFull() {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == 0) {
                return false;
            }
        }
    }
    return true;
}

int Board::getCols() const {
    return cols;
}

bool Board::isValidMove(int col) const {
    if (col < 0 || col >= cols) return false;
    return grid[0][col] == 0;
}

bool Board::isWinFor(int player) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (grid[row][col] == player) {
                if (checkDirection(row, col, 0, 1, player) || // Horizontal
                    checkDirection(row, col, 1, 0, player) || // Vertical
                    checkDirection(row, col, 1, 1, player) || // Diagonal down-right
                    checkDirection(row, col, -1, 1, player)) { // Diagonal up-right
                    return true;
                }
            }
        }
    }
    return false;
}