#include <raylib.h>
#include <stdio.h>

void applyAcceleration(Vector2 *ballPosition, int directionKey);

/*
Simple program where a circle is drawn on the screen
Provided functionality:
- Circle can be controlled using the arrow keys
- Can also be controlled be using mouse (uncomment line 25)
- Circle can be accelerated by holding space and pressing the respective arrow key to accelerate in that direction
*/

int main() {
    // Initialize window
    const int screenHeight = 500;
    const int screenWidth = 1000;
    InitWindow(screenWidth, screenHeight, "Moving Circle");
    SetTargetFPS(60);

    // Create a two-dimensional vector (struct) representing ball's position (sets start-pos)
    Vector2 ballPosition = {screenWidth / 2, screenHeight / 2};

    while(!WindowShouldClose()) {
        // Update ball's position based on the mouse position
        // ballPosition = GetMousePosition();

        // Update ball's position based on the keyboard input
        if(IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if(IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if(IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if(IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

        // Apply acceleration to ball
        if(IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_RIGHT)) applyAcceleration(&ballPosition, KEY_RIGHT);
        if(IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_LEFT)) applyAcceleration(&ballPosition, KEY_LEFT);
        if(IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_UP)) applyAcceleration(&ballPosition, KEY_UP);
        if(IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_DOWN)) applyAcceleration(&ballPosition, KEY_DOWN);


        // Handle visual representation
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPosition, 50, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void applyAcceleration(Vector2 *ballPosition, int directionKey) {
    switch(directionKey) {
        case KEY_RIGHT:
            ballPosition->x += 10.0f;
            break;
        case KEY_LEFT:
            ballPosition->x -= 10.0f;
            break;
        case KEY_UP:
            ballPosition->y -= 10.0f;
            break;
        case KEY_DOWN:
            ballPosition->y += 10.0f;
            break;
    }

}
