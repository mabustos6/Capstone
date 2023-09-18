#pragma once

#include "raylib.h"

class Ball
{
public:
    float x;
    float y;
    float radius;
    float ballSpeed_X;
    float ballSpeed_Y;
    Ball();
    void initBall(int x_speed, int y_speed, int radius);
    void Getspeed(int x_speed, int y_speed);
    void Draw();
};
