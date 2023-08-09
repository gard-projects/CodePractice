package main

import (
	"encoding/csv"
	"fmt"
	"io"
	"os"
)

// Define a struct
type Weather struct {
	Location string
	Date     string
	MaxTemp  float32
	MinTemp  float32
	IsSunny  bool
	IsRainy  bool
}

func main() {
	readFile("./files/sample.txt")
}

func readFile(inputFile string) {
	file, err := os.Open(inputFile)
	if err != nil {
		fmt.Println("Error: ", err)
	}
	defer file.Close()

	r := csv.NewReader(file)
	// Skip first line (header)
	r.Read()

	// Read file line by line, assign values to struct and print
	for {
		line, err := r.Read()
		if err != nil {
			fmt.Println("Error: ", err)
			break
		} else if err == io.EOF {
			break
		}

		createStructType(line[0], line[1], float32(line[2]), float32(line[3]), bool(line[4]), bool(line[5]))
	}
}

func createStructType(location string, date string, maxTemp float32, minTemp float32, isSunny bool, isRainy bool) Weather {
	// Create instance of Weather struct and return it
	return Weather{
		Location: location,
		Date:     date,
		MaxTemp:  maxTemp,
		MinTemp:  minTemp,
		IsSunny:  isSunny,
		IsRainy:  isRainy,
	}
}
