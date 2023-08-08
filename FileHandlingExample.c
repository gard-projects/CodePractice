#include <stdio.h>
#include <string.h>

/*

*/
int getMenuChoice();
void addStudent(FILE *file);
void createStudent(FILE *file, char* name, int age, int studentId, char* courses);


// Structure (similar to a class in Java)
struct Student {
    char name[50];
    int age;
    int studentId;
    char courses[50];
};

int main() {
    // File handling
    FILE *file;
    

    // Menu system
    int option;
    do {
        option = getMenuChoice();
        switch(option) {
             case 0:
                printf("Exiting menu..\n");
                break;
            case 1:
                file = fopen("./generated/example_file.txt", "a");
                addStudent(file);
                fclose(file);
                break;
            case 2:
                file = fopen("./generated/example_file.txt", "r");
                char text[100];
                while(fgets(text, sizeof(text), file)) {
                    printf("%s", text);
                }
                fclose(file);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }  while(option != 0);
}


int getMenuChoice() {
    int option;
    printf("\n");
    printf("0 - Exit\n");
    printf("1 - Add a new student\n");
    printf("2 - List all students\n");
    printf("\nChoice: ");
    scanf("%d", &option);
    return option;
}
void addStudent(FILE *file) {
    char name[50];
    int age;
    int studentId;
    char courses[50];
    char resetBuffer;

    printf("\nEnter student name:\t");
    fflush(stdin);
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove any "\n" from the string

    printf("\nEnter student age:\t");
    fflush(stdin);
    scanf("%d", &age);
    while((resetBuffer = getchar()) != '\n' && resetBuffer != EOF); // Clear the buffer (stdin

    printf("\nEnter student id:\t");
    fflush(stdin);
    scanf("%d", &studentId);
    while((resetBuffer = getchar()) != '\n' && resetBuffer != EOF); // Clear the buffer (stdin

    printf("\nEnter student courses:\t");
    fflush(stdin);
    fgets(courses, sizeof(courses), stdin);

    // create the structure
    createStudent(file, name, age, studentId, courses);
}
void createStudent(FILE *file, char* name, int age, int studentId, char* courses) {
    struct Student student;
    strncpy(student.name, name, 50);
    student.age = age;
    student.studentId = studentId;
    strncpy(student.courses, courses, 50);
    printf("Student created!\n");
    
    // Add the student to the file
    fprintf(file, "%s,%d,%d,%s", student.name, student.age, student.studentId, student.courses);
}
