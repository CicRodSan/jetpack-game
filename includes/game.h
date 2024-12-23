#ifndef GAME_H
#define GAME_H
#include "constants.h"
#include "menu.h"
#include "background.h"

// Enumera��o para os estados do jogo
typedef enum {
    INIT_STATE,       // Estado do menu principal
    PLAYING_STATE, // Estado de jogo em andamento
    GAME_OVER_STATE // Estado de fim de jogo// Estado de fim de jogo
} GameStateEnum;

// Defini��o da estrutura GameState
typedef struct {
    Menu menu;
    BACKGROUND bg;
    GameStateEnum currentState; 
} GameState;


// Declara��o das fun��es
void InitGame(GameState *gameState);
void UpdateGame(GameState *gameState);
void DrawGame(const GameState *gameState);
void UnloadGame(GameState *gameState);

#endif // GAME_H
