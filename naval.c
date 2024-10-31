#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 10
#define AGUA '~'
#define NAVIO 'N'
#define TIRO_ACERTO 'X'
#define TIRO_ERRO 'O'

void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void posicionarNavio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int navios);
int atirar(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna);

int main() {
    char tabuleiroJogador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char tabuleiroComputador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna, resultado;
    int navios = 5;
    int naviosJogador = navios, naviosComputador = navios;

    srand(time(NULL));

    inicializarTabuleiro(tabuleiroJogador);
    inicializarTabuleiro(tabuleiroComputador);

    printf("Posicionando os navios do jogador...\n");
    posicionarNavio(tabuleiroJogador, navios);

    printf("Posicionando os navios do computador...\n");
    posicionarNavio(tabuleiroComputador, navios);

    while (naviosJogador > 0 && naviosComputador > 0) {
        printf("\nSeu tabuleiro:\n");
        exibirTabuleiro(tabuleiroJogador);

        printf("\nEscolha uma posição para atirar (linha e coluna de 0 a 9): ");
        scanf("%d %d", &linha, &coluna);

        resultado = atirar(tabuleiroComputador, linha, coluna);
        if (resultado == 1) {
            printf("Você acertou um navio!\n");
            naviosComputador--;
        } else {
            printf("Você errou!\n");
        }

        // Computador atira
        linha = rand() % TAMANHO_TABULEIRO;
        coluna = rand() % TAMANHO_TABULEIRO;
        printf("\nO computador atirou em (%d, %d)\n", linha, coluna);

        resultado = atirar(tabuleiroJogador, linha, coluna);
        if (resultado == 1) {
            printf("O computador acertou seu navio!\n");
            naviosJogador--;
        } else {
            printf("O computador errou!\n");
        }
    }

    if (naviosJogador == 0) {
        printf("Todos os seus navios foram destruídos. Você perdeu!\n");
    } else {
        printf("Todos os navios do computador foram destruídos. Você venceu!\n");
    }

    return 0;
}

void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int navios) {
    int linha, coluna;
    for (int i = 0; i < navios; i++) {
        do {
            linha = rand() % TAMANHO_TABULEIRO;
            coluna = rand() % TAMANHO_TABULEIRO;
        } while (tabuleiro[linha][coluna] == NAVIO);
        tabuleiro[linha][coluna] = NAVIO;
    }
}

int atirar(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (tabuleiro[linha][coluna] == NAVIO) {
        tabuleiro[linha][coluna] = TIRO_ACERTO;
        return 1;
    } else if (tabuleiro[linha][coluna] == AGUA) {
        tabuleiro[linha][coluna] = TIRO_ERRO;
        return 0;
    }
    return -1;  // Já foi atingido anteriormente
}
