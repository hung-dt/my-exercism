#include "protein_translation.h"

#include <map>

const std::map<std::string, std::string> codonTable = {
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"},
    {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"},
    {"UUG", "Leucine"},
    {"UCU", "Serine"},
    {"UCC", "Serine"},
    {"UCA", "Serine"},
    {"UCG", "Serine"},
    {"UAU", "Tyrosine"},
    {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"},
    {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"},
    {"UAG", "STOP"},
    {"UGA", "STOP"}
};

namespace protein_translation {

std::vector<std::string> proteins(const std::string& rna) {
    std::vector<std::string> p;

    for (auto i = 0u; i < rna.size(); i += 3) {
        const auto codon = rna.substr(i, 3);
        const auto it = codonTable.find(codon);
        if (it != codonTable.end()) {
            if (it->second == "STOP") break;
            p.push_back(it->second);
        }
    }

    return p;
}

}  // namespace protein_translation
