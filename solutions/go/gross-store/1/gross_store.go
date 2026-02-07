package gross

// Units stores the Gross Store unit measurements.
func Units() map[string]int {
	units := map[string]int{}
    units["quarter_of_a_dozen"] = 3
    units["half_of_a_dozen"] = 6
    units["dozen"] = 12
    units["small_gross"] = 120
    units["gross"] = 144
    units["great_gross"] = 1728
    return units
}

// NewBill creates a new bill.
func NewBill() map[string]int {
	return make(map[string]int)
}

// AddItem adds an item to customer bill.
func AddItem(bill, units map[string]int, item, unit string) bool {
    value, exists := Units()[unit]
    if !exists {
        return false
    }
    bill[item] += value
    return true
}

// RemoveItem removes an item from customer bill.
func RemoveItem(bill, units map[string]int, item, unit string) bool {
	bvalue, bexists := bill[item]
    if !bexists {
        return false
    }

    uvalue, uexists := units[unit]
    if !uexists {
        return false
    }

    bvalue -= uvalue
    if bvalue < 0 {
        return false
    }

    if bvalue == 0 {
        delete(bill, item)
    } else {
        bill[item] = bvalue
    }
    return true
}

// GetItem returns the quantity of an item that the customer has in his/her bill.
func GetItem(bill map[string]int, item string) (qty int, exists bool) {
	qty, exists = bill[item]
    return
}
