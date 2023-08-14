#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define macros
#define MAX_STRING_LENGTH 10

int main() {
    // Create a pointer to a char with a memory size of 10 bytes
    size_t bufferSize = MAX_STRING_LENGTH * sizeof(char);
    char *buffer = (char *)malloc(bufferSize);
    if(!buffer) {
        printf("Error allocating memory!\n");
        free(buffer);
        return 1;
    }

    printf("Enter a string: ");
    fgets(buffer, bufferSize, stdin);

    // Remove the newline character (that fgets generates) from the string
    size_t length = strlen(buffer);
    if(length > 0 && buffer[length-1] == '\n') {
        buffer[length-1] = '\0';
    }


    /* Section: Using realloc() to increase memory size*/
    bufferSize *= 2;
    buffer = (char *)realloc(buffer, bufferSize);
    if(!buffer) {
        printf("Error reallocating memory!\n");
        free(buffer);
        return 1;
    }

    // Create a copy of the string to avoid undefined behaviour
    char *temp = strdup(buffer);
    if(!temp) {
        printf("Error allocating memory!\n");
        free(buffer);
        return 1;
    }

    // Append string to itself
    strcat(buffer, temp);
    free(temp);
    printf("String is now: %s\n", buffer);
    printf("Byte size: %zu\n", strlen(buffer));

    free(buffer);
    return 0;
}