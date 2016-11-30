#include <stdio.h>
#include <stdlib.h>
/*
 * Fazer um programa em C que manipule um vetor de, no máximo, 50 números inteiros e possua as seguintes funções:
 *
 * a) inserir elemento no vetor
 * b) soma dos numeros pares e retornar a soma
 * c) buscar um elemento e retornar 1 se o elemento existir no vetor
 * d) remover um elemento, dada a sua posicao e retornar o elemento
 *
 */

#define MAX 50

void inserir (int vet[MAX], int *tamanho, int elemento) {
    if (*tamanho < MAX) {
        vet[*tamanho] = elemento;
        (*tamanho)++;
    } else {
        printf("Vetor cheio!");
    }
}

int somar_pares(int vetor[MAX], int tamanho) {
    int resultado = 0;
    int i;

    for (i = 0; i <= tamanho; i++) {

        if (vetor[i] %2 == 0) {
            resultado += vetor[i];
        }

    }

    return resultado;

}

int busca_elemento (int vetor[MAX], int tamanho, int elemento) {

    int i;

    for (i = 0; i <= tamanho; i++) {

        if (vetor[i] == elemento) {
            return 1;
        }
    }

    return 0;

}

int remover(int vetor[MAX], int *tamanho, int posicao) {
    int i, elemento;

    elemento = vetor[posicao - 1];

    for (i = posicao - 1; i < *tamanho; i++) {
        vetor[i] = vetor[i + 1];
        (*tamanho)--;
    }

    return elemento;

}

int main() {

    int vetor[MAX];
    int tamanho = 0;
    int elemento;
    int soma;
    int busca;
    int posicao;
    char opcao;
    int sair = 0;

    while (sair != 1) {

        printf("\nEntre com a OPÇÃO [ I | S | B | R ]: ");
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {

            case 'i':
            case 'I':
                printf("\nInsira o elemento: ");
                scanf("%i", &elemento);
                getchar();
                inserir(vetor, &tamanho, elemento);
                break;

            case 's':
            case 'S':
                soma = somar_pares(vetor, tamanho);
                printf("\nA soma é: %d", soma);
                break;

            case 'B':
            case 'b':
                printf("\nEncontre com o elemento: ");
                scanf("%i", &elemento);
                getchar();
                busca = busca_elemento(vetor, tamanho, elemento);
                printf("\nA busca retornou: %d", busca);
                break;

            case 'R':
            case 'r':
                printf("\nQual posição vc quer remover? ");
                scanf("%d", &posicao);
                printf("O elemento removido foi %d", remover(vetor, &tamanho, posicao));
                break;

            default:
                printf("\n>>> Opção inválida! <<<\n");
                break;
        }

        printf("\nDigite 1 para sair ou 0 para continuar: ");
        scanf("%i", &sair);
        getchar();

    }

    return 0;

}
