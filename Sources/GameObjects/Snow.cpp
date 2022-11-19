#include "Snow.h"

Snow::Snow(int x, int y, float speed)
{
    subpixelPosition = Vector2Zero();
    position.x = x;
    position.y = y;
    this->speed = speed;
    texture = LoadTexture("../Assets/Sprites/SnowFlake.png");
    smallTexture = LoadTexture("../Assets/Sprites/SnowFlakeSmall.png");
}

Snow::~Snow()
{    
    UnloadTexture(texture);
}

void Snow::Move()
{
    // subpixelPosition.x += speed;
    subpixelPosition.y += speed;

    // position.x += (int) subpixelPosition.x;
    position.y += (int) subpixelPosition.y;

    // subpixelPosition.x -= (int) subpixelPosition.x;
    subpixelPosition.y -= (int) subpixelPosition.y;
}

void Snow::Draw()
{
    if (speed <= 1)
        DrawTexture(smallTexture, position.x, position.y, WHITE);
    else
        DrawTexture(texture, position.x, position.y, WHITE);
}
