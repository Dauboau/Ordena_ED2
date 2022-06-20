#include <stdio.h>
#include <stdlib.h>
#include "declara.h"
#include <time.h>
#include <math.h>

#define min_e 1000 // número de entradas inicial
#define max_e 10000000 // número de entradas final

int main(void) {
  
  // Abre o arquivo onde armazena-se os dados
  FILE *arq = fopen("Análise_Empírica.csv","w");

  // Variáveis importantes
  double time_taken; // Guarda o tempo em s
  clock_t t;
  int aleat_0;
  int aleat_1=-1;
  int max;
  int** matriz=AlocaMatriz(max_e,2);

  // Repete-se para cada digito
  for(int dig=1;dig<=9;dig++){

    // max comporá o intervalo fechado em 0 e aberto e max de números gerados pelo rand
    max=pow(10,dig-1);

    // Repete-se para cada número de entradas do min_e ao max_e aumentando 10x a cada iteração
    for(int entradas=min_e;entradas<=max_e;entradas=entradas*10){
      time_taken=0;

      // 3 repetições para maior precisão do tempo médio de ordenação
      for(int rep=0;rep<3;rep++){
        
        srand(time(NULL));
        for(int i=0;i<entradas;i++){
          matriz[i][0]=(rand()%10)*max;
          matriz[i][1]=2*max;
        }

        t = clock(); // começa a medir o tempo
        OrdenaNumeros(matriz,entradas); 
        t = clock() - t; // guarda o intervalo de tempo = tempo de ordenação
        time_taken = time_taken+((double)t)/CLOCKS_PER_SEC; // tempo transformado para segundos
      }
      // Guarda no arquivo Análise_Empírica.csv os dados coletados para posterior tratamento
      // número de entradas,número de digitos,tempo médio de ordenação
      fprintf(arq,"%d,%d,%f\n",entradas,dig,time_taken/3);
    }
  }


  LiberaMatriz(matriz, max_e);

}