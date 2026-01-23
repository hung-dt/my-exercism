#include "secret_handshake.h"

#include <algorithm>

const unsigned WINK{1};
const unsigned DOUBLE_BLINK{2};
const unsigned CLOSE_EYES{4};
const unsigned JUMP{8};
const unsigned REVERSE{16};

namespace secret_handshake {

std::vector<std::string> commands(const unsigned code) {
    std::vector<std::string> actions;
    if (code & WINK) {
        actions.push_back("wink");
    }
    if (code & DOUBLE_BLINK) {
        actions.push_back("double blink");
    }
    if (code & CLOSE_EYES) {
        actions.push_back("close your eyes");
    }
    if (code & JUMP) {
        actions.push_back("jump");
    }
    if (code & REVERSE) {
        std::reverse(actions.begin(), actions.end());
    }
    return actions;
}

}  // namespace secret_handshake
