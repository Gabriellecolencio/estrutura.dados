// Declaracao da constante que define o tamanho da fila
#define tamanhoMaximo 7

// Declaracao da estrutura da fila
struct no {

    unsigned char info;
    struct no *prox;

};

// Funcao printHash (imprime a tabela hash)
void printHash(struct no *vetorIndice[tamanhoMaximo]) {

    int i;

    struct no *p;

    for (i=0; i<tamanhoMaximo; i++){

        printf("\n\nLista %d: ", i);
        p = vetorIndice[i];

        while(p != NULL) {

            printf("%c\t", p->info);
            p = p->prox;

        }

    }

}

// Funcao insertHash (insere uma chave na tabela hash)
void insertHash(struct no *vetorIndice[tamanhoMaximo], char info) {

    struct no *e;

    if ((e = malloc(sizeof(struct no))) == NULL) {

        printf("ERRO: não foi possível alocar memória.\nA fila está cheia (full).");

    } else {

        e->info = info;
        e->prox = NULL;

        printf("\ncaracter: %c\ninteiro: %i\nchave: %i", e->info, e->info, e->info - 65);

        int indice = ((e->info - 65) % tamanhoMaximo);

        printf("\nindice: %i", indice);

        if (vetorIndice[indice] == NULL) {

            //printf("ponteiro antes - %p\n", vetorIndice[indice]);
            vetorIndice[indice] = e;
            //printf("ponteiro depois - %p\n", vetorIndice[indice]);

        } else {

            struct no *p;

            p = vetorIndice[indice];

            while (p->prox != NULL) {

                p = p->prox;

            }

            p->prox = e;

        }

        printf("\nElemento '%c' inserido na fila (insert) da Tabela Hash com sucesso.\n", e->info);

    }

}
