package main

import (
	"fmt"
)

/*
	This program features a simple ticket seller, which returns the price of a ticket based on given age
*/

func main() {
	display()
}

func display() {
	var age int
	fmt.Println("Enter your age: ")
	fmt.Scan(&age)

	// Invoke function to calculate ticket price
	price := getTicketPrice(age)
	fmt.Println("Ticket price is: ", price)
}

func getTicketPrice(age int) int {
	if age <= 6 {
		return 0
	} else if age <= 18 {
		return 100
	} else if age <= 60 {
		return 200
	} else if age > 60 && age <= 100 {
		return 0
	} else {
		return -1
	}
}
