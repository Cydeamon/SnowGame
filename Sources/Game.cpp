#include "Game.h"

Game::Game(RenderHandler *renderHandler)
{
    this->renderHandler = renderHandler;
    player = new Player();

    Vector2 playerCenteredPos;
    playerCenteredPos.x = renderHandler->GetGameWidth() / 2 - player->GetPlayerTexture().width;
    playerCenteredPos.y = renderHandler->GetGameHeight() / 2 - player->GetPlayerTexture().height;
    player->SetPosition(playerCenteredPos);

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
    DrawTexture(backgroundTexture, renderHandler->GetGameWidth() / 2 - backgroundTexture.width / 2, 0, WHITE);
    player->Draw();
}