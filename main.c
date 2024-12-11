#include "constants.h"
#include "game.h"

int main(void)
{
    // Inicializa a janela
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jogo 2D");
   
    GameState gameState;
    // Inicializa o estado do jogo
    InitGame(&gameState);

    SetTargetFPS(60);

    // Loop principal do jogo
    while (!WindowShouldClose() && gameState.currentState != GAME_OVER_STATE)
    {
        // Atualiza o estado do jogo
        UpdateGame(&gameState);

        // Desenha o estado atual do jogo
        BeginDrawing();
        ClearBackground(GetColor(0x052c46ff)); // Cor de fundo
        DrawGame(&gameState);
        EndDrawing();
    }

    // Descarrega os recursos carregados
    UnloadGame(&gameState); // Descarrega todos os recursos do jogo

    // Fecha a janela
    CloseWindow();

    return 0;
}
