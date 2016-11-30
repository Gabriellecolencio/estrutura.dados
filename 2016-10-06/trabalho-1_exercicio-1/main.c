/* ---
 * Trabalho de Estrutura de Dados 1º Bimestre
 * Autores: Getulio Vinicius Teixeira da Silva e Andréia Caroline Silva Alves
 * 3º Semestre do curso de Analise e Desenvolvimento de Sistemas
 * Faculdade de Técnologia de Franca - Fatec "Dr. Thomaz Novelino"
 * ---
 * Exercicio 1:
 * Fazer um programa que manipule os dados residenciais (nome, rua, número, cidade e estado) de um grupo de pessoas.
 * O programa deve permitir inserir, remover e pesquisar pelo nome da pessoa.
 * Usar uma lista dinâmica, que deve ser mantida sempre em ordem crescente pelo nome da pessoa.
 * ---
 * Funcao - 1: listarPessoas - void
 * Funcao - 2: buscarPessoa - void
 * Funcao - 3: inserirPessoa - void
 * Funcao - 4: removerPessoa - void
 * Funcao - 5: limpaMemoria - void
 * ---
 */

// Bibliotecas da linguagem C
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Arquivo de funcoes externo
#include "funcoes.h"

int main() {

    setlocale(LC_ALL, "");

    // Variaveis de controle da lista
    struct no *inicio = NULL;

    // Variaveis de controle do menu
    char opcao;
    int sair = 0;

    // Menu
    do {

		// Opcoes do usuário
		printf("\n\n\n*********************************\nO QUÊ VOCÊ DESEJA FAZER?\n---------------------------------\n");
		printf("L - Imprimir a lista de pessoas\n");
		printf("B - Buscar pessoa na lista\n");
		printf("I - Inserir pessoa na lista\n");
		printf("R - Remover pessoa da lista\n");
		printf("S - Sair\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case 'l':
            case 'L':

                listarPessoas(inicio);
                break;

            case 'b':
            case 'B':

                buscarPessoa(inicio);
                break;

            case 'i':
            case 'I':

                inserirPessoa(&inicio);
                break;

            case 'r':
            case 'R':

                removerPessoa(&inicio);
                break;

            case 's':
            case 'S':

                limpaMemoria(&inicio);
                sair = 1;
                printf("\nTchau! - :(\n");
                break;

            default:

                printf("\n---------------------------------\nERRO: Opção Inválida\n---------------------------------\n");
                break;

        }

    } while (sair == 0);

    return 0;
}
