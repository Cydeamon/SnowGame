#include <iostream>
#include "raylib.h"
#include "RenderHandler.h"
using namespace std;

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

int main()
{
    RenderHandler renderHandler;
    InitWindow(renderHandler.GetGameWidth(), renderHandler.GetGameHeight(), "Catch snow");
    renderHandler.Init();
    
    SetTargetFPS(60);
    SetWindowMinSize(renderHandler.GetWindowedDefaultWidth(), renderHandler.GetWindowedDefaultHeight());
    SetWindowPosition(renderHandler.GetWindowedCenteredPositionX(), renderHandler.GetWindowedCenteredPositionY());

    Texture2D textureGameBackground = LoadTexture("../Assets/Sprites/BG.png");

    while (!WindowShouldClose())
    {
        // Toggle fullscreen
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER))
            renderHandler.ToggleBorderlessFullscreen();

        // Game logic
        BeginTextureMode(renderHandler.GetTargetTexture());
        ClearBackground(BLACK);  // Clear render texture background color
        DrawTexture(textureGameBackground, 0, 0, WHITE);
        EndTextureMode();

        // Draw scaled game frame
        renderHandler.RenderScaledFrame();
    }

    UnloadTexture(textureGameBackground);

    CloseWindow();
    return 0;
}