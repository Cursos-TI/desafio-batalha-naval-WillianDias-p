#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HABILIDADE 5

#define AGUA 0
#define NAVIO_CEL 3
#define AREA_HABILIDADE 5

#define AFETADO 1
#define NAO_AFETADO 0

void imprimirTabuleiro(int tabuleiro[TAM][TAM]);
void inicializarTabuleiro(int tabuleiro[TAM][TAM]);
void criarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]);
void criarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]);
void criarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]);
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int linhaOrigem, int colunaOrigem);

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("     ");
    for (int j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    printf("   +---------------------\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d | ", i + 1);
        for (int j = 0; j < TAM; j++) {
            char simbolo;
            switch (tabuleiro[i][j]) {
                case AGUA:
                    simbolo = '~';
                    break;
                case NAVIO_CEL:
                    simbolo = 'N';
                    break;
                case AREA_HABILIDADE:
                    simbolo = '*';
                    break;
                default:
                    simbolo = '?';
                    break;
            }
            printf("%c ", simbolo);
        }
        printf("|\n");
    }
    printf("   +---------------------\n\n");
}

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void criarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i >= abs(j - centro)) {
                matriz[i][j] = AFETADO;
            } else {
                matriz[i][j] = NAO_AFETADO;
            }
        }
    }
}

void criarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = AFETADO;
            } else {
                matriz[i][j] = NAO_AFETADO;
            }
        }
    }
}

void criarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = AFETADO;
            } else {
                matriz[i][j] = NAO_AFETADO;
            }
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == AFETADO) {
                int linhaAlvo = linhaOrigem + i - centro;
                int colunaAlvo = colunaOrigem + j - centro;

                if (linhaAlvo >= 0 && linhaAlvo < TAM && colunaAlvo >= 0 && colunaAlvo < TAM) {
                    tabuleiro[linhaAlvo][colunaAlvo] = AREA_HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int navio = 3;

    int matrizCone[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizCruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarMatrizCone(matrizCone);
    criarMatrizCruz(matrizCruz);
    criarMatrizOctaedro(matrizOctaedro);

    printf("=======================================\n");
    printf("  DEMONSTRACAO DA HABILIDADE: CONE\n");
    printf("=======================================\n");
    inicializarTabuleiro(tabuleiro);
    for(int i = 0; i < navio; i++) tabuleiro[1][1+i] = NAVIO_CEL;
    printf("Tabuleiro apenas com o navio:\n\n");
    imprimirTabuleiro(tabuleiro);

    aplicarHabilidade(tabuleiro, matrizCone, 4, 4);
    printf("Tabuleiro com a habilidade CONE aplicada (origem E5):\n\n");
    imprimirTabuleiro(tabuleiro);

    printf("=======================================\n");
    printf("  DEMONSTRACAO DA HABILIDADE: CRUZ\n");
    printf("=======================================\n");
    inicializarTabuleiro(tabuleiro);
    for(int i = 0; i < navio; i++) tabuleiro[5][5+i] = NAVIO_CEL;
    printf("Tabuleiro apenas com o navio:\n\n");
    imprimirTabuleiro(tabuleiro);

    aplicarHabilidade(tabuleiro, matrizCruz, 5, 5);
    printf("Tabuleiro com a habilidade CRUZ aplicada (origem F6):\n\n");
    imprimirTabuleiro(tabuleiro);

    printf("=======================================\n");
    printf("  DEMONSTRACAO DA HABILIDADE: OCTAEDRO\n");
    printf("=======================================\n");
    inicializarTabuleiro(tabuleiro);
    for(int i = 0; i < navio; i++) tabuleiro[8][2+i] = NAVIO_CEL;
    printf("Tabuleiro apenas com o navio:\n\n");
    imprimirTabuleiro(tabuleiro);
    
    aplicarHabilidade(tabuleiro, matrizOctaedro, 7, 3);
    printf("Tabuleiro com a habilidade OCTAEDRO aplicada (origem D8):\n\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}