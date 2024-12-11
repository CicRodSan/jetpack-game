#include "background.h"

void InitBackground(BACKGROUND *bg) {
    // Carregar texturas de fundo
    bg->backgroundTextures[0] = LoadTexture("/home/cicero/Documentos/TRAB-ALG/assets/background.png");
    bg->backgroundTextures[1] = LoadTexture("/home/cicero/Documentos/TRAB-ALG/assets/midground.png");
    bg->backgroundTextures[2] = LoadTexture("/home/cicero/Documentos/TRAB-ALG/assets/foreground.png");

    // Verifica se houve erro ao carregar as texturas
    for (int i = 0; i < NUM_BACKGROUND_LAYERS; i++) {
        if (bg->backgroundTextures[i].id == 0) {
            printf("Erro ao carregar a textura de fundo %d\n", i);
        }
    }

    // Inicializa propriedades das camadas de fundo
    for (int i = 0; i < NUM_BACKGROUND_LAYERS; i++) {
        // Inicializa a rolagem
        bg->scrolling[i] = 0.0f;

        // Define a velocidade de rolagem com base na camada
        switch (i) {
        case 0:
            bg->speed[i] = BACKGROUND_SCROLL_SPEED;
            break;
        case 1:
            bg->speed[i] = MIDGROUND_SCROLL_SPEED;
            break;
        case 2:
            bg->speed[i] = FOREGROUND_SCROLL_SPEED;
            break;
        }

        // Calcula a escala com base na altura da tela
        float scaleHeight = (float)SCREEN_HEIGHT / (float)bg->backgroundTextures[i].height;
        bg->scale[i] = scaleHeight;

        // Ajusta a largura das texturas com base na escala
        bg->scaledWidth[i] = bg->backgroundTextures[i].width * bg->scale[i];
    }
}

void UpdateBackground(BACKGROUND *bg) {
    for (int i = 0; i < NUM_BACKGROUND_LAYERS; i++) {
        bg->scrolling[i] += bg->speed[i];
        if (bg->scrolling[i] >= bg->scaledWidth[i]) {
            bg->scrolling[i] = 0;  // Resetar rotação
        }
    }
}

void DrawBackground(const BACKGROUND *bg) {
    for (int i = 0; i < NUM_BACKGROUND_LAYERS; i++) {
        // Desenha a textura do fundo em duas partes para criar o efeito de rolagem contínua
        DrawTextureEx(bg->backgroundTextures[i], (Vector2) { -bg->scrolling[i], 0 }, 0.0f, bg->scale[i], WHITE);
        DrawTextureEx(bg->backgroundTextures[i], (Vector2) { bg->scaledWidth[i] - bg->scrolling[i], 0 }, 0.0f, bg->scale[i], WHITE);
    }
}

void UnloadBackground(BACKGROUND *bg) {
    for (int i = 0; i < NUM_BACKGROUND_LAYERS; i++) {
        if (bg->backgroundTextures[i].id > 0) { // Verifica se a textura é válida
            UnloadTexture(bg->backgroundTextures[i]);
        }
    }
}
