package main

import (
	"fmt"
)

func main() {
	display()
}

// Function for displaying string functionality
func display() {
	var userInput string
	var userChoice int
	var run bool = true

	for run {
		fmt.Println("Enter a string (0 to exit program): ")
		fmt.Scan(&userInput)
		fmt.Println()

		if userInput == "0" {
			break
		}

		fmt.Println("1. Length of string")
		fmt.Println("2. Reverse string")
		fmt.Println("3. Check if palindrome")
		fmt.Print("Enter choice: ")
		fmt.Scan(&userChoice)

		choice(userChoice, &userInput)
		fmt.Println()
	}
}

// Determine which function to invoke, and return suiting result
func choice(userChoice int, userInput *string) {
	switch userChoice {
	case 1:
		fmt.Println("Length of string is: ", len(*userInput))

	case 2:
		fmt.Println("Reverse of string is: ", reverseString(userInput))
	case 3:
		fmt.Println("Is palindrome: ", isPalindrome(userInput))
	default:
		fmt.Println("Invalid choice")
	}
}

// Reverse the given string
func reverseString(userInput *string) string {
	var outputString []rune
	// Create a slice of the user input (used in the iteration)
	slice := []rune(*userInput)
	for i, _ := range slice {
		// Swap the current rune with the "nth - 1" rune
		var reversedValue rune = slice[int((len(slice)-1)-i)]
		outputString = append(outputString, reversedValue)
	}
	return string(outputString)
}

// Check if given string is palindrome
func isPalindrome(userInput *string) bool {
	var reversedString string = reverseString(userInput)
	if *userInput == reversedString {
		return true
	} else {
		return false
	}
}
