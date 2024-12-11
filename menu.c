#include "constants.h"
#include "menu.h"

void InitMenu(Menu *menu) {
    menu->menuTexture = LoadTexture("/home/cicero/Documentos/TRAB-ALG/assets/menu.png"); // Carrega a imagem do menu
    menu->scale = 1.2f; // Define a escala
    menu->menuState = PLAY_STATE;
}

void UpdateMenu(Menu *menu) {
    if (IsKeyPressed(KEY_DOWN)) {
        menu->menuState = (menu->menuState + 1) % NUM_MENU_STATES;
    }
    if (IsKeyPressed(KEY_UP)) {
        menu->menuState = (menu->menuState - 1 + NUM_MENU_STATES) % NUM_MENU_STATES;
    }

    if (IsKeyPressed(KEY_ENTER)) {
        switch (menu->menuState) {
        case PLAY_STATE:
            // Código para iniciar o jogo
            break;
        case LEADERBOARD_STATE:
            // Código para exibir o leaderboard
            break;
        case EXIT_STATE:
            // Código para sair do jogo
            break;
        }
    }
}

void DrawMenu(const Menu *menu) {
    DrawTextureEx(menu->menuTexture, (Vector2) { 0, 0 }, 0.0f, menu->scale, WHITE);
    DrawText("Jetpack Cyberpunk", TITLE_X_POSITION, TITLE_Y_POSITION, TITLE_FONT_SIZE, RED);
    DrawText("Jogar", SCREEN_WIDTH / 2 - MeasureText("Jogar", MENU_FONT_SIZE) / 2, SCREEN_HEIGHT / 2 - OPTION_Y_OFFSET, MENU_FONT_SIZE,menu->menuState == PLAY_STATE ? SELECTED_COLOR : UNSELECTED_COLOR);
    DrawText("LeaderBoard", SCREEN_WIDTH / 2 - MeasureText("LeaderBoard", MENU_FONT_SIZE) / 2, SCREEN_HEIGHT / 2, MENU_FONT_SIZE, menu->menuState == LEADERBOARD_STATE ? SELECTED_COLOR : UNSELECTED_COLOR);
    DrawText("Sair", SCREEN_WIDTH / 2 - MeasureText("Sair", MENU_FONT_SIZE) / 2, SCREEN_HEIGHT / 2 + OPTION_Y_OFFSET, MENU_FONT_SIZE,menu->menuState == EXIT_STATE ? SELECTED_COLOR : UNSELECTED_COLOR);
}

void UnloadMenu(Menu *menu) {
    UnloadTexture(menu->menuTexture); // Libera a textura do menu
}
 
