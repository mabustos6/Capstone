#include"Paddle.h"

Paddle::Paddle()
{
	height = 100;
	width = 10;
	speed = 650;
	score = 0;
}

int Paddle::UpScore()
{
	score++;
	return score;
}

void Paddle::position(float x, float y)
{
	this->x = x;
	this->y = y;
}

Rectangle Paddle::GetRect()
{
	return Rectangle{ x - width / 2, y - height / 2, width, height };
}

void Paddle::Draw(Color c)
{
	DrawRectangleRec(GetRect(), c);
}