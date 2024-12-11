#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"  // Para as cores
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

// Dimensões da tela
#define SCREEN_WIDTH  1200
#define SCREEN_HEIGHT 600

// Cores
#define TITLE_COLOR     DARKBLUE
#define MENU_COLOR      DARKGRAY
#define SELECTED_COLOR  YELLOW  // Mantido apenas uma definição
#define UNSELECTED_COLOR GRAY   // Mantido apenas uma definição

// Posições e tamanhos
#define TITLE_X_POSITION (SCREEN_WIDTH / 2 - MeasureText("Cyberpunk", TITLE_FONT_SIZE) / 2)
#define TITLE_Y_POSITION 40
#define TITLE_FONT_SIZE  40

#define MENU_FONT_SIZE  30
#define OPTION_Y_OFFSET 30
#define NUM_MENU_STATES 3

// Valores de rolagem para cada camada do fundo
#define BACKGROUND_SCROLL_SPEED 3.5f
#define MIDGROUND_SCROLL_SPEED  4.0f
#define FOREGROUND_SCROLL_SPEED 4.5f

#define NUM_BACKGROUND_LAYERS 3   // Número de camadas de fundo

#endif // CONSTANTS_H
