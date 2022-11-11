#include <iostream>
#include "raylib.h"
using namespace std;

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

int main()
{
    // Window init
    bool isBorderlessFullscreen = false;

    const int gameWidth = 416;
    const int gameHeight = 240;
    const int minGameWindowWidth = gameWidth;
    const int minGameWindowHeight = gameHeight;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(gameWidth, gameHeight, "Catch snow");

    const int windowedGameWindowDefaultWidth = GetMonitorWidth(GetCurrentMonitor()) / 1.5;
    const int windowedGameWindowDefaultHeight = GetMonitorHeight(GetCurrentMonitor()) / 1.5;

    SetTargetFPS(60);
    SetWindowMinSize(windowedGameWindowDefaultWidth, windowedGameWindowDefaultHeight);
    
    SetWindowPosition(
        GetMonitorWidth(GetCurrentMonitor()) / 2 - windowedGameWindowDefaultWidth / 2,
        GetMonitorHeight(GetCurrentMonitor()) / 2 - windowedGameWindowDefaultHeight / 2
    );

    RenderTexture2D target = LoadRenderTexture(gameWidth, gameHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);  // Texture scale filter to use

    // Prepare game stuff
    Texture2D textureGameBackground = LoadTexture("../Assets/Sprites/BG.png");

    while (!WindowShouldClose())
    {
        // Calculate game screen scale
        float scale = MIN(
            (float)GetScreenWidth()/gameWidth, 
            (float)GetScreenHeight()/gameHeight
        );

        // Toggle fullscreen
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER))
        {
            if (isBorderlessFullscreen)
            {                
                ClearWindowState(FLAG_WINDOW_TOPMOST);
                ClearWindowState(FLAG_WINDOW_UNDECORATED);

                SetWindowPosition(
                    GetMonitorWidth(GetCurrentMonitor()) / 2 - windowedGameWindowDefaultWidth / 2,
                    GetMonitorHeight(GetCurrentMonitor()) / 2 - windowedGameWindowDefaultHeight / 2
                );

                SetWindowSize(windowedGameWindowDefaultWidth, windowedGameWindowDefaultHeight);
            }
            else
            {                
                SetWindowState(FLAG_WINDOW_TOPMOST);
                SetWindowState(FLAG_WINDOW_UNDECORATED);

                SetWindowPosition(0,0);

                SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
            }
            
            isBorderlessFullscreen = !isBorderlessFullscreen;
        }

        // Drawing game frame in renderTexture
        BeginTextureMode(target);
        ClearBackground(BLACK);  // Clear render texture background color
        DrawTexture(textureGameBackground, 0, 0, WHITE);
        EndTextureMode();

        // Draw scaled game frame
        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawTexturePro(
            target.texture, 
            (Rectangle) { 
                0.0f, 
                0.0f, 
                (float) target.texture.width, 
                (float)-target.texture.height 
            },
            (Rectangle){ 
                (GetScreenWidth() - ((float)gameWidth*scale))*0.5f, 
                (GetScreenHeight() - ((float)gameHeight*scale))*0.5f,
                (float)gameWidth*scale, (float)gameHeight*scale 
            }, 
            (Vector2){ 0, 0 }, 
            0.0f, 
            WHITE
        );

        EndDrawing();
    }

    UnloadTexture(textureGameBackground);

    CloseWindow();
    return 0;
}