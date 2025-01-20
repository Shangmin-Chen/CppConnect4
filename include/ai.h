#ifndef AI_H
#define AI_H

#include "board.h"
#include <vector>

class AI {
public:
    static int getMove(Board& board, int player, const std::string& tiebreak, int lookahead);
private:
    static std::vector<int> scoresFor(Board& board, int player, int lookahead);
    static int maxScoreColumn(const std::vector<int>& scores, const std::string& tiebreak);
};

#endif