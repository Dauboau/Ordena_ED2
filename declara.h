#define debug 1

void OrdenaNumeros(int **A, int n);
int **AlocaMatriz(int m, int n);
void LiberaMatriz(int **M, int m);
void ContagemIntersecoes(char* file_a,char* file_b,int na,int nb,char* output_file);
void Ctrl_F(FILE *arq_texto, FILE *arq_trechos, FILE *arq_saida);



// TAD

typedef int Tipo_Dado;

struct elemento{
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Pilha;


Pilha* cria_pilha();
void imprime_pilha(Pilha* li);
int remove_pilha(Pilha* li);
int insere_pilha(Pilha* li, Tipo_Dado dt);

/*
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista_ordenada(Lista* li, Tipo_Dado dt);
int remove_lista(Lista* li, Tipo_Dado dt);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el);
int consulta_lista_pos(Lista* li, int pos, Elem **el);
*/