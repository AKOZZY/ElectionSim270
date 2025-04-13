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
        switch (game->gameState)
        {
        case IN_MAIN_MENU:
            break;
        case IN_GAME:
            break;
        case IN_RESULTS:
            break;
        default:
            break;
        }
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