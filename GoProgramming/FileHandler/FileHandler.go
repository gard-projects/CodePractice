package main

import (
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"strconv"
)

var weatherData []*Weather

// Define a struct
type Weather struct {
	location string
	date     string
	maxTemp  float32
	minTemp  float32
	isSunny  bool
	isRainy  bool
}

/*
 This program reads a csv file and stores the data in a struct.
 - The program then displays the data in the struct.
 - The program also has a menu that allows the user to display all data or data for a specific date.
*/

func main() {
	menu()
}

func menu() {
	// Input of file to read
	var namespace string = "./files/"

	fmt.Println("Enter filename: ")
	var input string
	fmt.Scan(&input)

	// Handle potential errors when opening file
	location := namespace + input
	file, err := os.Open(location)
	if err != nil {
		if os.IsNotExist(err) {
			fmt.Println("File does not exist!")
			return
		} else {
			fmt.Println("Error: ", err)
			return
		}
	} else {
		readFile(file)
	}

	// Menu stuff...
	var choice int
	fmt.Println("1. List all weather data")
	fmt.Println("2. List all weather data for a specific location")
	fmt.Println("3. List all weather data for a specific date\n")
	fmt.Print("Enter choice: ")
	fmt.Scan(&choice)
	menuChoice(choice)
}

func readFile(file *os.File) {
	// Close file when function ends
	defer file.Close()

	r := csv.NewReader(file)
	// Skip first line (header)
	r.Read()

	// Read file line by line, assign values to struct and print
	var bools []bool
	var floats []float32

	for {
		line, err := r.Read()
		if err == io.EOF {
			fmt.Println("Successfully read file!")
			break
		} else if err != nil {
			fmt.Println("Error: ", err)
			break
		}

		// Cast string to types bool and float32
		floats = convertToFloat32(line[2], line[3])
		bools = convertToBool(line[4], line[5])
		// Create struct instance and append to slice
		currentStruct := createStructType(line[0], line[1], floats[0], floats[1], bools[0], bools[1])
		weatherData = append(weatherData, currentStruct)
	}
}

func menuChoice(choice int) {
	switch choice {
	case 1:
		listAllData()
	case 2:
		fmt.Println("Enter date: ")
		var date string
		fmt.Scan(&date)
		listDateData(date)
	default:
		fmt.Println("Invalid choice!")
	}
}

func listAllData() {
	// List all structure instances in file
	for _, value := range weatherData {
		displayWeather(value)
	}
}

func listDateData(date string) {
	// value is a pointer to a Weather struct
	for _, value := range weatherData {
		if value.date == date {
			displayWeather(value)
		}
	}
}

func displayWeather(current *Weather) {
	// Display weather data
	fmt.Println("--------------------------------------------------")
	fmt.Println("Location: ", current.location, "\t")
	fmt.Println("Date: ", current.date, "\t")
	fmt.Println("Max Temp: ", current.maxTemp, "degrees", "\t")
	fmt.Println("Min Temp: ", current.minTemp, "degrees", "\t")
	fmt.Println("Was Sunny: ", current.isSunny, "\t")
	fmt.Println("Was Rainy: ", current.isRainy, "\t")
	fmt.Println("--------------------------------------------------")
	fmt.Println()
	fmt.Println()
}

func createStructType(location string, date string, maxTemp float32, minTemp float32, isSunny bool, isRainy bool) *Weather {
	// Create instance of Weather struct and return it
	return &Weather{
		location: location,
		date:     date,
		maxTemp:  maxTemp,
		minTemp:  minTemp,
		isSunny:  isSunny,
		isRainy:  isRainy,
	}
}

func convertToFloat32(input ...string) []float32 {
	// Convert string to float32
	var result []float32
	for _, value := range input {
		float, err := strconv.ParseFloat(value, 32)
		if err != nil {
			fmt.Println("Error: ", err)
		} else {
			result = append(result, float32(float))
		}
	}
	return result
}

func convertToBool(input ...string) []bool {
	// Convert string to bool
	var result []bool
	for _, value := range input {
		bool, err := strconv.ParseBool(value)
		if err != nil {
			fmt.Println("Error: ", err)
		} else {
			result = append(result, bool)
		}
	}
	return result
}
