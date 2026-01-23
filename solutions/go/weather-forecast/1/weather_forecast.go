// Package weather provides tools to forecast the current weather condition of various cities.
package weather

var (
    // CurrentCondition represents current weather condition.
	CurrentCondition string

    // CurrentLocation represents current location.
	CurrentLocation  string
)

// Forecast returns a string that forecasts the current weather condition in a city.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
