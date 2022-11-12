#include "Player.h"

Player::Player()
{
    playerTexture = LoadTexture("../Assets/Sprites/Player.Idle.png");
}

Player::~Player()
{
    UnloadTexture(playerTexture);
}

void Player::Draw()
{
    DrawTexture(playerTexture, position.x, position.y, WHITE);
}