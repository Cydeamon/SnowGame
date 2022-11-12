#ifndef PLAYER_H
#define PLAYER_H


#include "raylib.h"

class Player
{
private: 
    Texture2D playerTexture;
    Vector2 position;
    int moveSpeed = 250;
    int snowFlakesCount = 0;

public:
    Player();
    ~Player();

    void SetPosition(Vector2 value)    { position = value; }
    void SetMoveSpeed(int value)       { moveSpeed = value; }
    void SetSnowFlakesCount(int value) { snowFlakesCount = value; }

    Texture2D GetPlayerTexture() { return playerTexture; }
    Vector2 GetPosition()        { return position; }
    int GetMoveSpeed()           { return moveSpeed; }
    int GetSnowFlakesCount()     { return snowFlakesCount; }

    void ResetSnowFlakesCount() { snowFlakesCount = 0; }
    void CollectSnowFlake()     { snowFlakesCount++; }
    
    void Move(Vector2 direction);
    void Draw();
};

#endif