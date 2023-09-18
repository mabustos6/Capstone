#pragma once
#include <raylib.h>
#include <string>
#include <memory>

class Paddle
{

public:
	float x;
	float y;
	float speed;
	float width;
	float height;
	int score;

	Paddle();
	int UpScore();
	void position(float x, float y);
	Rectangle GetRect();
	void Draw(Color c);
};