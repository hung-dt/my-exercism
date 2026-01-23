#include "queen_attack.h"

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
    // can attack on same row
    if (white_.first == black_.first) return true;

    // can attack on same column
    if (white_.second == black_.second) return true;

    // first diagonal
    auto r = white_.first - 1;
    auto c = white_.second + 1;
    while ( r >= 0 && c < 8) {
        if (r == black_.first && c == black_.second)
            return true;
        r--;
        c++;
    }

    // second diagonal
    r = white_.first + 1;
    c = white_.second + 1;
    while (r < 8 && c < 8) {
        if (r == black_.first && c == black_.second)
            return true;
        r++;
        c++;
    }

    // third diagonal
    r = white_.first + 1;
    c = white_.second - 1;
    while (r < 8 && c >= 0) {
        if (r == black_.first && c == black_.second)
            return true;
        r++;
        c--;
    }

    // fourth diagonal
    r = white_.first - 1;
    c = white_.second - 1;
    while (r >= 0 && c >= 0) {
        if (r == black_.first && c == black_.second)
            return true;
        r--;
        c--;
    }

    return false;
}
}  // namespace queen_attack
