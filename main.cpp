#include <raylib.h>
#include "game.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    const int winHeight = 920;
    const int winWidth = 725;
    InitWindow(winWidth, winHeight, "Tetris Game");
    SetTargetFPS(60);
    Font font = LoadFontEx("../assets/fonts/PressStart2P-Regular.ttf", 32, 0, 0);
    Game obj;
    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(obj.music);
        obj.HandleInput();
        if (EventTriggered(0.2))
        {
            obj.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(font, "Score", {520, 75}, 48, 2, WHITE);
        DrawTextEx(font, "Next", {535, 280}, 48, 2, WHITE);
        if (obj.gameOver)
        {
            DrawTextEx(font, "Game Over", {475, 620}, 48, 2, WHITE);
        }

        DrawRectangleRounded({500, 130, 175, 60}, 0.3, 6, GRAY);
        char scoreText[10];
        sprintf(scoreText, "%d", obj.score);
        Vector2 textsize = MeasureTextEx(font, scoreText, 48, 2);
        DrawTextEx(font, scoreText, {500 + (150 - textsize.x) / 2, 135}, 48, 2, WHITE);

        DrawRectangleRounded({500, 335, 175, 190}, 0.3, 6, GRAY);
        obj.Draw();
        EndDrawing();
    }
    CloseWindow();
}