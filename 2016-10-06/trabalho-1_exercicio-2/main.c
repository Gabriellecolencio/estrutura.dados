/* ---
 * Trabalho de Estrutura de Dados 1º Bimestre
 * Autores: Getulio Vinicius Teixeira da Silva e Andréia Caroline Silva Alves
 * 3º Semestre do curso de Analise e Desenvolvimento de Sistemas
 * Faculdade de Técnologia de Franca - Fatec "Dr. Thomaz Novelino"
 * ---
 * Exercicio 2:
 * Um grupo de pessoas tem que escolher um entre todos para ganhar uma viagem.
 * Para decidir quem será o sortudo, formaram um círculo (em ordem de chegada), e escolheram a primeira pessoa para iniciar e um número M.
 * Contando a partir da pessoa inicial, a M-ésima pessoa, no sentido horário, será retirada do círculo e não ganhará a viagem.
 * Em seguida, a contagem recomeça a partir da próxima pessoa, até que a última pessoa que restar no círculo ganhará a viagem.
 * Escreva um programa que leia o nome da pessoa inicial e o valor de M, imprima a ordem em que as pessoas irão sair do círculo e a que ganhou a viagem.
 * Utilizar lista circular encadeada.
 * ---
 * Funcao - 1: iniciarLista - struct no *
 * Funcao - 2: cadastrarParticipante - void
 * Funcao - 3: sortear - void
 * Funcao - 4: buscarParticipante - struct no *
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
    struct no *cabeca;

    // Variaveis de controle do menu
    char opcao;
    int encerrarCadastro = 0, sair = 0;

    // Iniciar a lista
    cabeca = iniciarLista();

	printf("\n*********************************\nSORTEIO DE VIAGEM - 1.0\n*********************************\n");

    // Menu
    do {

		// Opcoes do usuário
		printf("\n\n*********************************\nCADASTRAR PARTICIPANTE DO SORTEIO:\n---------------------------------\n");
		printf("C - Cadastrar novo participante\n");
		printf("E - Encerrar cadastro de participantes\n---------------------------------\n>>> ");

		// Carregar opcao
		scanf("%c", &opcao);
		getchar();

        switch (opcao) {

            case 'c':
            case 'C':

                cadastrarParticipante(cabeca);
                break;

            case 'e':
            case 'E':

                if (cabeca->prox == cabeca) {

                    sair = 1;

                }

                encerrarCadastro = 1;
                break;

            default:

                printf("\n---------------------------------\nERRO: Opção Inválida\n---------------------------------\n");
                break;

        }

    } while (encerrarCadastro == 0);

    if (sair == 1) {

        free(cabeca);
        printf("\n---------------------------------\nNenhum participante foi cadastrado.\nO sorteio será encerrado e eu ficarei com a viagem.\n");
        printf("Nada mais justo afinal.\nVou arrumar as malas.\n---------------------------------\n");
        printf("\nTchau! - :)\n");

        return 0;

    }

    imprimirComecoFim(cabeca);

    printf("\n---------------------------------\nÉ HORA DO SORTEIO\n---------------------------------\n");

    sortearViagem(cabeca);

    limpaMemoria(cabeca);

    printf("\nTchau! - :)\n");

    return 0;
}
