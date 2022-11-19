#include <iostream>
#include "raylib.h"

#include "Game.h"
#include "RenderHandler.h"

using namespace std;

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

int main()
{
    RenderHandler *renderHandler = new RenderHandler();
    InitWindow(renderHandler->GetGameWidth(), renderHandler->GetGameHeight(), "Catch snow");
    renderHandler->Init();    
    Game *game = new Game(renderHandler);
    
    SetTargetFPS(60);
    SetWindowMinSize(renderHandler->GetWindowedDefaultWidth(), renderHandler->GetWindowedDefaultHeight());
    SetWindowPosition(renderHandler->GetWindowedCenteredPositionX(), renderHandler->GetWindowedCenteredPositionY());
    renderHandler->ToggleBorderlessFullscreen();

    while (!WindowShouldClose())
    {
        // Toggle fullscreen
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER))
            renderHandler->ToggleBorderlessFullscreen();

        // Game logic
        BeginTextureMode(renderHandler->GetTargetTexture());
        ClearBackground(BLACK);  // Clear render texture background color        
        game->GameLogic();
        EndTextureMode();

        // Draw scaled game frame
        renderHandler->RenderScaledFrame();
    }

    delete game;

    CloseWindow();
    return 0;
}