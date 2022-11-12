#ifndef RENDERHANDLER_H
#define RENDERHANDLER_H

#include "raylib.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

class RenderHandler
{
private:   
    bool isBorderlessFullscreen = false;
    int gameWidth = 426;
    int gameHeight = 240;
    int windowedDefaultWidth;
    int windowedDefaultHeight;
    RenderTexture2D target;

public:
    RenderHandler();    
    void Init();

    bool IsBorderlessFullscreen()      { return isBorderlessFullscreen; }
    int GetGameWidth()                 { return gameWidth;              }
    int GetGameHeight()                { return gameHeight;             }
    int GetWindowedDefaultWidth()      { return windowedDefaultWidth;   }
    int GetWindowedDefaultHeight()     { return windowedDefaultHeight;  }
    RenderTexture2D GetTargetTexture() { return target;                 }

    float GetGameScreenScale();
    int GetWindowedCenteredPositionX();
    int GetWindowedCenteredPositionY();

    void ToggleBorderlessFullscreen();
    void RenderScaledFrame();
};

#endif