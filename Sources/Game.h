#ifndef GAME_H
#define GAME_H

#include <list>
#include <iostream>
#include "GameObjects/Snow.h"
#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "RenderHandler.h"
using namespace std;

class Game
{
private: 
    Texture2D backgroundTexture;
    Texture2D foregroundTexture;
    Texture2D startGameTexture;
    Player *player;
    RenderHandler *renderHandler;
    list<Snow*> snow;
    int snowAmount = 100;
    bool gameStarted = false;

    void UnloadResources();
    void ProcessControls();
    void ProcessSnowFall();
    void DrawSnowFall();

public: 
    Game(RenderHandler *renderHandler);
    ~Game();

    void GameLogic();
};

#endif