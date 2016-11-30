// Declaracao da estrutura da fila
struct no {

    int info;
    struct no *prox;

};

// Funcao queueList
void queueList(struct no *inicio) {

    if (inicio == NULL) {

        printf("\nA fila está vazia (empty).\n");

    } else {

        struct no *p;

        p = inicio;

        printf("\nElementos na fila.\n");

        while (p != NULL) {

            printf("%i ", p->info);
            p = p->prox;

        }

    }

}

// Funcao queueRear
void queueRear(struct no *inicio) {

    if (inicio == NULL) {

        printf("\nA fila está vazia (empty).");

    } else {

        struct no *p;

        p = inicio;

        while (p->prox != NULL) {

            p = p->prox;

        }

        printf("\nO último elemento da fila (rear) é: %i", p->info);

    }

}

// Funcao queueSize
int queueSize(struct no *inicio) {

    int tamanho = 0;

    if (inicio == NULL) {

        printf("\nA fila está vazia (empty).");

    } else {

        struct no *p;

        p = inicio;

        while (p != NULL) {

            ++tamanho;
            p = p->prox;

        }

    }

    return tamanho;

}

// Funcao queueInsert
void queueInsert(struct no **inicio) {

    struct no *e;

    if ((e = malloc(sizeof(struct no))) == NULL) {

        printf("ERRO: não foi possível alocar memória.\nA fila está cheia (full).");

    } else {

        printf("\nDigite número inteiro: ");
        scanf("%i", &e->info);
        getchar();

        e->prox = NULL;

        if (*inicio == NULL) {

            *inicio = e;

        } else {

            struct no *p;

            p = *inicio;

            while (p->prox != NULL) {

                p = p->prox;

            }

            p->prox = e;

        }

        printf("\nElemento '%i' inserido na fila (insert) com sucesso.", e->info);

    }

}

// Funcao queueDelete
void queueDelete(struct no **inicio) {

    if (*inicio == NULL) {

        printf("\nA fila está vazia (empty).");

    } else {

        struct no *p;

        p = *inicio;
        *inicio = p->prox;

        printf("\nO primeiro elemento da fila '%i' foi removido", p->info);
        free(p);

    }

}

// Funcao queueClear
void queueClear(struct no **inicio) {

    if (*inicio == NULL) {

        printf("\nA fila está vazia (empty).");

    } else {

        struct no *p;

        while (*inicio != NULL) {

            p = *inicio;
            *inicio = p->prox;

            printf("\nApagando o elemento '%i'", p->info);

            free(p);

        }
    }

}
