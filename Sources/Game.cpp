#include "Game.h"
#include "iostream"

Game::Game(RenderHandler *renderHandler)
{
    this->renderHandler = renderHandler;
    player = new Player();
    backgroundTexture = LoadTexture("../Assets/Sprites/BG.png");
}

Game::~Game()
{
    delete player;
    UnloadResources();
}

void Game::UnloadResources()
{
    UnloadTexture(backgroundTexture);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GAME LOGIC

void Game::GameLogic()
{
    std::cout << "Do some stuff" << std::endl;
    DrawTexture(backgroundTexture, renderHandler->GetGameWidth() / 2 - backgroundTexture.width / 2, 0, WHITE);
}