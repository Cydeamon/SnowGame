#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "RenderHandler.h"

class Game
{
private: 
    Player *player;
    Texture2D backgroundTexture;
    RenderHandler *renderHandler;

    void UnloadResources();

public: 
    Game(RenderHandler *renderHandler);
    ~Game();

    void GameLogic();
    void ProcessControls();
};

#endif