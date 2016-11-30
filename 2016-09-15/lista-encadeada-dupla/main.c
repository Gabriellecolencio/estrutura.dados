#include <stdio.h>
#include <stdlib.h>

/*
 * Exercicio: lista encadeada dupla
 * Funcao imprimirComecoFim - void
 * Funcao imprimirFimComeco - void
 * Funcao inserirComeco - void
 * Funcao inserirFim - void
 * Funcao removerComeco - void
 * Funcao removerFim - void
 * Funcao removerElemento - void
 * Funcao limpaMemoria - void
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da lista
    struct no *inicio = NULL;
    int x;

    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcao do usuário
        printf("\n*****************************\nO QUÊ VOCÊ DESEJA FAZER?\n---\n");
        printf(" I - imprimir a lista do começo para o fim.\n");
        printf(" J - imprimir a lista do fim para o começo.\n");
        //printf(" T - ver tamanho da lista.\n");
        printf(" B - buscar elemento na lista.\n");
        printf(" C - inserir elemento no começo da lista.\n");
        printf(" F - inserir elemento no fim da lista.\n");
        //printf(" G - inserir elemento no meio.\n");
        printf(" P - remover elemento no começo da lista.\n");
        printf(" U - remover elemento no fim da lista.\n");
        printf(" R - buscar e remover um elemento.\n");
        printf(" S - Sair\n---\n>>> ");

        // Carregar opcao
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {

            case 'i':
            case 'I':

                imprimirComecoFim(inicio);
                break;

            case 'j':
            case 'J':

                imprimirFimComeco(inicio);
                break;

            case 'b':
            case 'B':

                printf("\nEncontre na lista o elemento: ");
                scanf("%i", &x);
                getchar();

                buscarElemento(inicio, x);
                break;

            case 'c':
            case 'C':

                printf("\nInsira no começo da lista o nro: ");
                scanf("%i", &x);
                getchar();
                inserirComeco(&inicio, x);
                break;

            case 'f':
            case 'F':

                printf("\nInsira no fim da lista o nro: ");
                scanf("%i", &x);
                getchar();
                inserirFim(&inicio, x);
                break;

            case 'p':
            case 'P':

                removerComeco(&inicio);
                break;

            case 'u':
            case 'U':

                removerFim(&inicio);
                break;

            case 'r':
            case 'R':

                printf("\nEncontre e remova o elemento: ");
                scanf("%i", &x);
                getchar();
                removerElemento(&inicio, x);
                break;

            case 's':
            case 'S':

                limpaMemoria(&inicio);
                sair = 1;

                printf("\nTchau nenem!\n");
                break;

            default:

                printf("\n>>> Opção inválida! <<<\n");
                break;

        }

    } while (sair != 1);

    return 0;

}
