#include <stdio.h>
#include <stdlib.h>
#include "declara.h"

#include <time.h>

#define min_e 1000
#define max_e 1000000

int main(void) {
  
  FILE *arq = fopen("Análise_Empírica.csv","w");
  double time_taken;
  clock_t t;
  int aleat_0;
  int aleat_1=-1;
  int max;
  int** matriz=AlocaMatriz(max_e,2);

  for(int dig=1;dig<=10;dig++){
    max=10*dig;
    for(int entradas=min_e;entradas<=max_e;entradas=entradas*10){
      time_taken=0;

      for(int rep=0;rep<10;rep++){
        srand(time(NULL));
        aleat_0=rand()%max;
        matriz[0][0]=aleat_0;
        while(aleat_1<aleat_0){
          aleat_1=rand()%max;
        }
        matriz[0][1]=aleat_1;

        t = clock();
        OrdenaNumeros(matriz,entradas);
        t = clock() - t;
        time_taken = time_taken+((double)t)/CLOCKS_PER_SEC;
      }
      fprintf(arq,"%d,%d,%f\n",entradas,dig,time_taken/10); // em segundos
    }
  }

  LiberaMatriz(matriz, max_e);
  

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