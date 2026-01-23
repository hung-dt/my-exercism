#include "queen_attack.h"

#include <cmath>
#include <stdexcept>

namespace queen_attack {

chess_board::chess_board(piece w, piece b)
    : white_{w}, black_{b}
{
    if (white_.first < 0 || white_.second < 0
        || black_.first < 0 || black_.second < 0) {
        throw std::domain_error("");
    }

    if (white_.first > 7 || white_.second > 7
        || black_.first > 7 || black_.second > 7) {
        throw std::domain_error("");
    }

    if (white_ == black_) {
        throw std::domain_error("");
    }
}

piece chess_board::white() const {
    return white_;
}

piece chess_board::black() const {
    return black_;
}

bool chess_board::can_attack() const {
    return (white_.first == black_.first) || (white_.second == black_.second)
        || std::abs(white_.first - black_.first) == std::abs(white_.second - black_.second);
}
}  // namespace queen_attack
