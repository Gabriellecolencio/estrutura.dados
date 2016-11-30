// Declaracao da constante que define o tamanho da pilha
#define tamanhoMaximo 50

// Declaracao da estrutura da pilha
struct pilha {

    char item[tamanhoMaximo];
    int topo;

};

// Iniciar a pilha
struct pilha * stackInit() {

    struct pilha *s;

    if ((s = malloc(sizeof(struct pilha))) == NULL) {

		printf("\nERRO: não foi possível alocar memória.");
		return NULL;

    } else {

        s->topo = -1;

    }

    return s;

}

// Funcao testaExpressao (inserir ou remover elementos na pilha)
int testaExpressao(struct pilha *s, char x) {

    int resultado = 1;

    if (s->topo == -1) {

        if ((x == '{') || (x == '[') || (x == '(')) {

            printf("\nOK: Caractere empilhado.");

            s->item[++(s->topo)] = x;

            printf("\ns->topo vale: %i", s->topo);

        } else {

            printf("\nERRO 1: Caractere não empilhado.");

            resultado = 0;

        }

    } else {

        switch (x) {

            case '{':

                if ((s->item[s->topo] == '[') || (s->item[s->topo] == '{')) {

                    printf("\nERRO 2: Caractere não empilhado.");

                    resultado = 0;

                } else {

                    printf("\nOK: Caractere empilhado.");

                    s->item[++(s->topo)] = x;

                    printf("\ns->topo vale: %i", s->topo);

                }

                break;

            case '[':

                if ((s->item[s->topo] == '(') || (s->item[s->topo] == '[')) {

                    printf("\nERRO 3: Caractere não empilhado.");

                    resultado = 0;

                } else {

                    printf("\nOK: Caractere empilhado.");

                    s->item[++(s->topo)] = x;

                    printf("\ns->topo vale: %i", s->topo);

                }

                break;

            case '(':

                if ((s->item[s->topo] == '{') || (s->item[s->topo] == '(')) {

                    printf("\nERRO 4: Caractere não empilhado.");

                    resultado = 0;

                } else {

                    printf("\nOK: Caractere empilhado.");

                    s->item[++(s->topo)] = x;

                    printf("\ns->topo vale: %i", s->topo);

                }

                break;

            case '}':

                if (s->item[s->topo] == '{') {

                    printf("\nOK: Caracteres conferem. Foram desempilhados.");

                    --(s->topo);

                    printf("\ns->topo vale: %i", s->topo);

                } else {

                    printf("\nERRO 5: Caractere não empilhado.");

                    resultado = 0;

                }

                break;

            case ']':

                if (s->item[s->topo] == '[') {

                    printf("\nOK: Caracteres conferem. Foram desempilhados.");

                    --(s->topo);

                    printf("\ns->topo vale: %i", s->topo);

                } else {

                    printf("\nERRO 6: Caractere não empilhado.");

                    resultado = 0;

                }

                break;

            case ')':

                if (s->item[s->topo] == '(') {

                    printf("\nOK: Caracteres conferem. Foram desempilhados.");

                    --(s->topo);

                    printf("\ns->topo vale: %i", s->topo);

                } else {

                    printf("\nERRO 7: Caractere não empilhado.");

                    resultado = 0;

                }

                break;

        }

    }

    return resultado;

}

// Funcao testaCaractere (testa a existencia dos caracteres '{[()]}')
void testaCaractere(struct pilha *s, char expressao[50]) {

    int resultado = 1, i = 0;

    while ((expressao[i] != '\0') && (resultado == 1)) {

        if ((expressao[i] == '{') || (expressao[i] == '}') || (expressao[i] == '[') || (expressao[i] == ']') || (expressao[i] =='(') || (expressao[i] == ')')) {

            printf("\nCaractere encontrado na posição %i: %c", i, expressao[i]);

            resultado = testaExpressao(s, expressao[i]);

        }

        i++;

    }

    if (resultado == 1) {

        printf("\nA expressão está correta.");

    } else {

        printf("\nA expressão está errada na posicao %i - '%c'.", i - 1, expressao[i - 1]);

    }

    s->topo = -1;

}

// Funcao digitarExpressao (insere uma expressao em um vetor "string")
void digitarExpressao(struct pilha *s) {

    char expressao[50];

    printf("Digite uma expressao numerica com maximo de 50 caracteres:\n\n>>>\t");
    fgets(expressao, 49, stdin);
    //getchar();

    testaCaractere(s, expressao);

}
