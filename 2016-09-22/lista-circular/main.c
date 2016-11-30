#include <stdio.h>
#include <stdlib.h>

/*
 * Exercicio: Lista circular
 * Funcao - 1: inicializarCabeca - struct no *
 * Funcao - 2: imprimirComecoFim - void
 * Funcao - 3: tamanhoLista - int
 * Funcao - 4: buscarElemento - void
 * Funcao - 5: inserirComeco - void
 * Funcao - 6: inserirFim - void
 * Funcao - 7: removerComeco - void
 * Funcao - 8: removerFim - void
 * Funcao - 9: removerElemento - void
 * Funcao - 10: limpaMemoia - void
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da lista
    struct no *cabeca;
    int x;

    // Inicializar a cabeca da lista
    cabeca = inicializarCabeca();


    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcao do usuário
        printf("\n*****************************\nO QUÊ VOCÊ DESEJA FAZER?\n---\n");
        printf(" I - imprimir a lista do começo para o fim.\n");
        //printf(" J - imprimir a lista do fim para o começo.\n");
        printf(" T - ver tamanho da lista.\n");
        printf(" B - buscar elemento na lista.\n");
        printf(" C - inserir elemento no começo da lista.\n");
        printf(" F - inserir elemento no fim da lista.\n");
        //printf(" G - inserir elemento no meio da lista.\n");
        printf(" P - remover elemento no começo da lista.\n");
        printf(" U - remover elemento no fim da lista.\n");
        printf(" R - buscar e remover um elemento da lista.\n");
        printf(" S - Sair\n---\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case 'i':
            case 'I':

                imprimirComecoFim(cabeca);
                break;

            case 't':
            case 'T':

                printf("\n---\nA lista possui '%i' elementos.\n---\n", tamanhoLista(cabeca));
                break;

            case 'b':
            case 'B':

                printf("\nEncontre na lista o nro: ");
                scanf("%i", &x);
                getchar();

                buscarElemento(cabeca, x);
                break;

            case 'c':
            case 'C':

                printf("\nInsira no começo da lista o nro: ");
                scanf("%i", &x);
                getchar();

                inserirComeco(cabeca, x);
                break;

            case 'f':
            case 'F':

                printf("\nInsira no fim da lista o nro: ");
                scanf("%i", &x);
                getchar();

                inserirFim(cabeca, x);
                break;

            case 'p':
            case 'P':

                removerComeco(cabeca);
                break;

            case 'u':
            case 'U':

                removerFim(cabeca);
                break;

            case 'r':
            case 'R':

                printf("\nRemova da lista o elemento: ");
                scanf("%i", &x);
                getchar();

                removerElemento(cabeca, x);
                break;

            case 's':
            case 'S':

                sair = 1;
                limpaMemoria(cabeca);
                printf("\nTchau nenem!\n");
                break;

            default:

                printf("\n*** OPÇÃO INVÁLIVA ***\n");
                break;

        }

    } while (sair == 0);

    return 0;
}
