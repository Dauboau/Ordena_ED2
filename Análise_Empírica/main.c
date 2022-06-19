#include <stdio.h>
#include <stdlib.h>
#include "declara.h"
#include <time.h>

#define min_e 1000 // número de entradas inicial
#define max_e 100000 // número de entradas final

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
  for(int dig=1;dig<=10;dig++){

    // max comporá o intervalo fechado em 0 e aberto e max de números gerados pelo rand
    max=10*dig;

    // Repete-se para cada número de entradas do min_e ao max_e aumentando 10x a cada iteração
    for(int entradas=min_e;entradas<=max_e;entradas=entradas*10){
      time_taken=0;

      // 10 repetições para maior precisão do tempo médio de ordenação
      for(int rep=0;rep<10;rep++){

        srand(time(NULL)); // reinicia o rand a cada iteração
        aleat_0=rand()%max; // início do intervalo a ser ordenado
        matriz[0][0]=aleat_0;
        while(aleat_1<aleat_0){ // fim do intervalo (sempre maior ou igual ao início)
          aleat_1=rand()%max;
        }
        matriz[0][1]=aleat_1;

        t = clock(); // começa a medir o tempo
        OrdenaNumeros(matriz,entradas); 
        t = clock() - t; // guarda o intervalo de tempo = tempo de ordenação
        time_taken = time_taken+((double)t)/CLOCKS_PER_SEC; // tempo transformado para segundos

      }
      // Guarda no arquivo Análise_Empírica.csv os dados coletados para posterior tratamento
      // número de entradas,número de digitos,tempo médio de ordenação
      fprintf(arq,"%d,%d,%f\n",entradas,dig,time_taken/10);

    }
  }

  LiberaMatriz(matriz, max_e);

}