#include "beer_song.h"

#include <sstream>

namespace beer_song {

std::string verse(const int n)
{
    if (n < 0) {
        return "";
    }
    if (n > 1) {
        std::ostringstream o;
        o << n << " bottles of beer on the wall, " << n << " bottles of beer.\n"
            << "Take one down and pass it around, " << (n - 1) << " bottle" << (n - 1 > 1 ? "s" : "") << " of beer on the wall.\n";
        return o.str();
    }
    if (n == 1) {
        return std::string{ "1 bottle of beer on the wall, 1 bottle of beer.\n"
        "Take it down and pass it around, no more bottles of beer on the "
        "wall.\n"};
    }

    return std::string{"No more bottles of beer on the wall, no more bottles of beer.\n"
        "Go to the store and buy some more, 99 bottles of beer on the wall.\n"};
}

std::string sing(const int s, const int e)
{
    if (s < e) return "";

    std::string v{};
    for (auto i = s; i >= e; --i) {
        v += verse(i) + "\n";
    }
    v.pop_back();    // remove the last \n
    return v;
}

}  // namespace beer_song
