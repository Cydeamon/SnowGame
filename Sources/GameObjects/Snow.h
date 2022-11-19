#include "raylib.h"
#include "raymath.h"

class Snow
{
private:
    Vector2 position;
    Vector2 subpixelPosition;
    float speed;
    Texture2D texture;
    Texture2D smallTexture;

public:
    Snow(int x, int y, float speed = 0.5);
    ~Snow();

    void Move();
    void Draw();

    void SetPosition(Vector2 position)                 { this->position = position;                 }
    void SetSpeed(float speed)                         { this->speed = speed;                       }
    void SetSubpixelPosition(Vector2 subpixelPosition) { this->subpixelPosition = subpixelPosition; }

    Vector2 GetPosition()         { return position;         }
    float GetSpeed()              { return speed;            }
    Vector2 GetSubpixelPosition() { return subpixelPosition; }
};