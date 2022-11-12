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

void Player::Move(Vector2 direction)
{
    position.x += direction.x * moveSpeed * GetFrameTime();
    position.y += direction.y * moveSpeed * GetFrameTime();
}