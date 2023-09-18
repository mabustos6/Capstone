#include"ball.h"

void Ball::Getspeed(int x_speed, int y_speed)
{
    ballSpeed_X = x_speed;
    ballSpeed_Y = y_speed;
}

void Ball::Draw()
{
    DrawCircle((int)x, (int)y, radius, DARKPURPLE);//creating circle(X,Y,Radius, Color)
}

Ball::Ball()
{
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    radius = 15;
    ballSpeed_X = 400;
    ballSpeed_Y = 400;
}
void Ball::initBall(int x_speed, int y_speed, int radius)
{
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    this->radius = radius;
    ballSpeed_X = x_speed;
    ballSpeed_Y = y_speed;
}
