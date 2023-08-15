#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define macros
#define NUMBER_SIZE 10
#define NUMBER_COUNT 100 // Read maximum 99 numbers (1 byte for null terminator)
#define GET_ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

int main() {
    // Allocate to heap
    int size = NUMBER_SIZE * sizeof(int);
    int* numbers = (int*)malloc(size);
    if(!numbers) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Handle input of numbers
    // Input is stored on the stack (memory automaticly allocated and deallocated)
    char input[NUMBER_COUNT];
    printf("Type in some numbers (seperate with space): ");
    // Input array decays to a pointer
    fgets(input, NUMBER_COUNT, stdin);
    printf("You typed: %s\n", input);

    // Handle converting of string to int, and add to array
    char *token = strtok(input, " ");
    int i = 0;
    while(token) {
        //Reallocate memory if necessary
        if(i == NUMBER_SIZE) {
            size *= 2;
            int *newSize = (int*) realloc(numbers, size);
            if(!newSize) {
                printf("Error when reallocating memory!");
                free(numbers);
                return 1;
            }

            numbers = newSize;
        }
        numbers[i] = atoi(token); 

        // Get token ready for next iteration
        token =strtok(NULL, " ");
        i++;
    }

    // Print numbers from array
    for(int j=0; j < i; j++) {
        printf("Current number: %d\n", numbers[j]);
    }

    free(numbers);
    return 0;
}