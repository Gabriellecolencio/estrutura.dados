#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---
 * Trabalho de Estrutura de Dados 2º Bimestre
 * Autores: Getulio Vinicius Teixeira da Silva e Andréia Caroline Silva Alves
 * 3º Semestre do curso de Analise e Desenvolvimento de Sistemas
 * Faculdade de Técnologia de Franca - Fatec "Dr. Thomaz Novelino"
 * ---
 * Data: 2016-11-02
 * ---
 * Exercicio 1:
 * Fazer uma função que verifique se uma dada expressão aritmética possui ou não:
 * * parênteses;
 * * colchetes; e
 * * chaves.
 * corretamente utilizados, tanto número quanto posição.
 * ---
 */

// Bibliotecas da linguagem C
#include <locale.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da pilha
    struct pilha *s;

    // Iniciar a pilha
    s = stackInit();

    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcao do usuário
		printf("\n\n\n*********************************\nO QUÊ VOCÊ DESEJA FAZER?\n---------------------------------\n");
		printf("1 - Digitar a expressão matemática \n");
		printf("S - Sair\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case '1':

                digitarExpressao(s);
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
