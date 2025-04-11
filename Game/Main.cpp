#include "raylib.h"
#include "Game.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Election Simulator 270");

    SetTargetFPS(60);

    // Create Game Instance
    Game* game = new Game();

    while (!WindowShouldClose())
    {
        // Update
        game->Update();

        // Render
        BeginDrawing();
        ClearBackground(SKYBLUE);
        game->Render();
        EndDrawing();
    }
    CloseWindow();

    delete(game);

    return 0;
}