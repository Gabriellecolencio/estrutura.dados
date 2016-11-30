#include <stdio.h>
#include <stdlib.h>

/*
 * Trabalho de Estrutura de Dados 2º Bimestre
 * Autores: Getulio Vinicius Teixeira da Silva e Andréia Caroline Silva Alves
 * 3º Semestre do curso de Analise e Desenvolvimento de Sistemas
 * Faculdade de Técnologia de Franca - Fatec "Dr. Thomaz Novelino"
 * ---
 * Data: 2016-10-27
 * ---
 * Exercicio 3: hashing
 * ---
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Iniciar filas
    struct no *vetorIndice[tamanhoMaximo];

    int i;

    for (i=0; i<tamanhoMaximo; i++) {

        vetorIndice[i] = NULL;

    }

    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcao do usuario
		printf("\n\n\n*********************************\nO QUÊ VOCÊ DESEJA FAZER?\n---------------------------------\n");
		printf("1 - Imprimir a tabela hash\n");
		printf("2 - Inserir chave\n");
		printf("S - Sair\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case '1':

                printHash(vetorIndice);
                break;

            case '2':
                insertHash(vetorIndice, 'N');
                insertHash(vetorIndice, 'I');
                insertHash(vetorIndice, 'V');
                insertHash(vetorIndice, 'O');
                insertHash(vetorIndice, 'Z');
                insertHash(vetorIndice, 'U');
                insertHash(vetorIndice, 'A');
                insertHash(vetorIndice, 'E');
                insertHash(vetorIndice, 'F');
                insertHash(vetorIndice, 'R');
                insertHash(vetorIndice, 'B');
                insertHash(vetorIndice, 'L');
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
