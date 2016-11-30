#include <stdio.h>
#include <stdlib.h>

/*
 * Exercicio: fila
 * Funcao - 1: ....
 * Funcao - 2: ....
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
//#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da lista


    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcao do usuário
		printf("\n\n\n*********************************\nO QUÊ VOCÊ DESEJA FAZER?\n---------------------------------\n");
		printf("S - Sair\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case 's':
            case 'S':

                printf("\nTchau!\n");
                sair = 1;
                break;

            default:

                printf("\n---------------------------------\nERRO: Opção Inválida\n---------------------------------\n");
                break;

        }

    } while (sair == 0);

    return 0;
}

