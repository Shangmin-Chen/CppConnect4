#include "ai.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

int AI::getMove(Board& board, int player, const std::string& tiebreak, int lookahead) {
    std::vector<int> scores = scoresFor(board, player, lookahead);
    return maxScoreColumn(scores, tiebreak);
}

std::vector<int> AI::scoresFor(Board& board, int player, int lookahead) {
    std::vector<int> scores(board.getCols(), 0);
    for (int col = 0; col < board.getCols(); ++col) {
        if (!board.isValidMove(col)) {
            scores[col] = -1;
        } else if (board.isWinFor(player)) {
            scores[col] = 100;
        } else if (board.isWinFor(3 - player)) {
            scores[col] = 0;
        } else if (lookahead == 0) {
            scores[col] = 50;
        } else {
            board.dropPiece(col, player);
            std::vector<int> opponentScores = scoresFor(board, 3 - player, lookahead - 1);
            scores[col] = 100 - *std::max_element(opponentScores.begin(), opponentScores.end());
            board.removePiece(col);
        }
    }
    return scores;
}

int AI::maxScoreColumn(const std::vector<int>& scores, const std::string& tiebreak) {
    int maxScore = *std::max_element(scores.begin(), scores.end());
    std::vector<int> bestCols;

    for (int col = 0; col < scores.size(); ++col) {
        if (scores[col] == maxScore) {
            bestCols.push_back(col);
        }
    }

    if (tiebreak == "LEFT") {
        return bestCols.front();
    } else if (tiebreak == "RIGHT") {
        return bestCols.back();
    } else { // RANDOM
        srand(time(0));
        return bestCols[rand() % bestCols.size()];
    }
}