#include <stdio.h>
#include <stdlib.h>

/*
 * Exercicio: pilha
 * Data: 13/10/2016
 * Funcao - 1: listStack - void
 * Funcao - 2: sizeStack - int
 * Funcao - 3: pushStack - void
 * Funcao - 4: popStack - void
 * Funcao - 5: clearStack - void
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da pilha
    struct no *topo = NULL;

    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcao do usuário
		printf("\n\n\n*********************************\nO QUÊ VOCÊ DESEJA FAZER?\n---------------------------------\n");
		printf("1 - Listar os elementos da pilha (list)\n");
		printf("2 - Mostrar o elemento no topo da pilha (top)\n");
		printf("3 - Mostrar o tamanho da pilha (size)\n");
		printf("4 - Inserir elemento na pilha (push)\n");
		printf("5 - Remover elemento da pilha (pop)\n");
		printf("6 - Limpar a pilha (clear)\n");
		printf("7 - Sair\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case '1':

                listStack(topo);
                break;

            case '2':

                if (topo == NULL) {

                    printf("\nA lista está vazia.");

                } else {

                    printf("\nO elemento que está no topoo da pilha é: %i", topo->info);

                }

                break;

            case '3':

                printf("\nO quantidade de elementos na pilha é: %i", sizeStack(topo));
                break;

            case '4':

                pushStack(&topo);
                break;

            case '5':

                popStack(&topo);
                break;

            case '6':

                clearStack(&topo);
                break;

            case '7':

                clearStack(&topo);
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
