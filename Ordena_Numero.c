#include <stdio.h>
#include <stdlib.h>
#include "declara.h"

void OrdenaDigitos(int **A, int n, int pos){

    /*
        Entrada: A, matriz com duplas de n´umeros a serem ordenadas.
        Entrada: n, n´umero de linhas em A.
        Entrada: posicao, posi¸c˜ao do d´ıgito a se considerar (10, 100, 1000, etc.).
    */

   int B[10] = {0,0,0,0,0,0,0,0,0,0};
   int digito = 0;

   for (size_t i = 0; i < n; i++){
       
       digito = A[i][0]/pos;
       digito = digito%10;
       B[digito] = B[digito]+1;

   }

   for (size_t i = 1; i <= 9; i++){

      B[i] = B[i] + B[i-1];

   }

   int C[n][2];

   for (size_t i = n-1; i >= 0; i--){

    digito = A[i][0]/pos;
    digito = digito%10;
    B[digito] = B[digito]-1;
    C[B[digito]][0] = A[i][0];
    C[B[digito]][1] = A[i][1];

    //gambiarra que ta fznd funcionar
    if(i==0)
      break;

   }
   
   for (size_t i = 0; i < n; i++){

      A[i][0] = C[i][0];
      A[i][1] = C[i][1];

   }
   
   
   
}

void OrdenaNumeros(int **A, int n){
    
    /*
        Entrada: A[n][2], vetor com pares de n´umeros a serem ordenados.
        Entrada: n, n´umero de elementos em A.
        Obs: passar por referência uma matriz alocada dinamicamente.
    */

    int maior = 0;

    for (size_t i = 0; i < n; i++){

      if(A[i][0] > maior)
        maior = A[i][0];
        
    }

    int pos = 1;

    while((maior/pos) > 1){
        
      OrdenaDigitos(A, n, pos);
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
