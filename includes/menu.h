#ifndef MENU_H
#define MENU_H

#include "constants.h"

// Enumera��o para os estados do menu
typedef enum {
    PLAY_STATE,
    LEADERBOARD_STATE,
    EXIT_STATE
} MenuStateEnum;

// Defini��o da estrutura Menu
typedef struct {
    Texture2D menuTexture;
    float scale;
    MenuStateEnum menuState;
} Menu;

// Declara��o das fun��es do menu
void InitMenu(Menu *menu);
void UpdateMenu(Menu *menu);
void DrawMenu(const Menu *menu);
void UnloadMenu(Menu *menu);

#endif // MENU_H

