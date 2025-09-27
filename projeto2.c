#include <stdio.h>

#define TAM 10      // tamanho do tabuleiro 10x10
#define NAVIO 3     // tamanho do navio
#define AGUA 0
#define NAVIO_CEL 3

// Função para imprimir o tabuleiro formatado
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    // cabeçalho com letras das colunas
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // imprime o tabuleiro com numeração das linhas
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1); // numeração das linhas
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para validar se um navio pode ser colocado
int podeColocar(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int k = 0; k < NAVIO; k++) {
        int l = linha + k * dLinha;
        int c = coluna + k * dColuna;
        if (l < 0 || l >= TAM || c < 0 || c >= TAM) return 0; // fora do tabuleiro
        if (tabuleiro[l][c] == NAVIO_CEL) return 0;           // já ocupado
    }
    return 1;
}

// Função para posicionar um navio
void colocarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int k = 0; k < NAVIO; k++) {
        int l = linha + k * dLinha;
        int c = coluna + k * dColuna;
        tabuleiro[l][c] = NAVIO_CEL;
    }
}

int main() {
    int tabuleiro[TAM][TAM]; // matriz que representa o tabuleiro

    // inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // imprime tabuleiro inicial (somente água)
    printf("Tabuleiro inicial (somente agua):\n\n");
    imprimirTabuleiro(tabuleiro);

    // coordenadas iniciais fixas para simplificação
    int linhaHorizontal = 2, colunaHorizontal = 4; // navio horizontal
    int linhaVertical   = 5, colunaVertical   = 7; // navio vertical
    int linhaDiag1      = 0, colunaDiag1      = 0; // navio diagonal ↘
    int linhaDiag2      = 7, colunaDiag2      = 2; // navio diagonal ↗

    // posiciona navio horizontal (direção direita: dLinha=0, dColuna=1)
    if (podeColocar(tabuleiro, linhaHorizontal, colunaHorizontal, 0, 1))
        colocarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 0, 1);

    // posiciona navio vertical (direção baixo: dLinha=1, dColuna=0)
    if (podeColocar(tabuleiro, linhaVertical, colunaVertical, 1, 0))
        colocarNavio(tabuleiro, linhaVertical, colunaVertical, 1, 0);

    // posiciona navio diagonal principal (↘, direção: dLinha=1, dColuna=1)
    if (podeColocar(tabuleiro, linhaDiag1, colunaDiag1, 1, 1))
        colocarNavio(tabuleiro, linhaDiag1, colunaDiag1, 1, 1);

    // posiciona navio diagonal secundária (↗, direção: dLinha=-1, dColuna=1)
    if (podeColocar(tabuleiro, linhaDiag2, colunaDiag2, -1, 1))
        colocarNavio(tabuleiro, linhaDiag2, colunaDiag2, -1, 1);

    // imprime tabuleiro com navios
    printf("Tabuleiro com os navios posicionados:\n\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
