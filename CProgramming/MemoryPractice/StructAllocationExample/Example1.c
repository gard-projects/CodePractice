#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int age;
    char name[50];
}Person;

// Declare functions
Person* createPerson(int age, char* name);
void deletePerson(Person* person);
void printPerson(Person* person);

int main() {
    // Get some input
    int age;
    char name[50];
    printf("Input name and age respectively (seperated by space): ");
    scanf("%s %d", name, &age);

    // Create and store instance
    Person *person1 = createPerson(age, name);
    printPerson(person1);
    deletePerson(person1);
    return 0;
}

// Define function bodies
Person* createPerson(int age, char* name) {
    // Create Person instance
    Person *person = (Person*)malloc(10 * sizeof(Person));
    if(!person) {
        printf("Memory allocation failed!");
        return NULL;
    }
    person->age = age;
    strcpy(person->name, name);
    return person;
}

void deletePerson(Person* person) {
    free(person);
    printf("Successfully deallocated memory of Person instance!");
    return;
}

void printPerson(Person* person) {
    printf("\n");
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("\n");
    return;
}

