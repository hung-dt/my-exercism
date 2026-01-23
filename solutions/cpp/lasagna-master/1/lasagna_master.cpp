#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(const std::vector<std::string>& layers, int avgTime) {
    return avgTime * layers.size();
}

amount quantities(const std::vector<std::string>& layers) {
    amount ret{ 0, 0 };

    for (const auto& layer: layers) {
        if (layer == "sauce") {
            ret.sauce += 0.2;
        }
        if (layer == "noodles") {
            ret.noodles += 50;
        }
    }

    return ret;
}

void addSecretIngredient(std::vector<std::string>& ingredients, const std::vector<std::string>& friendIngredients) {
    ingredients.back() = friendIngredients.back();
}

std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portions) {
    std::vector<double> newQuantities;
    for (const auto& q : quantities) {
        newQuantities.push_back(q * portions / 2);
    }
    return newQuantities;
}

void addSecretIngredient(std::vector<std::string>& ingredients, const std::string& offering) {
    ingredients.back() = offering;
}
}  // namespace lasagna_master
