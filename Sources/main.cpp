#include <iostream>
#include "raylib.h"
using namespace std;

int main()
{    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hello, world!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Hello, world!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}