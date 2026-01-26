package lasagna

// TODO: define the 'PreparationTime()' function
func PreparationTime(layers []string, minutesPerLayer int) int {
    if minutesPerLayer == 0 {
        minutesPerLayer = 2
    }
    return len(layers) * minutesPerLayer
}

// TODO: define the 'Quantities()' function
func Quantities(layers []string) (int, float64) {
    noodles := 0
    sauce := 0.0

    for i := 0; i < len(layers); i++ {
        if layers[i] == "noodles" {
            noodles += 50
        }
        if layers[i] == "sauce" {
            sauce += 0.2
        }
    }

    return noodles, sauce
}

// TODO: define the 'AddSecretIngredient()' function
func AddSecretIngredient(friendList []string, yourList []string) {
    yourList[len(yourList) - 1] = friendList[len(friendList) - 1]
}

// TODO: define the 'ScaleRecipe()' function
func ScaleRecipe(amountsForTwo []float64, nPortions int) []float64 {
    var scaledAmounts = make([]float64, len(amountsForTwo))
    for i := 0; i < len(amountsForTwo); i++ {
        scaledAmounts[i] = amountsForTwo[i] / 2.0 * float64(nPortions)
    }
    return scaledAmounts
}

// Your first steps could be to read through the tasks, and create
// these functions with their correct parameter lists and return types.
// The function body only needs to contain `panic("")`.
//
// This will make the tests compile, but they will fail.
// You can then implement the function logic one by one and see
// an increasing number of tests passing as you implement more
// functionality.
