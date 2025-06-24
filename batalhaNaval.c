#include <stdio.h>

#include <stdio.h>

// Nível aventureiro

#define TAM 10
#define TAM_NAVIO 3

int main() {

    int tabuleiro[TAM][TAM] = {0};
    int i;

    // posição inicial dos navios
    int linha1 = 1, coluna1 = 2;
    int linha2 = 4, coluna2 = 7;
    int linha3 = 0, coluna3 = 0;
    int linha4 = 5, coluna4 = 9;

    // posicionando navio 1 (horizontal)
    if (coluna1 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha1][coluna1 + i] == 3) {
                printf("Navio 1 com sobreposição.\n");
                return 1;
            }
            tabuleiro[linha1][coluna1 + i] = 3;
        }
    } else {
        printf("Navio 1 fora do tabuleiro.\n");
        return 1;
    }

    // posicionando navio 2 (vertical)
    if (linha2 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha2 + i][coluna2] == 3) {
                printf("Navio 2 com sobreposição.\n");
                return 1;
            }
            tabuleiro[linha2 + i][coluna2] = 3;
        }
    } else {
        printf("Navio 2 fora do tabuleiro.\n");
        return 1;
    }

    // posicionando navio 3 (diagonal crescente)
    if (linha3 + TAM_NAVIO <= TAM && coluna3 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha3 + i][coluna3 + i] == 3) {
                printf("Navio 3 com sobreposição.\n");
                return 1;
            }
            tabuleiro[linha3 + i][coluna3 + i] = 3;
        }
    } else {
        printf("Navio 3 fora do tabuleiro.\n");
        return 1;
    }

    // posicionando navio 4 (diagonal decrescente)
    if (linha4 + TAM_NAVIO <= TAM && coluna4 - (TAM_NAVIO - 1) >= 0) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha4 + i][coluna4 - i] == 3) {
                printf("Navio 4 com sobreposição.\n");
                return 1;
            }
            tabuleiro[linha4 + i][coluna4 - i] = 3;
        }
    } else {
        printf("Navio 4 fora do tabuleiro.\n");
        return 1;
    }

    // exibir o tabuleiro
    printf("\nTabuleiro:\n\n");

    int linha, coluna;

    printf("    ");
    for (coluna = 0; coluna < TAM; coluna++) {
        printf("%2d ", coluna);
    }
    printf("\n");

    for (linha = 0; linha < TAM; linha++) {
        printf("%2d |", linha);
        for (coluna = 0; coluna < TAM; coluna++) {
            printf(" %d ", tabuleiro[linha][coluna]);
        }
        printf("|\n");
    }

    return 0;
}
