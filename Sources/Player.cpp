#include "Player.h"

Player::Player()
{
    playerTexture = LoadTexture("../Assets/Sprites/Player.Idle.png");
    playerCatchTexture = LoadTexture("../Assets/Sprites/Player.Catching.png");
    
    catchZoneStart.x = 6;
    catchZoneStart.y = 15;    
    
    catchZoneEnd.x = 13;
    catchZoneEnd.y = 17;
}

Player::~Player()
{
    UnloadTexture(playerTexture);
    UnloadTexture(playerCatchTexture);
}

void Player::Draw()
{
    switch (state)
    {
        case PlayerState::DEFAULT:  DrawTexture(playerTexture,      position.x, position.y, WHITE); break;
        case PlayerState::CATCHING: DrawTexture(playerCatchTexture, position.x, position.y, WHITE); break;
    }
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

bool Player::InCatchZone(Vector2 position)
{
    Vector2 globalCatchZoneStart = Vector2Add(this->position, catchZoneStart);
    Vector2 globalCatchZoneEnd = Vector2Add(this->position, catchZoneEnd);

    bool inZone = globalCatchZoneStart.x <= position.x && globalCatchZoneEnd.x >= position.x && 
                  globalCatchZoneStart.y <= position.y && globalCatchZoneEnd.y >= position.y;

    return inZone;
}