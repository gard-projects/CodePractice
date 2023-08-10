#include "raylib.h"

int main() {
    // Initialize screen properties
    const int screenHeight = 500;
    const int screenWidth = 1000;
    InitWindow(screenWidth, screenHeight, "Example Window");

    // Set the frames per second
    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose()) {
        BeginDrawing(); // Prepare drawing buffer
        ClearBackground(RED); // Sets the background color
        DrawText("This is my example window", 200, 200, 24, BLACK); // Draws some text

        EndDrawing(); // Presents everything to the screen
    }
    CloseWindow(); // Closes the window

    return 0;
}