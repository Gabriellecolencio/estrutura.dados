// Decalaração da estrutura da lista
struct no {

    int info;
    struct no *prox;

};

// Funcao inicializarCabeca
struct no * inicializarCabeca() {

    // Cabeça da lista circular
    struct no *cabeca;

    // Iniciar a cabeca da lista
    if ((cabeca = malloc(sizeof(struct no))) == NULL) {

        printf("\n*** Erro na alocação de memória! ***\n");

    } else {

        cabeca->prox = cabeca;

    }

    return cabeca;

}

// Funcao imprimirComecoFim
void imprimirComecoFim(struct no *cabeca) {

    struct no *p;

    p = cabeca->prox;

    printf("\n---\nElementos da lista:\n---\n");

    while (p != cabeca) {

        printf("%i ", p->info);
        p = p->prox;

    }

    printf("\n---\n");

}

// Funcao tamanhoLista
int tamanhoLista(struct no *cabeca) {

    int x = 0;
    struct no *p;

    p = cabeca->prox;

    while (p != cabeca) {

        x++;
        p = p->prox;

    }

    return x;

}

// Funcao buscarElemento
void buscarElemento(struct no *cabeca, int x) {

    struct no *elemento;
    int total = 0;

    elemento = cabeca->prox;

    printf("\n---");

    while (elemento != cabeca) {

        if (elemento->info == x) {

            ++total;
            printf("\nElemento '%i' encontrado no endereço '%p'.", elemento->info, elemento);

        }

        elemento = elemento->prox;

    }

    printf("\n---\nElemento '%i' encontrado '%i' vez(es) na lista.\n---\n", x, total);

}

// Funcao inserirComeco
void inserirComeco(struct no *cabeca, int x) {

    struct no *comeco;

    if ((comeco = malloc(sizeof(struct no))) == NULL) {

        printf("Erro na alocação de memória!");

    } else {

        comeco->info = x;

        if (cabeca->prox == cabeca) {

            comeco->prox = cabeca;

        } else {

            comeco->prox = cabeca->prox;

        }

        cabeca->prox = comeco;

    }

}

// Funcao inserirFim
void inserirFim(struct no *cabeca, int x) {

    struct no *fim;

    if ((fim = malloc(sizeof(struct no))) == NULL) {

        printf("Erro de alocação de memória!");

    } else {

        fim->info = x;
        fim->prox = cabeca;

        struct no *p;

        p = cabeca;

        while (p->prox != cabeca) {

            p = p->prox;

        }

        p->prox = fim;

    }

}

// Funcao removerComeco
void removerComeco(struct no *cabeca) {

    if (cabeca->prox == cabeca) {

        printf("\n---\nA lista estava vazia.\n---\n");

    } else {

        struct no *comeco;

        comeco = cabeca->prox;
        cabeca->prox = comeco->prox;

        printf("\n---\nElemento '%i' armazenado no endereço '%p' será removido.\n---\n", comeco->info, comeco);

        free(comeco);

    }

}

// Funcao removerFim
void removerFim(struct no *cabeca) {

    if (cabeca->prox == cabeca) {

        printf("\n---\nA lista estava vazia.\n---\n");

    } else {

        struct no *fim;

        fim = cabeca->prox;

        if (fim->prox == cabeca) {

            cabeca->prox = cabeca;

        } else {

            struct no *p;

            while (fim->prox != cabeca) {

                p = fim;
                fim = fim->prox;

            }

            p->prox = cabeca;

        }

        printf("\n---\nElemento '%i' armazenado no endereço '%p' será removido.\n---\n", fim->info, fim);

        free(fim);

    }

}

// Funcao removerElemento
void removerElemento(struct no *cabeca, int x) {

    struct no *atual, *anterior, *elemento;
    int total = 0;

    anterior = cabeca;
    atual = cabeca->prox;

    printf("\n---");

    while (atual != cabeca) {

        elemento = atual;
        atual = atual->prox;

        if (elemento->info == x) {

            ++total;
            printf("\nElemento '%i' encontrado no endereço '%p'.", elemento->info, elemento);

            anterior->prox = atual;

            free(elemento);

        } else {

            anterior = anterior->prox;

        }

    }

    printf("\n---\nElemento '%i' encontrado e removido '%i' vez(es) na lista.\n---\n", x, total);

}

// Funcao limpaMemoria
void limpaMemoria(struct no *cabeca) {

    struct no *p;

    p = cabeca->prox;

    while (p != cabeca) {

        cabeca->prox = p->prox;

        printf("\napagando - %i", p->info);

        free(p);

        p = cabeca->prox;

    }

    free(p);

}
