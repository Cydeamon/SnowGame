#include "Game.h"
#include <iostream>


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GAME LOGIC

void Game::GameLogic()
{
    DrawTexture(backgroundTexture, renderHandler->GetGameWidth() / 2 - backgroundTexture.width / 2, 0, WHITE);
    ProcessControls();
    ProcessSnowFall();

    if (gameStarted) {
        player->Draw();
        char snowflakesString[25];
        DrawTexture(foregroundTexture, renderHandler->GetGameWidth() / 2 - foregroundTexture.width / 2, 0, WHITE);
        sprintf(snowflakesString, "Snow flakes catched: %d", player->GetSnowFlakesCount());
        DrawText(snowflakesString, 5, 165, 12, BLUE);
    } else {
        DrawTexture(startGameTexture, renderHandler->GetGameWidth() / 2 - startGameTexture.width / 2, 0, WHITE);
    }

    DrawSnowFall();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OTHER STUFF

Game::Game(RenderHandler *renderHandler)
{
    // Init render handler
    this->renderHandler = renderHandler;

    // Init player
    player = new Player();

    Vector2 playerCenteredPos;
    playerCenteredPos.x = renderHandler->GetGameWidth() / 2 - player->GetPlayerTexture().width / 2;
    playerCenteredPos.y = renderHandler->GetGameHeight() / 2 - player->GetPlayerTexture().height / 2;
    player->SetPosition(playerCenteredPos);

    // Init textures
    backgroundTexture = LoadTexture("../Assets/Sprites/BG.png");
    foregroundTexture = LoadTexture("../Assets/Sprites/FG.png");
    startGameTexture = LoadTexture("../Assets/Sprites/StartScreen.png");

    // Init snow
    for (int i = 0; i < snowAmount; i++)
    {
        Snow* snowFlake = new Snow(
            rand() % renderHandler->GetGameWidth(),
            rand() % renderHandler->GetGameHeight(),
            rand() % 3 + 0.5
        );
        
        snow.push_back(snowFlake);
    }
}

Game::~Game()
{
    delete player;
    UnloadResources();
}

void Game::ProcessSnowFall()
{
    for (Snow* snowFlake : snow)
    {
        if (player->InCatchZone(snowFlake->GetPosition()) && 
            player->GetState() == Player::PlayerState::CATCHING)
        {
            player->CollectSnowFlake();
            
            Vector2 pos = snowFlake->GetPosition();
            pos.y = -10;
            snowFlake->SetPosition(pos);
        }
        else
        {
            snowFlake->Move();            

            if (snowFlake->GetPosition().y > renderHandler->GetGameHeight())
            {
                Vector2 pos = snowFlake->GetPosition();
                pos.y = -10;
                snowFlake->SetPosition(pos);
            }
        }
    }
}

void Game::DrawSnowFall()
{
    for (Snow* snowFlake : snow)
        snowFlake->Draw();
}


void Game::UnloadResources()
{
    UnloadTexture(backgroundTexture);
    UnloadTexture(foregroundTexture);

    for (Snow* snowFlake : snow)
        delete snowFlake;
}

void Game::ProcessControls()
{
    // Movement    
    Vector2 direction = {0, 0};

    if (IsKeyDown(KEY_LEFT))
        direction.x -= 1;

    if (IsKeyDown(KEY_RIGHT))
        direction.x += 1;

    if (IsKeyDown(KEY_UP))
        direction.y -= 1;

    if (IsKeyDown(KEY_DOWN))
        direction.y += 1;

    if (IsKeyDown(KEY_ENTER))
        gameStarted = true;

    player->SetState(IsKeyDown(KEY_SPACE) ? Player::PlayerState::CATCHING : Player::PlayerState::DEFAULT);
    player->Move(Vector2Normalize(direction));
}