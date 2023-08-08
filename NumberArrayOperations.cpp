// Import statement, provide packages
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// Macro for calculating the size of an array
#define GET_ARRAY_SIZE(array) (sizeof(array) / sizeof(*array))

/*
This program will display the following information about an array of numbers:
- The numbers in the array
- The sum of the numbers in the array
- The average of the numbers in the array
- The largest value in the array
- The smallest value in the array
*/

// Function declaration
void display(int *numbers, int size);
void printNumbers(int *numbers, int size);
double calculateSum(int *numbers, int size);
double calculateAverage(int *numbers, int size);
int findMax(int numbers[], int size);
int findMin(int numbers[], int size);


int main() {
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    display(numbers, GET_ARRAY_SIZE(numbers));
}

// Function definition
void display(int numbers[], int size) {
    printf("--------------------------------- Information ---------------------------------\n");
    printNumbers(numbers, size);
    printf("\nSum: %.1lf", calculateSum(numbers, size));
    printf("\nAverage: %.1lf", calculateAverage(numbers, size));
    printf("\nLargest value: %d", findMax(numbers, size));
    printf("\nSmallest value: %d", findMin(numbers, size));
    printf("\n-----------------------------------------------------------------------------\n");
}

void printNumbers(int *numbers, int size) {
    printf("Numbers: ");
    for(int i = 0; i < size; i++) {
        printf("%d\t", *(numbers + i));
    }
}

double calculateSum(int *numbers, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += *(numbers + i);
    }
    return (double)sum;
}

double calculateAverage(int *numbers, int size) {
    return calculateSum(numbers, size) / size;
}

int findMax(int numbers[], int size) {
    int max = *numbers;
    for(int i=0; i < size; i++) {
        if(*(numbers + i) >= max) {
            max = *(numbers + i);
        }
    }
    return max;
}

int findMin(int numbers[], int size) {
    int min = *numbers;
    for(int i=0; i < size; i++) {
        if((*numbers + i) <= min) {
            min = *(numbers + i);
        }
    }
    return min;
}