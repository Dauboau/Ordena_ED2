#define debug 0

void OrdenaNumeros(int **A, int n);
int **AlocaMatriz(int m, int n);
void LiberaMatriz(int **M, int m);
void ContagemIntersecoes(char* file_a,char* file_b,int na,int nb,char* output_file);
void Ctrl_F(char* nome_texto, char* nome_trechos, char* nome_saida);
void Contagem_Leituras(char* arq_genoma, char* arq_pos_genes, char* arq_pos_fragmentos, char* arq_fragmentos, int n_genes, int n_fragmentos, char* arq_saida);



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
