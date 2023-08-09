package main

import (
	"fmt"
)

/*
 This program features a simple calculator, with basic operations.
*/

func main() {
	display()
}

// Get user input
func display() {
	var operation string
	var num1, num2 int

	fmt.Println("Enter operation, and two numbers:")
	fmt.Scan(&operation, &num1, &num2)

	// Do calculation and get result
	result := calculation(operation, num1, num2)
	fmt.Println("Answer: ", result)
}

func calculation(operation string, num1, num2 int) float32 {
	var result int
	switch operation {
	case "+":
		result = num1 + num2
	case "-":
		result = num1 - num2
	case "*":
		result = num1 * num2
	case "/":
		result = num1 / num2
	default:
		fmt.Println("Operation is not supported")
	}
	return float32(result)
}
