#pragma once
#include "Paddle.h"
#include "ball.h"
#include <string>
#include <raylib.h>
#include <assert.h>
#include <mutex>
#include <memory>

using namespace std;

class Game
{
public:

    Game(int screenWidth, int screenHeight);
    ~Game();
    bool Close();
    void Play();
    std::mutex mtx;
    const char* Tittle = "Pong";

private:

    bool start;
    string leftScore, rightScore;
    Ball ball;
    Paddle leftPaddle, rightPaddle;
    const char* winnerMassage;

    void Draw();
    void Update();
    void UpdateKey();
};