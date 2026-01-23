#include <string>

namespace log_line {
std::string message(std::string line) {
    auto sepPos = line.find("]: ");
    if (sepPos != std::string::npos) {
        return line.substr(sepPos + 3);
    }
    return line;
}

std::string log_level(std::string line) {
    auto sepPos = line.find("]:");
    if (sepPos != std::string::npos) {
        return line.substr(1, sepPos - 1);
    }
    return line;
}

std::string reformat(std::string line) {
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
