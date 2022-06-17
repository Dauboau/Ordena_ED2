#include <stdio.h>
#include <stdlib.h>
#include "declara.h"

int main(void) {

  int n=3;
  int** matriz = AlocaMatriz(n,2);
  matriz[0][0]=212;
  matriz[0][1]=4;
  matriz[1][0]=22;
  matriz[1][1]=9;
  matriz[2][0]=23;
  matriz[2][1]=6;

  OrdenaNumeros(matriz, n);

  for(int i=0;i<n;i++){
    printf("%d %d\n",matriz[i][0],matriz[i][1]);
  }

}

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