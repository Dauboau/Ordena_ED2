#include <stdio.h>
#include <stdlib.h>
#include "declara.h"

int main(void) {
  
  int n=3;
  int** matrizx = AlocaMatriz(n,2);
  matrizx[0][0]=212;
  matrizx[0][1]=4;
  matrizx[1][0]=22;
  matrizx[1][1]=9;
  matrizx[2][0]=23;
  matrizx[2][1]=6;

  OrdenaNumeros(matrizx,n);

  for(int i=0;i<n;i++){
    printf("%d %d\n",matrizx[i][0],matrizx[i][1]);
  }

  //time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

  //fprintf(arq,"%f\n",time_taken);

  //Contagem_Leituras("genoma_pequeno.txt", "pos_genes_pequeno.txt", "pos_fragmentos.csv", "fragmentos_pequeno.txt", 100, 300, "atividade_genica.txt");

}

// Complexidade em função de m(número de figitos) e n(tamanho da entrada)
  /*
  int n=3;
  int** matriz = AlocaMatriz(n,2);
  matriz[0][0]=212;
  matriz[0][1]=4;
  matriz[1][0]=22;
  matriz[1][1]=9;
  matriz[2][0]=23;
  matriz[2][1]=6;
  */

 /*
  for(int i=0;i<n;i++){
    printf("%d %d\n",matriz[i][0],matriz[i][1]);
  }
  */

  //ContagemIntersecoes("A.csv","B.csv",3,7,"contagens.txt");

/*
FILE *texto, *trechos, *saida;
    texto = fopen("texto.txt", "r");
    trechos = fopen("trechos.txt", "r");
    saida = fopen("saida.txt", "a");

    Ctrl_F(texto, trechos, saida);

    fclose(texto);
    fclose(trechos);
    fclose(saida);

    return 0;
    */

 /*
  int n=3;
  int** matrizx = AlocaMatriz(n,2);
  matrizx[0][0]=212;
  matrizx[0][1]=4;
  matrizx[1][0]=22;
  matrizx[1][1]=9;
  matrizx[2][0]=23;
  matrizx[2][1]=6;

  OrdenaNumeros(matrizx,n);

  for(int i=0;i<n;i++){
    printf("%d %d\n",matrizx[i][0],matrizx[i][1]);
  }
  */