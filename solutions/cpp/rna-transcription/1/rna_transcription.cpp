#include "rna_transcription.h"

#include <map>

const std::map<char, char> dna_rna = {{'G', 'C'}, {'C', 'G'}, {'T', 'A'}, {'A', 'U'}};

namespace rna_transcription {

char to_rna(const char c) {
    return dna_rna.at(c);
}

std::string to_rna(const std::string& strand) {
    std::string rna;
    for (const auto c : strand) {
        rna += dna_rna.at(c);
    }
    return rna;
}
}  // namespace rna_transcription
