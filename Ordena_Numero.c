#include <stdio.h>
#include <stdlib.h>
#include "declara.h"

void OrdenaDigitos(int **A, int n, int pos){

    /*
        Entrada: A, matriz com duplas de n´umeros a serem ordenadas.
        Entrada: n, n´umero de linhas em A.
        Entrada: pos, posição do dígito a se considerar (10, 100, 1000, etc.).
    */

   // Criação das filas
   Fila* filas[10];
   for(int i=0;i<10;i++){
     filas[i]=cria_fila();
   }

   // Descobre o digito correspondente a posição desejada no número sendo lido
   int digito = 0;
   for (size_t i = 0; i < n; i++){
       digito = A[i][0]/pos;
       digito = digito%10;
       insere_fila(filas[digito],A[i][0],A[i][1]); // Insere o intervalo no final fila
   }

   // Tira os intervalos das filas do menor digito em diante
   int pos_a=0;
   for(int i=0;i<10;i++){
    while(primeiro_fila(filas[i],0)!=-1){
      // O primeiro inserido na fila é o primeiro a ser colocado na lista e assim por diante
      A[pos_a][0] = primeiro_fila(filas[i],0);
      A[pos_a][1] = primeiro_fila(filas[i],1);
      remove_fila(filas[i]);
      pos_a++;
    }
    free(filas[i]); // Limpa da memória o ponteiro apontando para as listas vazias
   }
}

void OrdenaNumeros(int **A, int n){
    
    /*
        Entrada: A[n][2], vetor com pares de n´umeros a serem ordenados.
        Entrada: n, n´umero de elementos em A.
        Obs: passar por referência uma matriz alocada dinamicamente.
    */

    // Descobre-se o maior número
    int maior = 0;
    for (size_t i = 0; i < n; i++){
      if(A[i][0] > maior)
        maior = A[i][0];
    }

    // Pelo número de digitos do maior número, se chama a ordenação com base nos digitos
    // do menos significativo ao mais significativo
    int pos = 1;
    while((maior/pos) > 1){  
      OrdenaDigitos(A, n, pos);

      if(debug){ // modo de debug
        printf("Início da Iteração:\n");
        for(int i=0;i<n;i++){
          printf("%d %d\n",A[i][0],A[i][1]);
        }
        printf("Fim da Iteração:\n");
      }

      pos = pos*10;
    }
}

int **AlocaMatriz(int m, int n){

  int **M;
 
  M = (int **)malloc(sizeof(int *)*m);

  if(M == NULL){

    printf("Memoria insuficiente.\n");
    exit(1);

  }

  for(int i = 0; i < m; i++){

    M[i] = (int *)malloc(sizeof(int)*n);

    if(M[i] == NULL){

      printf("Memoria insuficiente.\n");
      exit(1);

    }

  }

  return M;
}

void LiberaMatriz(int **M, int m){

  for(int i = 0; i < m; i++)
    free(M[i]);

  free(M);

}
