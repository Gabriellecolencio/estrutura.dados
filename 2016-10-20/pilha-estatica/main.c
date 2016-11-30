#include <stdio.h>
#include <stdlib.h>

/*
 * Exercicio: pilha - estática
 * Data: 2016/10/20
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da pilha
    struct pilha *s;
    int x;

    // Iniciar a pilha
    s = stackInit();

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
		printf("S - Sair\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case '1':

                if (s->topo > -1) {

                    printf("\nPos.:\tItem:");
                    stackList(s);

                } else {

                    printf("\nA pilha está vazia (empty).");

                }

                break;

            case '2':

                if (s->topo == -1) {

                    printf("\nA pilha está vazia (empty).");

                } else {

                    printf("\nO elemento que está no topo da pilha é: %i", s->item[s->topo]);

                }

                break;

            case '3':

                printf("\nO quantidade de elementos na pilha é: %i", s->topo + 1);
                break;

            case '4':

                if (s->topo < (tamanhoMaximo - 1)) {

                    printf("\nDigite um numero inteiro: ");
                    scanf("%i", &x);
                    getchar();
                    stackPush(s, x);

                } else {

                    printf("\nA pilha está cheia (full).");
                }

                break;

            case '5':

                if (s->topo > -1) {

                    printf("\nO elemento '%i' foi removido.", stackPop(s));

                } else {

                    printf("\nA pilha está vazia (empty).");

                }

                break;

            case '6':

                if (s->topo == -1) {

                    printf("\nA pilha está vazia (empty).");

                } else {

                    s->topo = -1;
                    printf("\nA pilha foi esvaziada (empty).\n");

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
