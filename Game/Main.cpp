#include "raylib.h"
#include "Game.h"

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    //SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(screenWidth, screenHeight, "Election Simulator 270");
    //ToggleFullscreen();

    SetTargetFPS(60);

    // Create Game Instance
    Game* game = new Game();

    game->gameState = IN_MAIN_MENU;

    while (!WindowShouldClose())
    {
        switch (game->gameState)
        {
        case IN_MAIN_MENU:
            // Update
            game->UpdateMenu();
            // Render
            BeginDrawing();
            ClearBackground(SKYBLUE);
            game->RenderMenu();
            EndDrawing();
            break;
        case IN_GAME:
            // Update
            game->Update();
            // Render
            BeginDrawing();
            ClearBackground(SKYBLUE);
            game->Render();
            EndDrawing();
            break;
        case IN_RESULTS:

            break;
        default:

            break;
        }
        

        
    }
    CloseWindow();

    delete(game);

    return 0;
}