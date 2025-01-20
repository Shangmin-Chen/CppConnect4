#include "game.h"
#include <iostream>

Game::Game(int rows, int cols, bool aiEnabled, int lookahead) : board(rows, cols), currentPlayer(1), aiEnabled(aiEnabled), lookahead(lookahead) {}

void Game::start() {
    bool gameOver = false;
    while (!gameOver) {
        board.printBoard();

        int col;
        if (aiEnabled && currentPlayer == 2) {
            col = AI::getMove(board, currentPlayer, "RANDOM", lookahead);
            std::cout << "AI chooses column " << col << ".\n";
        } else {
            std::cout << "Player " << currentPlayer << "'s turn. Enter column: ";
            while (!(std::cin >> col) || !board.isValidMove(col)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid column: ";
            }
        }

        board.dropPiece(col, currentPlayer);

        gameOver = isGameOver();
        if (!gameOver) switchPlayer();
    }

    board.printBoard();
    if (board.checkWin()) {
        std::cout << "Player " << currentPlayer << " wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

bool Game::isGameOver() {
    return board.checkWin() || isDraw();
}

bool Game::isDraw() {
    return board.isFull();
}