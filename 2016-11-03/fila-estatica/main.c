#include <stdio.h>
#include <stdlib.h>

/*
 * Exercicio: fila - estática
 * Data: 2016/11/03
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da fila
    struct fila *q;
    int x;

    // Iniciar a fila
    q = queueInit();

    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcao do usuario
		printf("\n\n\n*********************************\nO QUÊ VOCÊ DESEJA FAZER?\n---------------------------------\n");
		printf("1 - Listar os elementos da fila (list)\n");
		printf("2 - Mostrar o elemento no inicio da fila (front)\n");
		printf("3 - Mostrar o elemento no fim da fila (rear)\n");
		printf("4 - Mostrar o tamanho da fila (size)\n");
		printf("5 - Inserir elemento na fila (insert)\n");
		printf("6 - Remover elemento da fila (delete)\n");
		printf("7 - Limpar a fila (clear)\n");
		printf("S - Sair\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case '1':

                if (q->queueFront != q->queueRear) {

                    printf("\nP. Vet:\tItem:");
                    queueList(q);

                } else {

                    printf("\nA fila está vazia (empty).");

                }

                break;

            case '2':

                if (q->queueFront == q->queueRear) {

                    printf("\nA fila está vazia (empty).");

                } else {

                    printf("\nO elemento que está no inicio da fila (front) é: %i", q->item[q->queueFront + 1]);

                }

                break;

            case '3':

                if (q->queueFront == q->queueRear) {

                    printf("\nA fila está vazia (empty).");

                } else {

                    printf("\nO elemento que está no fim da fila (rear) é: %i", q->item[q->queueRear + 1]);

                }

                break;

            case '4':

                printf("\nO quantidade de elementos na fila é: %i", queueSize(q));
                break;

            case '5':

                if (q->queueFront != ((q->queueRear + 1) % tamanhoMaximo)) {

                    printf("\nDigite um numero inteiro: ");
                    scanf("%i", &x);
                    getchar();
                    queueInsert(q, x);

                } else {

                    printf("\nA fila está cheia (full).");
                }

                break;

            case '6':

                if (q->queueFront != q->queueRear) {

                    printf("\nO elemento '%i' foi removido.", queueDelete(q));

                    printf("\nFront: %i \t Rear: %i\n", q->queueFront, q->queueRear);

                } else {

                    printf("\nA fila está vazia (empty).");

                }

                break;

            case '7':

                if ((q->queueFront == 0) && (q->queueRear == 0)) {

                    printf("\nA fila está vazia (empty).");

                } else {

                    q->queueFront = q->queueRear = 0;
                    printf("\nA fila foi esvaziada (empty).\n");

                }

                break;

            case 's':
            case 'S':

                sair = 1;
                printf("\nTchau! :(\n");
                break;

            default:

                printf("\nERRO: Opção Inválida");
                break;

        }

    } while (sair == 0);

    return 0;
}
