#include <stdio.h>

/*
Desafio Novato: Tema 5 - Jogo de Batalha Naval
    Autor: Jardel Santos
    Nível: Novato
    Linguagem: C - Vetores e Matrizes.

Objetivo:
    1. Represente o Tabuleiro: Utilize uma matriz (array bidimensional) para representar o tabuleiro do Batalha Naval.
       Neste nível novato, o tabuleiro terá um tamanho fixo 10x10. 
       Inicialize todas as posições do tabuleiro com o valor 0, representando água.
    2. Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios. 
       Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições). 
       Um navio será posicionado horizontalmente e o outro verticalmente. 
       Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3. 
       Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro 
       dos limites do tabuleiro e não se sobreponham. 
    3. Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console.
       Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios. 
       A saída deve ser clara e organizada, permitindo visualizar facilmente a posição dos navios. 
*/

#define TABULEIRO 10    // Tamanho do tabuleiro
#define NAVIO 3    // Tamanho de cada navio

int main() {
    int tabuleiro[TABULEIRO][TABULEIRO]; // Matriz do tabuleiro
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TABULEIRO; i++) {
        for (j = 0; j < TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --------------------------
    // Definindo coordenadas dos navios
    // --------------------------
    // Navio horizontal
    int navioH_linha = 2; // Linha inicial
    int navioH_coluna = 1; // Coluna inicial

    // Navio vertical
    int navioV_linha = 5; // Linha inicial
    int navioV_coluna = 7; // Coluna inicial

    // --------------------------
    // Validação simples para garantir que o navio fique dentro do tabuleiro
    // --------------------------
    if (navioH_coluna + NAVIO > TABULEIRO || navioH_linha >= TABULEIRO) {
        printf("Navio horizontal fora dos limites do tabuleiro!\n");
        return 1; // para testar esta validação, modificar valor excedendo na instrução na linha 42
    }

    if (navioV_linha + NAVIO > TABULEIRO || navioV_coluna >= TABULEIRO) {
        printf("Navio vertical fora dos limites do tabuleiro!\n");
        return 1; // para testar esta validação, modificar valor excedendo na instrução na linha 45
    }

    // --------------------------
    // Posiciona navio horizontal
    // --------------------------
    for (i = 0; i < NAVIO; i++) {
        tabuleiro[navioH_linha][navioH_coluna + i] = 3; // Marca com 3
    }

    // --------------------------
    // Posiciona navio vertical
    // --------------------------
    for (i = 0; i < NAVIO; i++) {
        // Validação simples de sobreposição
        if (tabuleiro[navioV_linha + i][navioV_coluna] == 3) {
            printf("Erro: navios sobrepostos!\n");
            return 1;
        }
        tabuleiro[navioV_linha + i][navioV_coluna] = 3; // Marca com 3
    }

    // --------------------------
    // Exibe o tabuleiro com colunas A-J e linhas 1-10
    // --------------------------
    printf("== TABULEIRO BATALHA NAVAL ==\n\n");

    // Cabeçalho das colunas
    printf("   "); // Espaço inicial para alinhar com números das linhas
    for (j = 0; j < TABULEIRO; j++) {
        printf("%c ", 'A' + j); // Letras de A a J
    }
    printf("\n");

    // Exibe cada linha com número e os valores do tabuleiro
    for (i = 0; i < TABULEIRO; i++) {
        printf("%2d ", i + 1); // Número da linha
        for (j = 0; j < TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
