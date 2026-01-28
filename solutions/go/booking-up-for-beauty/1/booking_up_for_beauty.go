package booking

import "time"

// Schedule returns a time.Time from a string containing a date.
func Schedule(date string) time.Time {
	layout := "1/2/2006 15:04:05"
    t, _ := time.Parse(layout, date)
    return t
}

// HasPassed returns whether a date has passed.
func HasPassed(date string) bool {
    layout := "January 2, 2006 15:04:05"
    t, _ := time.Parse(layout, date)
	return t.Before(time.Now())
}

// IsAfternoonAppointment returns whether a time is in the afternoon.
func IsAfternoonAppointment(date string) bool {
	layout := "Monday, January 2, 2006 15:04:05"
    t, _ := time.Parse(layout, date)
    noon := time.Date(t.Year(), t.Month(), t.Day(), 12, 0, 0, 0, time.UTC)
    evening := time.Date(t.Year(), t.Month(), t.Day(), 18, 0, 0, 0, time.UTC)
    return (t.After(noon) || t.Equal(noon)) && t.Before(evening)
}

// Description returns a formatted string of the appointment time.
func Description(date string) string {
	t := Schedule(date)
    return "You have an appointment on " + t.Format("Monday, January 2, 2006, at 15:04.")
}

// AnniversaryDate returns a Time with this year's anniversary.
func AnniversaryDate() time.Time {
	return time.Date(time.Now().Year(), 9, 15, 0, 0, 0, 0, time.UTC)
}
