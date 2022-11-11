#include "RenderHandler.h"

RenderHandler::RenderHandler()
{    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
}

void RenderHandler::Init()
{
    windowedDefaultWidth = GetMonitorWidth(GetCurrentMonitor()) / 1.5;
    windowedDefaultHeight = GetMonitorHeight(GetCurrentMonitor()) / 1.5;
    target = LoadRenderTexture(GetGameWidth(), GetGameHeight());
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
}

void RenderHandler::ToggleBorderlessFullscreen()
{
    if (isBorderlessFullscreen)
    {                
        ClearWindowState(FLAG_WINDOW_TOPMOST);
        ClearWindowState(FLAG_WINDOW_UNDECORATED);

        SetWindowPosition(GetWindowedCenteredPositionX(), GetWindowedCenteredPositionY());
        SetWindowSize(windowedDefaultWidth, windowedDefaultHeight);
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

int RenderHandler::GetWindowedCenteredPositionX()
{
    return GetMonitorWidth(GetCurrentMonitor()) / 2 - windowedDefaultWidth / 2;
}

int RenderHandler::GetWindowedCenteredPositionY()
{
    return GetMonitorHeight(GetCurrentMonitor()) / 2 - windowedDefaultHeight / 2;
}

float RenderHandler::GetGameScreenScale()
{
    return MIN((float)GetScreenWidth()/gameWidth, (float)GetScreenHeight()/gameHeight);
}

void RenderHandler::RenderScaledFrame()
{
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
            (GetScreenWidth() - ((float)gameWidth*GetGameScreenScale()))*0.5f, 
            (GetScreenHeight() - ((float)gameHeight*GetGameScreenScale()))*0.5f,
            (float) gameWidth * GetGameScreenScale(), (float) gameHeight * GetGameScreenScale() 
        }, 
        (Vector2){ 0, 0 }, 
        0.0f, 
        WHITE
    );

    EndDrawing();
}