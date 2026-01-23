#pragma once

#include <utility>

// first is row, second is column
using piece = std::pair<int, int>;

namespace queen_attack {

class chess_board {
public:
    chess_board(piece, piece);

    piece white() const;
    piece black() const;

    bool can_attack() const;
private:
    piece white_;
    piece black_;
};


}  // namespace queen_attack
