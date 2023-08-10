#include <math.h>
#include <stdio.h>
#include <string.h>
# define GET_VECTOR_SIZE(vector) (sizeof(vector) / sizeof(*vector))

double lengthVector(int vector[], int size);
char advancedSquareRoot(double number);

int main() {
    int vector[] = {8, 2, 4};
    printf("Length of vector %.1lf", lengthVector(vector, GET_VECTOR_SIZE(vector)));
    printf("\nSquare root of -4: %s", advancedSquareRoot(-4));

}

double lengthVector(int vector[], int sizeVector) {
    int sum = 0;
    for(int i=0; i<sizeVector; i++) {
        sum += pow(*(vector + i), 2);
    }
    return sqrt(sum);
}



