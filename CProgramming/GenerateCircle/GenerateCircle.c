#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CIRCLES 100
#define GET_ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef struct {
    Vector2 position;
    float radius;
    Color color;
} Circle;

// Declare functions
Vector2 generateVector(int screenHeight, int screenWidth);
float generateRadius();
Color generateColor();


int main() {
    // Initialize window
    const int screenHeight = 500;
    const int screenWidth = 1000;
    InitWindow(screenWidth, screenHeight, "Generate Circle");
    SetTargetFPS(60);


    // Main function
    Circle circles[MAX_CIRCLES];
    int clicked = 0;
    while(!WindowShouldClose()) {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && clicked < MAX_CIRCLES) {
            circles[clicked].position = generateVector(screenHeight, screenWidth);
            circles[clicked].radius = generateRadius();
            circles[clicked].color = generateColor();
            clicked++;
        }


        BeginDrawing();
        ClearBackground(WHITE);
        for(int i=0; i < GET_ARRAY_SIZE(circles); i++) {
            DrawCircleV(circles[i].position, circles[i].radius, circles[i].color);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}


// Define functions
Vector2 generateVector(int screenHeight, int screenWidth) {
    int genX = rand() % (screenWidth + 1); // Generate a random number between 0 and 500
    int genY = rand() % (screenHeight + 1); // Generate a random number between 0 and 500
    return (Vector2){genX, genY};
}

float generateRadius() {
    float genRadius = rand() % 31;
    return genRadius;
}

Color generateColor() {
    return (Color) {
        // Generate a random number between 0 and 255 for each color channel
        rand() % 256, rand() % 256, rand() % 256, rand() % 256
    };
}
