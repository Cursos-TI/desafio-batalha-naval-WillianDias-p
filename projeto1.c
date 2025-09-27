#include <stdio.h>

int main() {

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0};  // Inicializando o tabuleiro com zeros

    // Imprimir o título
    printf("Tabuleiro de Batalha Naval\n");
    printf("  "); 
    // Imprimir as letras das colunas (A, B, C,...)
    // Espaço extra para alinhar as letras das colunas
    for (int j = 0; j < 10; j++) {
        printf("%c ", linha[j]);
    }
    printf("\n");  // Nova linha após a impressão das colunas

    // Imprimir o tabuleiro, linha por linha
    for (int i = 0; i < 10; i++) {
        printf("%d ", i + 1);  // Imprimir o número da linha (1, 2, 3,...)
        for (int j = 0; j < 4; j++) {
            // Imprimir o conteúdo do tabuleiro (aqui representado por ".")
            printf("0 ");
                for (int j = 0; j >= 5 && j <= 7; j++) {
            
                    printf("3 ");
                }
        }
        printf("\n");  // Nova linha após cada linha do tabuleiro
    }

    return 0;
}
