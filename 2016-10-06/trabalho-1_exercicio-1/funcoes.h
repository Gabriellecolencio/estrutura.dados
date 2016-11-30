// Decalaracao da estrutura da lista
struct no {

    unsigned int numero;
    char nome[51], rua[51], cidade[51], estado[3];
    struct no *dir, *esq;

};


// Funcao listarPessoas
void listarPessoas(struct no *inicio) {

    if (inicio == NULL) {

        printf("\n---------------------------------\nNão existem pessoas na lista.\n---------------------------------\n");

    } else {

        struct no *p;
        int posicao = 0;

        p = inicio;

        printf("\n---------------------------------\nPOS.:\tNOME:\n");

        while (p != NULL) {

            ++posicao;

            printf("%i\t%s", posicao, p->nome);

            p = p->dir;

        }

        printf("---------------------------------\n");

    }

}

// Funcao buscarPessoa
void buscarPessoa(struct no *inicio) {

    if (inicio == NULL) {

        printf("\n---------------------------------\nNão existem pessoas na lista.\n---------------------------------\n");

    } else {

        char nome[51];
        struct no *p;
        int terminouBusca = 0;

        printf("\n---------------------------------\nOK: Informe o nome da pessoa.\n---------------------------------\n");
        printf("NOME:\t");
        fgets(nome, 50, stdin);

        p = inicio;

        do {

            if (strcmp(nome, p->nome) == 0) {

                printf("\n---------------------------------\nPessoa encontrada na lista:\n---------------------------------\n");
                printf("NOME:\t%s", p->nome);
                printf("RUA:\t%s", p->rua);
                printf("NUMERO:\t%i\n", p->numero);
                printf("CIDADE:\t%s", p->cidade);
                printf("ESTADO:\t%s", p->estado);
                printf("\n---------------------------------\n");

                terminouBusca = 1;

            } else {

                if (p->dir == NULL) {

                    printf("\n---------------------------------\nPessoa não encontrada na lista.\n---------------------------------\n");

                    terminouBusca = 1;

                } else {

                    p = p->dir;

                }

            }

        } while (terminouBusca == 0);

    }

}

// Funcao inserirPessoa
void inserirPessoa(struct no **inicio) {

    struct no *novaPessoa;

    if ((novaPessoa = malloc(sizeof(struct no))) == NULL) {

        printf("\n---------------------------------\nERRO: Não foi possível alocar memória.\n---------------------------------\n");

    } else {

        printf("\n---------------------------------\nOK: Informe os dados da pessoa.\n---------------------------------\n");
        printf("NOME:\t");
        fgets(novaPessoa->nome, 50, stdin);
        printf("RUA:\t");
        fgets(novaPessoa->rua, 50, stdin);
        printf("NUMERO:\t");
        scanf("%u", &novaPessoa->numero);
        getchar();
        printf("CIDADE:\t");
        fgets(novaPessoa->cidade, 50, stdin);
        printf("ESTADO:\t");
        fgets(novaPessoa->estado, 3, stdin);
        getchar();

        if (*inicio == NULL) {

            *inicio = novaPessoa;
            novaPessoa->esq = NULL;
            novaPessoa->dir = NULL;

        } else {

            int encontrouPosicao = 0;
            struct no *p;

            p = *inicio;

            do {

                if (strcmp(novaPessoa->nome, p->nome) < 0) {

                    if (p->esq == NULL) {

                        *inicio = novaPessoa;

                    } else {

                        p->esq->dir = novaPessoa;

                    }

                    novaPessoa->dir = p;
                    novaPessoa->esq = p->esq;
                    p->esq = novaPessoa;
                    encontrouPosicao = 1;

                } else {

                    if (p->dir == NULL) {

                        p->dir = novaPessoa;
                        novaPessoa->esq = p;
                        novaPessoa->dir = NULL;
                        encontrouPosicao = 1;

                    } else {

                        p = p->dir;

                    }

                }

            } while (encontrouPosicao == 0);

        }

        printf("\n---------------------------------\nNova pessoa inserida na lista com sucesso.\n---------------------------------\n");

    }

}

// Funcao removerPessoa
void removerPessoa(struct no **inicio) {

    if (*inicio == NULL) {

        printf("\n---------------------------------\nNão existem pessoas na lista.\n---------------------------------\n");

    } else {

        char nome[51];
        struct no *p;
        int terminouBusca = 0;

        printf("\n---------------------------------\nOK: Informe o nome da pessoa que deseja remover.\n---------------------------------\n");
        printf("NOME:\t");
        fgets(nome, 50, stdin);

        p = *inicio;

        do {

            if (strcmp(nome, p->nome) == 0) {

                /*printf("\n---------------------------------\nPessoa encontrada na lista:\n---------------------------------\n");
                printf("NOME:\t%s", p->nome);
                printf("RUA:\t%s", p->rua);
                printf("NUMERO:\t%i\n", p->numero);
                printf("CIDADE:\t%s", p->cidade);
                printf("ESTADO:\t%s", p->estado);
                printf("\n---------------------------------\n");*/

                if ((p->esq == NULL) && (p->dir == NULL)) {

                    *inicio = NULL;

                } else {

                    if (p->esq == NULL) {

                        *inicio = p->dir;
                        p->dir->esq = NULL;

                    } else {

                        if (p->dir == NULL) {

                            p->esq->dir = NULL;

                        } else {

                            p->esq->dir = p->dir;
                            p->dir->esq = p->esq;

                        }

                    }

                }

                free(p);

                printf("\n---------------------------------\n%s", nome);
                printf("foi removido(a) da lista.\n---------------------------------\n");

                terminouBusca = 1;

            } else {

                if (p->dir == NULL) {

                    printf("\n---------------------------------\nPessoa não encontrada na lista.\n---------------------------------\n");

                    terminouBusca = 1;

                } else {

                    p = p->dir;

                }

            }

        } while (terminouBusca == 0);

    }

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
