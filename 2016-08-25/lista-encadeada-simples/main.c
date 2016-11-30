#include <stdio.h>
#include <stdlib.h>

/*
 * Exercicio: Lista encadeada simples
 * Funcao imprimir - void
 * Funcao tamanhoLista - int
 * Funcao mediaLista - float
 * Funcao buscarElemento - int
 * Funcao inserirComeco - int
 * Funcao inserirFim - int
 * Funcao inserirMeio - int
 * Funcao removerComeco - void
 * Funcao removerFim - void
 * Funcao limpaMemoria - void
 */

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
        printf("\n###\nO QUÊ VOCÊ DESEJA FAZER?\n---\n");
        printf(" I - Imprimir elementos da lista.\n");
        printf(" T - Tamanho da lista.\n");
        printf(" M - Média aritimetica da lista.\n");
        printf(" B - Buscar elementos da lista.\n");
        printf(" C - Inserir no começo da lista.\n");
        printf(" F - Inserir no fim da lista.\n");
        printf(" G - Inserir no meio da lista.\n");
        printf(" P - Remover no começo da lista.\n");
        printf(" U - Remover no começo da lista.\n");
        printf(" S - Sair\n---\n>>> ");

        // Carregar opcao
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {

            case 'i':
            case 'I':

                imprimir(inicio);
                break;

            case 't':
            case 'T':

                printf("\n---\nO tamanho da lista é: %i\n---\n", tamanhoLista(inicio));
                break;

            case 'm':
            case 'M':

                printf("\n---\nA média aritimética da lista é: %f\n---\n", mediaLista(inicio));
                break;

            case 'b':
            case 'B':

                printf("\nBusque na lista o nro: ");
                scanf("%i", &x);
                getchar();

                printf("\n---\n");
                printf("\nForam encontrados '%i' elementos\n---\n", buscarElemento(inicio, x));
                break;

            case 'c':
            case 'C':

                printf("\nInsira no começo da lista o nro: ");
                scanf("%i", &x);
                getchar();

                if (inserirComeco(&inicio, x) == 1) {

                    printf("\nO numero foi inserido com sucesso.\n");

                } else {

                    printf("\nO numero não foi inserido.\n");

                }

                break;

            case 'f':
            case 'F':

                printf("\nInsira no fim da lista o nro: ");
                scanf("%i", &x);
                getchar();

                if (inserirFim(&inicio, x) == 1) {

                    printf("\nO numero foi inserido com sucesso.\n");

                } else {

                    printf("\nO numero não foi inserido.\n");

                }

                break;

            case 'g':
            case 'G':

                printf("\nInsira no meio da lista o nro: ");
                scanf("%i", &x);
                getchar();

                if (inserirMeio(&inicio, x) == 1) {

                    printf("\nO numero foi inserido com sucesso.\n");

                } else {

                    printf("\nO numero não foi inserido.\n");

                }

                break;

            case 'p':
            case 'P':

                removerComeco(&inicio);
                break;

            case 'u':
            case 'U':

                removerFim(&inicio);
                break;

            case 's':
            case 'S':

                limpaMemoria(&inicio);
                sair = 1;
                printf("\nTchau nenem!\n");
                break;

            default:

                printf("\n*** OPÇÃO INVÁLIVA ***\n");
                break;

        }

    } while (sair == 0);

    return 0;
}
