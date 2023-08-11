#include <raylib.h>
#include <stdio.h>
#include <math.h>

Vector2 constructRectangle();
Vector2 rotate(Vector2 rectangle);
void startGame(Vector2* rectangle);



int main() {
    // User input
    Vector2 rectangle = constructRectangle();
    startGame(&rectangle);
    return 0;
}

Vector2 constructRectangle() {
    float width;
    float height;
    printf("Enter the width and height of the rectangle: ");
    scanf("%f %f", &width, &height);
    printf("\n\n");

    return (Vector2){width, height};
}

// Applies a linear transformation to the vectors in the rectangle, rotation about 45 degrees counter-clockwise
Vector2 rotate(Vector2 rectangle) {
    const int ANGLE = 45;
    float rot_x = cos(45) * rectangle.x - sin(45) * rectangle.y;
    float rot_y = sin(45) * rectangle.x + cos(45) * rectangle.y;
    return (Vector2) {rot_x, rot_y};
}

void startGame(Vector2* rectangle) {
     // Initialize window
    const int screenHeight = 500;
    const int screenWidth = 1000;
    InitWindow(screenWidth, screenHeight, "Rotate Cube");
    SetTargetFPS(60);

    Vector2 position = {screenWidth / 2, screenHeight / 2}; // start position

    while(!WindowShouldClose()) {
        // Rotate cube (45 degrees)
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            position = rotate(*rectangle);
        }

        BeginDrawing();
        DrawRectangleV(position, *rectangle, RED);
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
}