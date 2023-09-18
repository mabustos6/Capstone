#include"raylib.h"
#include"Game.h"

int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 700;

    Game game(screenWidth, screenHeight);

    while ( not game.Close())
    {
        game.Play();
    }
    return 0;
}