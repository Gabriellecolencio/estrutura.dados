// Declaração da estrutura da lista
struct no {

    int info;
    struct no *esq, *dir;

};

// Funcao imprimirComecoFim
void imprimirComecoFim(struct no *inicio) {

    printf("\n---\nElementos da lista:\n---\n");

    if (inicio == NULL) {

        printf("Lista vazia!");

    } else {

        struct no *p;

        p = inicio;

        while (p != NULL) {

            printf("%d ", p->info);
            p = p->dir;

        }

    }

    printf("\n---\n");

}

// Funcao imprimirFimComeco
void imprimirFimComeco(struct no *inicio) {

    printf("\n---\nElementos da lista:\n---\n");

    if (inicio == NULL) {

        printf("Lista vazia!");

    } else {

        struct no *p;

        p = inicio;

        while (p->dir != NULL) {

            p = p->dir;

        }

        while (p != NULL) {

            printf("%d ", p->info);
            p = p->esq;

        }

    }

    printf("\n---\n");

}

// Função buscarElemento
void buscarElemento(struct no *inicio, int x) {

    struct no *elemento;
    int total = 0;

    elemento = inicio;

    printf("\n---");

    while (elemento != NULL) {

        if (elemento->info == x) {

            printf("\nElemento '%i' encontrado no endereço '%p'.", elemento->info, elemento);
            ++total;

        }

        elemento = elemento->dir;

    }

    printf("\n---\nO elemento '%i' foi encontrado '%i' vezes.\n---\n", x, total);

}

// Funcao inserirComeco
void inserirComeco(struct no **inicio, int x) {

    struct no *comeco;

    if ((comeco = malloc(sizeof(struct no))) == NULL) {

        printf("Erro na alocação de memória!");

    } else {

        comeco->esq = NULL;
        comeco->dir = *inicio;
        comeco->info = x;

        if (*inicio != NULL) {

            (*inicio)->esq = comeco;

        }

        *inicio = comeco;

        printf("\n---\nElemento '%i' inserido com sucesso no endereço '%p'.\n---\n", comeco->info, comeco);

    }

}

// Funcao inserirFim
void inserirFim(struct no **inicio, int x) {

    struct no *fim;

    if ((fim = malloc(sizeof(struct no))) == NULL) {

        printf("\nErro na alocação de memória!\n");

    } else {

        fim->info = x;

        if (*inicio == NULL) {

            *inicio = fim;
            fim->dir = NULL;
            fim->esq = NULL;

        } else {

            struct no *p;

            p = *inicio;

            while (p->dir != NULL) {

                p = p->dir;

            }

            p->dir = fim;
            fim->esq = p;
            fim->dir = NULL;

        }

        printf("\n---\nElemento '%i' inserido com sucesso no endereço '%p'.\n---\n", fim->info, fim);

    }

}

// Funcao removerComeco
void removerComeco(struct no **inicio) {

    if (*inicio == NULL) {

        printf("\n---\nA lista estava vazia.\n---\n");

    } else {

        struct no *comeco;

        comeco = *inicio;

        if (comeco->dir == NULL) {

            *inicio = NULL;

        } else {

            *inicio = comeco->dir;
            comeco->dir->esq = NULL;

        }

        printf("\n---\nRemovendo o elemento '%i' armazenado no endereço '%p'.\n---\n", comeco->info, comeco);
        free(comeco);

    }

}

// Funcao removerFim
void removerFim(struct no **inicio) {

    if (*inicio == NULL) {

        printf("\n---\nA lista estava vazia.\n---\n");

    } else {

        struct no *fim;

        fim = *inicio;

        if (fim->dir == NULL) {

            *inicio = NULL;

        } else {

            while (fim->dir != NULL) {

                fim = fim->dir;

            }

            fim->esq->dir = NULL;

        }

        printf("\n---\nRemovendo o elemento '%i' armazenado no endereço '%p'.\n---\n", fim->info, fim);
        free(fim);

    }

}

// Função removerElemento
void removerElemento(struct no **inicio, int x) {

    struct no *elemento;
    int total = 0;

    elemento = *inicio;
    printf("\n---");

    while (elemento != NULL) {

        struct no *p;

        p = elemento;
        elemento = elemento->dir;

        if (p->info == x) {

            printf("\nElemento '%i' encontrado no endereço '%p'. será removido", p->info, p);
            ++total;

            if (p->esq == NULL) {

                *inicio = p->dir;

            } else {

                if (p->dir == NULL) {

                    p->esq->dir = NULL;

                } else {

                    p->esq->dir = p->dir;
                    p->dir->esq = p->esq;

                }

            }

            free(p);

        }

    }

    printf("\n---\nO elemento '%i' foi encontrado e removido '%i' vezes.\n---\n", x, total);

}

// Funcao limpaMemoria
void limpaMemoria(struct no **inicio) {

    struct no *p;

    while (*inicio != NULL) {

        p = *inicio;
        *inicio = (*inicio)->dir;
        free(p);

    }

}
