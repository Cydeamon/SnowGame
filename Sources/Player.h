#ifndef PLAYER_H
#define PLAYER_H


#include "raylib.h"
#include "raymath.h"
#include <iostream>

class Player
{
public: 
    enum PlayerState {DEFAULT, CATCHING};

private:
    PlayerState state = PlayerState::DEFAULT;

    Texture2D playerTexture;
    Texture2D playerCatchTexture;

    Vector2 catchZoneStart;
    Vector2 catchZoneEnd;
    
    Vector2 playerBoundariesStart;
    Vector2 playerBoundariesEnd;

    Vector2 position;
    Vector2 velocity;
    int moveSpeed = 4;
    int lerpFactor = 50;
    int snowFlakesCount = 0;

    float LerpValue(float goal, float current);

public:
    Player();
    ~Player();

    void SetPosition(Vector2 value)    { position = value; }
    void SetMoveSpeed(int value)       { moveSpeed = value; }
    void SetSnowFlakesCount(int value) { snowFlakesCount = value; }
    void SetState(PlayerState value)   { state = value; }

    Texture2D GetPlayerTexture() { return playerTexture; }
    Vector2 GetPosition()        { return position; }
    int GetMoveSpeed()           { return moveSpeed; }
    int GetSnowFlakesCount()     { return snowFlakesCount; }
    PlayerState GetState()       { return state; }

    void ResetSnowFlakesCount() { snowFlakesCount = 0; }
    void CollectSnowFlake()     { snowFlakesCount++; }
    void Move(Vector2 direction);
    void Draw();
    bool InCatchZone(Vector2 position);
    
};

#endif