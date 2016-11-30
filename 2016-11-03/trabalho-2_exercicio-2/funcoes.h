// Declaracao da constante que define o tamanho da fila
#define tamanhoMaximo 6

// Declaracao da estrutura da fila
struct fila {

    int item[tamanhoMaximo];
    int queueFront, queueRear;

};

// Iniciar a fila
struct fila * queueInit() {

    struct fila *q;

    if ((q = malloc(sizeof(struct fila))) == NULL) {

		printf("\nERRO: não foi possível alocar memória.");

    } else {

        q->queueFront = q->queueRear = 0;

    }

    return q;

}

// Funcao queueList (listar elementos da fila)
void queueList(struct fila *q) {

    int i = q->queueFront;

    do {

        if (i == (tamanhoMaximo - 1)) {

            i = 0;

        } else {

            i++;

        }

        printf("\n%i\t%i", i, q->item[i]);

    } while (i != (q->queueRear));

}

// Funcao queueSize (resultar o numero de elementos na fila)
int queueSize(struct fila *q) {

    if (q->queueRear > q->queueFront) {

        return q->queueRear - q->queueFront;

    } else {

        return tamanhoMaximo - q->queueFront + q->queueRear;

    }

}

// Funcao queueInsert (inserir elemento na fila)
void queueInsert(struct fila *q, int x) {

    q->queueRear = (q->queueRear + 1) % tamanhoMaximo;
    q->item[q->queueRear] = x;

    printf("\nFront: %i \t Rear: %i \t Item: %i\n", q->queueFront, q->queueRear, q->item[q->queueRear]);

}

// Funcao queueDelete (remover elemento da fila)
int queueDelete(struct fila *q) {

    q->queueFront = ((q->queueFront + 1) % tamanhoMaximo);
    return(q->item[q->queueFront]);

}
