#include "constants.h"
#include "game.h"

void InitGame(GameState* gameState) {
    InitMenu(&gameState->menu);        // Inicializa o menu
    InitBackground(&gameState->bg);
}

void UpdateGame(GameState* gameState) {
    switch (gameState->currentState) {
    case INIT_STATE:
        UpdateMenu(&gameState->menu); // Atualiza o menu

        if (IsKeyPressed(KEY_ENTER)) {
            switch (gameState->menu.menuState) {
            case PLAY_STATE:
                gameState->currentState = PLAYING_STATE;
          
                break;
            case LEADERBOARD_STATE:
                // Código para exibir o leaderboard, se necessário
                break;
            case EXIT_STATE:
                CloseWindow(); // Fecha o jogo
                break;
            }
        }
        break;

    case PLAYING_STATE:
      UpdateBackground(&gameState->bg);
        break;

    case GAME_OVER_STATE:
       
        break;
    }
}

void DrawGame(const GameState* gameState) {
    switch (gameState->currentState) {
    case INIT_STATE:
        DrawMenu(&gameState->menu); // Desenha o menu
        break;
    case PLAYING_STATE:
        DrawBackground(&gameState->bg);
        break;
    case GAME_OVER_STATE:
        break;
    } 
}

void UnloadGame(GameState* gameState) {
    UnloadMenu(&gameState->menu);    // Libera os recursos do menu
    UnloadBackground(&gameState->bg);
}
