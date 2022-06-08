#include <stdio.h>
#include <stdlib.h>

#define debug 1

void OrdenaNumeros(int **A, int n);
int **AlocaMatriz(int m, int n);
void LiberaMatriz(int **M, int m);

void ContagemIntersecoes(char* file_a,char* file_b,int na,int nb,char* output_file){
  
  FILE *a = fopen(file_a,"r"); // Arquivo A.csv é aberto
  FILE *b = fopen(file_b,"r"); // Arquivo B.csv é aberto
  FILE *c = fopen(output_file,"w"); // Arquivo contagens.txt é aberto

  int **A = AlocaMatriz(na, 2); // Matriz A (intervalos em A)
  int **B = AlocaMatriz(nb, 2); // Matriz B (intervalos em B)

  // Guarda o número de interseções de B com A para cada intervalo de A
  int* contagens=malloc(sizeof(int)*na);
  for(int i=0;i<na;i++){
    contagens[i]=0;
  }

  // Lê o arquivo A e guarda na memória
  for(int i=0;i<na;i++){
  
    fscanf(a,"%d,%d",&A[i][0],&A[i][1]);

    if(debug){
      printf("%d %d\n",A[i][0],A[i][1]);
    }

  }

  if(debug){
      printf("\n");
  }

  // Lê o arquivo B e guarda na memória
  for(int i=0;i<nb;i++){
  
    fscanf(b,"%d,%d",&B[i][0],&B[i][1]);

    if(debug){
      printf("%d %d\n",B[i][0],B[i][1]);
    }

  }

  // Ordena os intervalos de A e de B
  OrdenaNumeros(A, na);
  OrdenaNumeros(B, nb);

  if(debug){
    printf("\n");

    for(int i=0;i<na;i++){
      printf("%d %d\n",A[i][0],A[i][1]);
    }

    printf("\n");

    for(int i=0;i<nb;i++){
      printf("%d %d\n",B[i][0],B[i][1]);
    }
  }

  // Verifica as interseções e faz a contagem delas
  int primeiro_iB=0;
  for(int ia=0;ia<na;ia++){
    for(int ib=primeiro_iB;ib<nb;ib++){
      if(A[ia][1]<B[ib][0] || A[ia][0]>B[ib][1]){
        if(contagens[ia]==0){
          primeiro_iB=ib;
        }
      }
      else{
        contagens[ia]++;
      }
    }
  }


  // Imprime na saida fornecida as contagens
  for(int i=0;i<na;i++){
    fprintf(c,"%d\n",contagens[i]);
  }
  
  
  fclose(a);
  fclose(b);
  free(contagens);
  
}

int main(void) {

  ContagemIntersecoes("A.csv","B.csv",3,7,"contagens.txt");

}

/*
  int **matriz = AlocaMatriz(3, 2);  

  matriz[0][0]=2;
  matriz[0][1]=8;
  matriz[1][0]=3;
  matriz[1][1]=4;
  matriz[2][0]=0;
  matriz[2][1]=12;

  OrdenaNumeros(matriz, 3);

  for (size_t i = 0; i < 3; i++){
    printf("%d, %d\n", matriz[i][0], matriz[i][1]);
  }
*/