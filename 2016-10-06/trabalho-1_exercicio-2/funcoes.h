// Decalaração da estrutura da lista
struct no {

    char nome[51];
    struct no *prox;

};

// Funcao iniciarLista
struct no * iniciarLista() {

    struct no *cabeca;

    if ((cabeca = malloc(sizeof(struct no))) == NULL) {

        printf("\n---------------------------------\nERRO: Não foi possível alocar memória.\n---------------------------------\n");

    } else {

        strcpy(cabeca->nome, "cabeca");
        cabeca->prox = cabeca;

    }

    return cabeca;

}

// Funcao imprimirComecoFim
void imprimirComecoFim(struct no *cabeca) {

    struct no *p;
    int i = 1;

    p = cabeca->prox;

    printf("\n---------------------------------\nParticipantes do sorteio:\n---------------------------------\n");

    while (p != cabeca) {

        printf("%iº - %s", i, p->nome);
        p = p->prox;
        ++i;

    }

    printf("---------------------------------\n");

}

// Funcao cadastrarParticipante
void cadastrarParticipante(struct no *cabeca) {

    struct no *participante;

    if ((participante = malloc(sizeof(struct no))) == NULL) {

        printf("\n---------------------------------\nERRO: Não foi possível alocar memória.\n---------------------------------\n");

    } else {

        printf("\n---------------------------------\nOK: Informe o nome do participante.\n---------------------------------\n");
        printf("NOME:\t");
        fgets(participante->nome, 50, stdin);

        participante->prox = cabeca;

        struct no *p;

        p = cabeca;

        while (p->prox != cabeca) {

            p = p->prox;

        }

        p->prox = participante;

        printf("\n---------------------------------\nNovo participante inserido com sucesso.\n---------------------------------\n");

    }

}

// Funcao buscarParticipante
struct no * buscarParticipante(struct no *cabeca, char nome[51]) {

    struct no *p, *anterior = NULL;
    int terminouBusca = 0;

    p = cabeca;

    do {

        if (strcmp(nome, p->prox->nome) == 0) {

            printf("\n---------------------------------\nO sorteio começará por:\n---------------------------------\n");
            printf("%s", p->prox->nome);
            printf("---------------------------------\n");

            anterior = p;
            terminouBusca = 1;

        } else {

            if (p->prox->prox == cabeca) {

                printf("\n---------------------------------\nParticipante não encontrado.\n---------------------------------\n");

                terminouBusca = 1;

            } else {

                p = p->prox;

            }

        }

    } while (terminouBusca == 0);

    return anterior;

}

// Funcao sortearViagem
void sortearViagem(struct no *cabeca) {

    struct no *anterior = NULL, *atual;
    char nome[51];
    unsigned int m = 0;
    int eliminado = 0, vencedor = 0, i;

    while (anterior == NULL) {

        printf("\n---------------------------------\nQual participante dará inicio ao sorteio?\n---------------------------------\n");
        printf("NOME:\t");
        fgets(nome, 50, stdin);

        anterior = buscarParticipante(cabeca, nome);

    }

    printf("\n---------------------------------\nInforme um numero inteiro maior que zero.\n---------------------------------\n");
    printf("M: ");
    scanf("%u", &m);

    printf("\n---------------------------------\nELIMINADOS PELA ORDEM\n---------------------------------\n");
    printf("Ord.:\tNOME:\n");

    while (vencedor == 0) {

        atual = anterior->prox;

        if ((anterior == cabeca) && (atual->prox == cabeca)) {

            vencedor = 1;

        } else {

            for (i = 2; i <= m; i++) {

                if (atual->prox == cabeca) {

                    anterior = cabeca;
                    atual = cabeca->prox;

                } else {

                    anterior = atual;
                    atual = atual->prox;

                }

                //printf("%i - nao - %s", i, atual->nome);

            }

            if (atual->prox == cabeca) {

                anterior->prox = cabeca;
                anterior = cabeca;

            } else {

                anterior->prox = atual->prox;

            }

            ++eliminado;

            printf("%iº\t%s", eliminado, atual->nome);
            free(atual);

        }

    }

    printf("\n---------------------------------\nO(A) GRANDE VENCEDOR(A)\n---------------------------------\n");
    printf("%s", cabeca->prox->nome);
    printf("Arrume as malas.\n---------------------------------\n");

}

// Funcao limpaMemoria
void limpaMemoria(struct no *cabeca) {

    struct no *p;

    p = cabeca->prox;

    while (p != cabeca) {

        cabeca->prox = p->prox;

        free(p);

        p = cabeca->prox;

    }

    free(p);

}
