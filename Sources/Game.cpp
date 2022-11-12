#include "Game.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GAME LOGIC

void Game::GameLogic()
{
    DrawTexture(backgroundTexture, renderHandler->GetGameWidth() / 2 - backgroundTexture.width / 2, 0, WHITE);
    ProcessControls();
    player->Draw();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OTHER STUFF

Game::Game(RenderHandler *renderHandler)
{
    this->renderHandler = renderHandler;
    player = new Player();

    Vector2 playerCenteredPos;
    playerCenteredPos.x = renderHandler->GetGameWidth() / 2 - player->GetPlayerTexture().width / 2;
    playerCenteredPos.y = renderHandler->GetGameHeight() / 2 - player->GetPlayerTexture().height / 2;
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

void Game::ProcessControls()
{
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN)) 
    {
        Vector2 direction = {0, 0};

        if (IsKeyDown(KEY_LEFT))
            direction.x -= 1;

        if (IsKeyDown(KEY_RIGHT))
            direction.x += 1;

        if (IsKeyDown(KEY_UP))
            direction.y -= 1;

        if (IsKeyDown(KEY_DOWN))
            direction.y += 1;

        player->Move(Vector2Normalize(direction));
    }
}
