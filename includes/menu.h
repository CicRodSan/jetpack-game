#ifndef MENU_H
#define MENU_H

#include "constants.h"

// Enumeração para os estados do menu
typedef enum {
    PLAY_STATE,
    LEADERBOARD_STATE,
    EXIT_STATE
} MenuStateEnum;

// Definição da estrutura Menu
typedef struct {
    Texture2D menuTexture;
    float scale;
    MenuStateEnum menuState;
} Menu;

// Declaração das funções do menu
void InitMenu(Menu *menu);
void UpdateMenu(Menu *menu);
void DrawMenu(const Menu *menu);
void UnloadMenu(Menu *menu);

#endif // MENU_H

