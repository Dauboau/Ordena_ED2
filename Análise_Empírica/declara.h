#define debug 0

void OrdenaNumeros(int **A, int n);
int **AlocaMatriz(int m, int n);
void LiberaMatriz(int **M, int m);

// TAD

typedef int Tipo_Dado;

struct elemento{
    Tipo_Dado dado[2];
    struct elemento *prox;
};

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

typedef struct elemento Elem;

typedef struct fila Fila;

Fila* cria_fila();
void imprime_fila(Fila* li);
int remove_fila(Fila* li);
int insere_fila(Fila* li, Tipo_Dado ini,Tipo_Dado fim);
int primeiro_fila(Fila* pi,int p);
