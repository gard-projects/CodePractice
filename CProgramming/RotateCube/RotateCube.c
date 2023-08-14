#include <raylib.h>
#include <stdio.h>
#include <math.h>

// Declare functions


int main() {
    const int screenWidth = 1000;
    const int screenHeight = 500;
    InitWindow(screenWidth, screenHeight, "Rotate Cube");
    SetTargetFPS(60);

    Vector2 position = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 size = { 100.0f, 100.0f };
    Color color = RED;
    float rotationAngle = 0;

    while(!WindowShouldClose()) {
        // Rotate when key activated
        if(IsKeyPressed(KEY_R)) rotationAngle += 45.0f;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        Vector2 origin = { position.x / 2.0f, position.y / 2.0f };
        DrawRectanglePro((Rectangle){position.x, position.y, size.x, size.y}, origin, rotationAngle, color);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}