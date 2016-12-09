// Declaracao da estrutura da pilha
struct no {

    int info;
    struct no *prox;

};

// Funcao listStack (listar elementos da pilha)
void listStack(struct no *topo) {

    if (topo == NULL) {

        printf("\nA pilha está vazia (empty).");

    } else {

        struct no *p;

        p = topo;

        printf("\nElementos na pilha:\n");

        while (p != NULL) {

            printf("%i ", p->info);
            p = p->prox;

        }

    }

}

// Funcao sizeStack (mostrar o tamanho da pilha)
int sizeStack(struct no *topo) {

    int tamanho = 0;
    struct no *p;

    p = topo;

    while (p != NULL) {

        ++tamanho;
        p = p->prox;

    }

    return tamanho;

}

// Funcao pushStack (inserir elemento na pilha)
void pushStack(struct no **topo) {

    struct no *e;

    if ((e = malloc(sizeof(struct no))) == NULL) {

		printf("\n\n\n---------------------------------\nERRO: não foi possível alocar memória\n---------------------------------\n");

    } else {

        printf("\nDigite um número inteiro: ");
        scanf("%i", &e->info);
        getchar();

        if (*topo == NULL) {

            *topo = e;
            e->prox = NULL;

        } else {

            e->prox = *topo;
            *topo = e;

        }

        printf("\nO elemento '%i' foi inserido na pilha com sucesso.", e->info);

    }

}

// Funcao popStack (remover elemento da pilha)
void popStack(struct no **topo) {

    if (*topo == NULL) {

        printf("\nA pilha está vazia (empty).");

    } else {

        struct no *p;
        int x;

        p = *topo;
        x = p->info;
        *topo = p->prox;

        free(p);

        printf("\nO elemento '%i' foi removido.", x);

    }

}

// Funcao clearStack (limpar a lista)
void clearStack(struct no **topo) {

    if (*topo == NULL) {

        printf("\nA pilha está vazia (empty).");

    } else {

        struct no *p;
        int x;

        while (*topo != NULL) {

            p = *topo;
            *topo = p->prox;
            x = p->info;

            free(p);

            printf("\nO elemento '%i' foi removido.", x);

        }

    }
}
