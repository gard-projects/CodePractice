#include <stdio.h>
#include <stdlib.h>

#define GET_ARRAY_LENGTH(array) (sizeof(array) / sizeof(*array))
#define MAX_STRING_LENGTH 10

int main() {
    // Dynamic memory allocation
    char *buffer;
    size_t bufferSize = MAX_STRING_LENGTH * sizeof(char);
    buffer = (char*) malloc(bufferSize);

    // Check if memory allocation was successful
    if(buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    printf("(1) Enter a string: ");
    fgets(buffer, (int)bufferSize, stdin);
    printf("You entered: %s\n", buffer);

    /*
    * Section: Use of realloc() to resize the buffer
    */
    printf("(2) Enter a new string: ");

    char ch; // Stored on stack (local memory)
    size_t length = 0;

    // Iterate through input and increase buffer size if needed
    // Notice we use "length + 1" to account for the null terminator
    while((ch = getchar()) != '\n') {
        printf("Current index: %d\n", (int)length);
        if(length + 1 >= bufferSize) {
            bufferSize *= 2;
            char *newBuffer = realloc(buffer, bufferSize);

            if(newBuffer == NULL) {
                printf("Error: Memory allocation failed.\n");
                free(buffer);
                return 1;
            }
            buffer = newBuffer; // Update buffer pointer
        }
        buffer[length] = ch;
        length++;
    }

    buffer[length] = '\0'; // Add null terminator
    printf("Resulting string: %s\n", buffer);
    free(buffer); // Free allocated memory
    
    return 0;
}