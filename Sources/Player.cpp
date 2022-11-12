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
    velocity.x = LerpValue(direction.x * moveSpeed, velocity.x);
    velocity.y = LerpValue(direction.y * moveSpeed, velocity.y);
    
    position.x += velocity.x;
    position.y += velocity.y;
}

float Player::LerpValue(float goal, float current)
{
    float delta = GetFrameTime() * lerpFactor;
    float difference = goal - current;

    if (difference > delta)
        return current + delta;
    
    if (difference < -delta)
        return current - delta;

    return goal;
}