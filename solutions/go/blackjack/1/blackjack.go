package blackjack

// ParseCard returns the integer value of a card following blackjack ruleset.
func ParseCard(card string) int {
	switch card {
        case "ace": return 11
        case "two": return 2
        case "three": return 3
        case "four": return 4
        case "five": return 5
        case "six": return 6
        case "seven": return 7
        case "eight": return 8
        case "nine": return 9
        case "ten": return 10
        case "jack": return 10
        case "queen": return 10
        case "king": return 10
        default: return 0
    }
}

// FirstTurn returns the decision for the first turn, given two cards of the
// player and one card of the dealer.
func FirstTurn(card1, card2, dealerCard string) string {
	if card1 == "ace" && card2 == "ace" {
        return "P"
    }

    sum := ParseCard(card1) + ParseCard(card2)
    dealer := ParseCard(dealerCard)

    if sum == 21 {
        if dealer < 10 {
            return "W"
        }
        return "S"
    }

    if 17 <= sum && sum < 21 {
        return "S"
    }

    if 12 <= sum && sum < 17 {
        if dealer > 6 {
            return "H"
        }
        return "S"
    }

    return "H"
}
