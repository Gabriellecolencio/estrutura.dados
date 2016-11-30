// Declaracao da constante que define o tamanho da pilha
#define tamanhoMaximo 5

// Declaracao da estrutura da pilha
struct pilha {

    int item[tamanhoMaximo];
    int topo;

};

// Iniciar a pilha
struct pilha * stackInit() {

    struct pilha *s;

    if ((s = malloc(sizeof(struct pilha))) == NULL) {

		printf("\nERRO: não foi possível alocar memória.");

    } else {

        s->topo = -1;

    }

    return s;

}

// Funcao stackList (listar elementos da pilha)
void stackList(struct pilha *s) {

    int i;

    for (i = (s->topo); i > -1; i--) {

        printf("\n%i\t%i", i, s->item[i]);

    }

}

// Funcao stackPush (inserir elemento na pilha)
void stackPush(struct pilha *s, int x) {

    s->item[++(s->topo)] = x;

}

// Funcao stackPop (remover elemento da pilha)
int stackPop(struct pilha *s) {

    return(s->item[(s->topo)--]);

}
