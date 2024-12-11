#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "constants.h"


// Definição da estrutura BACKGROUND
typedef struct {
    Texture2D backgroundTextures[NUM_BACKGROUND_LAYERS];
    float scrolling[NUM_BACKGROUND_LAYERS];     // Rolagem para cada camada
    float scale[NUM_BACKGROUND_LAYERS];         // Escala para cada camada
    float scaledWidth[NUM_BACKGROUND_LAYERS];   // Largura ajustada para cada camada
    float speed[NUM_BACKGROUND_LAYERS];         // Velocidade de rolagem para cada camada
} BACKGROUND;

// Declaração das funções do fundo
void InitBackground(BACKGROUND *bg);
void UpdateBackground(BACKGROUND *bg);
void DrawBackground(const BACKGROUND *bg);
void UnloadBackground(BACKGROUND *bg);

#endif // BACKGROUND_H

