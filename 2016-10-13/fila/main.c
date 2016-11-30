#include <stdio.h>
#include <stdlib.h>

/*
 * Exercicio: fila - dinâmica
 * Data: 2016/10/13
 * Funcao - 1: queueList - void
 * Funcao - 2: queueRear - void
 * Funcao - 3: queueSize - int
 * Funcao - 4: queueInsert - void
 * Funcao - 5: queueDelete - void
 * Funcao - 6: queueClear - void
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da fila
    struct no *inicio = NULL;

    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcao do usuário
		printf("\n\n\n*********************************\nO QUÊ VOCÊ DESEJA FAZER?\n---------------------------------\n");
		printf("1 - Listar elementos na fila (list)\n");
		printf("2 - Mostrar o 1º elemento da fila (front)\n");
		printf("3 - Mostrar o último elemento da fila (rear)\n");
		printf("4 - Mostrar o tamanho da fila (size)\n");
		printf("5 - Inserir um elemento na fila (insert)\n");
		printf("6 - Remover um elemento da fila (delete)\n");
		printf("7 - Limpar a fila (clear)\n");
		printf("S - Sair\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case '1':

                queueList(inicio);
                break;

            case '2':

                if (inicio == NULL) {

                    printf("\nA fila está vazia (empty).");

                } else {

                    printf("\nO primeiro elemento da fila (front) é: %i", inicio->info);

                }
                break;

            case '3':

                queueRear(inicio);
                break;

            case '4':

                printf("\nO tamanho da fila (size) é: %i", queueSize(inicio));
                break;

            case '5':

                queueInsert(&inicio);
                break;

            case '6':

                queueDelete(&inicio);
                break;

            case '7':

                queueClear(&inicio);
                break;

            case 's':
            case 'S':

                queueClear(&inicio);
                sair = 1;
                printf("\nTchau!\n");
                break;

            default:

                printf("\n---------------------------------\nERRO: Opção Inválida\n---------------------------------\n");
                break;

        }

    } while (sair == 0);

    return 0;
}
