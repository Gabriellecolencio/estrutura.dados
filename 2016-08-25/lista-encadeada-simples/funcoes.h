// Declaracao da estrutura da lista
struct no {

    int info;
    struct no *prox;

};

// Funcao imprimir
void imprimir(struct no *inicio) {

    if (inicio == NULL) {

        printf("\n---\nNão há elementos na lista\n---\n");

    } else {

        struct no *p;

        p = inicio;

        printf("\n---\nElementos na lista\n---\n");

        while (p != NULL) {

            printf("%i ", p->info);
            p = p->prox;

        }

        printf("\n---\n");

    }

}

// Funcao tamanhoLista
int tamanhoLista(struct no *inicio) {

    struct no *p;
    int tamanho = 0;

    p = inicio;

    while (p != NULL) {

        ++tamanho;
        p = p->prox;

    }

    return tamanho;

}

// Funcao mediaLista
float mediaLista(struct no *inicio) {

    struct no *p;
    float tamanho = 0;
    float soma = 0;
    float media = 0;

    p = inicio;

    while (p != NULL) {

        ++tamanho;
        soma += p->info;
        p = p->prox;

    }

    if (tamanho != 0) {

        media = soma / tamanho;

    }

    return media;

}

// Funcao buscarElemento
int buscarElemento(struct no *inicio, int x) {

    struct no *p;
    int resultado = 0;

    p = inicio;

    while (p != NULL) {

        if (p->info == x) {

            printf("Elemento '%i' encontrado no endereço '%p'.\n", p->info, p);
            resultado++;

        }

        p = p->prox;

    }

    return resultado;

}

// Funcao inserirComeco
int inserirComeco(struct no **inicio, int x) {

    struct no *comeco;
    int resultado = 0;

    if ((comeco = malloc(sizeof(struct no))) == NULL) {

        printf("\n---\n Erro na alocação de memória.\n---\n");

    } else {

        comeco->info = x;

        if (*inicio == NULL) {

            *inicio = comeco;
            comeco->prox = NULL;

        } else {

            comeco->prox = *inicio;
            *inicio = comeco;

        }

        resultado = 1;

    }

    return resultado;

}

// Funcao inserirFim
int inserirFim(struct no **inicio, int x) {

    struct no *fim,*p;
    int resultado = 0;

    if ((fim = malloc(sizeof(struct no))) == NULL) {

        printf("\n---\n Erro na alocação de memória.\n---\n");

    } else {

        fim->info = x;
        fim->prox = NULL;

        p = *inicio;

        if (p == NULL) {

            *inicio = fim;

        } else {

            while (p->prox != NULL) {

                p = p->prox;

            }

            p->prox = fim;

        }

        resultado = 1;

    }

    return resultado;

}

// Função inserirMeio
int inserirMeio(struct no **inicio, int inteiro) {

    struct no *meio;
    int resultado = 0;

    if ((meio = malloc(sizeof(struct no))) == NULL) {

        printf("\nErro na alocação de memória!\n");

    } else {

        meio->info = inteiro;

        if (*inicio == NULL) {

            meio->prox = NULL;
            *inicio = meio;

        } else {

            struct no *p;
            int tamanho, i;

            p = *inicio;

            tamanho = tamanhoLista(p);

            for (i = 1; i < tamanho / 2; i++) {

                p = p->prox;

            }

            meio->prox = p->prox;
            p->prox = meio;

        }

        resultado = 1;

    }

    return resultado;

}

// Funcao removerComeco
void removerComeco(struct no **inicio) {

    if (*inicio == NULL) {

        printf("\n---\nA lista esta vazia.\n---\n");

    } else {

        struct no *comeco;

        comeco = *inicio;
        *inicio = comeco->prox;

        printf("\n---\nO elemento %i amarmazenado no endereço %p será removido.\n---\n", comeco->info, comeco);

        free(comeco);

    }

}

// Funcao removerFim

void removerFim(struct no **inicio) {

    if (*inicio == NULL) {

        printf("\n---\nA lista esta vazia.\n---\n");

    } else {

        struct no *fim, *p;

        fim = *inicio;

        if (fim->prox == NULL) {

            *inicio = NULL;

        } else {

            while (fim->prox != NULL) {

                p = fim;
                fim = fim->prox;

            }

            p->prox = NULL;

        }

        printf("\n---\nO elemento %i amarmazenado no endereço %p será removido.\n---\n", fim->info, fim);
        free(fim);

    }

}

// Funcao buscarRemover
/*
 * Nao foi pedida nesse exercicio mas da pra fazer.
 */

// Funcao limpaMemoria
void limpaMemoria(struct no **inicio) {

    struct no *p;

    while (*inicio != NULL) {

        p = *inicio;
        *inicio = (*inicio)->prox;
        free(p);

    }

}
