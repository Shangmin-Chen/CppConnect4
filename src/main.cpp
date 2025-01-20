#include <iostream>
#include "game.h"

int main() {
    std::cout << "Welcome to Connect4!" << std::endl;

    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    char aiChoice;
    std::cout << "Enable AI for Player 2? (y/n): ";
    std::cin >> aiChoice;

    int lookahead = 0;
    if (aiChoice == 'y' || aiChoice == 'Y') {
        std::cout << "Enter AI difficulty (lookahead depth): ";
        std::cin >> lookahead;
    }

    Game game(rows, cols, aiChoice == 'y' || aiChoice == 'Y', lookahead);
    game.start();
    return 0;
}