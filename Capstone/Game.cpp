#include "Game.h"

Game::~Game()
{
    CloseWindow();
}

bool Game::Close()
{
    return WindowShouldClose();
}

Game::Game(int screenWidth, int screenHeight)
{
    auto &title = Game::Tittle = "Pong";
    InitWindow(screenWidth, screenHeight, title);
    SetWindowState(FLAG_VSYNC_HINT);
    ball.initBall(500, 500, 15);
    leftPaddle.position(50, GetScreenHeight() / 2);
    leftScore = '0';
    rightPaddle.position(GetScreenWidth() - 50, GetScreenHeight() / 2);
    rightScore = '0';
    winnerMassage = nullptr;
    start = false;
}

void Game::Play()
{
    BeginDrawing();
    Update();
    Draw();
    UpdateKey();
    EndDrawing();
}

void Game::Draw()
{
    ClearBackground(WHITE);
    ball.Draw();
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), BLACK);
    DrawFPS(70, 10);
    leftPaddle.Draw(RED);
    rightPaddle.Draw(DARKGREEN);
    DrawText(leftScore.c_str(), GetScreenWidth() / 2 - 80, GetScreenHeight() - 650, 60, RED);
    DrawText(rightScore.c_str(), GetScreenWidth() / 2 + 50, GetScreenHeight() - 650, 60, DARKGREEN);
}

void Game::Update()
{
    if (start == false)
    {   
        std::lock_guard<std::mutex> lck(mtx);
        std::string strText = ("Press Space to Begin");
        const char* Text = strText.c_str();

        int width = MeasureText( Text, 60);

        DrawText(Text, GetScreenWidth() / 2 - width / 2, GetScreenHeight() / 2 + 100, 60, DARKPURPLE);

        if (IsKeyPressed(KEY_SPACE))
        {
            ball.x += ball.ballSpeed_X * GetFrameTime();
            ball.y += ball.ballSpeed_Y * GetFrameTime();
            start = true;
        }
    }
    else
    {
        ball.x += ball.ballSpeed_X * GetFrameTime();
        ball.y += ball.ballSpeed_Y * GetFrameTime();

        if (ball.y < 0)
        {
            ball.y = 0;
            ball.ballSpeed_Y *= -1;
        }
        if (ball.y > GetScreenHeight())
        {
            ball.y = GetScreenHeight();
            ball.ballSpeed_Y *= -1;
        }

        //check collision circle rectangle "left paddle"
        if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, leftPaddle.GetRect()))
        {
            if (ball.ballSpeed_X < 0)
            {
                ball.ballSpeed_X *= -1.1f;
            }
        }

        //check collision circle rectangle "right paddle"
        if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, rightPaddle.GetRect()))
        {
            if (ball.ballSpeed_X > 0)
            {
                ball.ballSpeed_X *= -1.1f;
            }
        }

        //winner massage 
        if (ball.x < 0)
        {
            winnerMassage = "Green Player Wins";
        }

        if (ball.x > GetScreenWidth())
        {
            winnerMassage = "Red Player Wins";
        }

        if (winnerMassage && IsKeyPressed(KEY_SPACE))
        {
            if (ball.x < 0)
            {
                rightScore = to_string(rightPaddle.UpScore());
                ball.Getspeed(400, 400);
            }

            if (ball.x > GetScreenWidth())
            {
                leftScore = to_string(leftPaddle.UpScore());
                ball.Getspeed(-1 * 400, 400);
            }

            ball.x = GetScreenWidth() / 2.0f;
            ball.y = GetScreenHeight() / 2.0f;

            leftPaddle.y = GetScreenHeight() / 2;
            rightPaddle.y = GetScreenHeight() / 2;

            winnerMassage = nullptr;

        }
        if (winnerMassage == "Red Player Wins")
        {
            int widthText = MeasureText(winnerMassage, 60);
            DrawText(winnerMassage, GetScreenWidth() / 2 - widthText / 2, GetScreenHeight() / 2 - 30, 60, RED);
        }
        if (winnerMassage == "Green Player Wins")
        {
            int widthText = MeasureText(winnerMassage, 60);
            DrawText(winnerMassage, GetScreenWidth() / 2 - widthText / 2, GetScreenHeight() / 2 - 30, 60, DARKGREEN);
        }
    }

}

void Game::UpdateKey()
{
    if (IsKeyDown(KEY_W))
    {
        if (leftPaddle.y > 50) {
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }
    }
    if (IsKeyDown(KEY_S))
    {
        if (leftPaddle.y < GetScreenHeight() - 55)
        {
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }
    }

    if (IsKeyDown(KEY_UP))
    {
        if (rightPaddle.y > 55)
        {
            rightPaddle.y -= rightPaddle.speed * GetFrameTime();
        }
    }

    if (IsKeyDown(KEY_DOWN))
    {
        if (rightPaddle.y < GetScreenHeight() - 55)
        {
            rightPaddle.y += rightPaddle.speed * GetFrameTime();
        }
    }
}