#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "declara.h"

/*

  Arquivo usado para a análise empírica da função "ContagemLeituras"

  Cada linha 'ciclos_ini = clock()' armazena a contagem de clocks
  Ja as linas 'soma_ciclos += clock() - ciclos_ini' armazenam a quantidade de ciclos de clock
discorridos durante a execução da função.
  Por fim, a operação ((double) soma_ciclos) / CLOCKS_PER_SEC) retorna o tempo, em segundos,
de execução da função.

*/

int main(void){

  FILE* fd;
  fd = fopen("dados_contagem_leituras.txt", "w");
  
  clock_t ciclos_ini, soma_ciclos = 0;

  fprintf(fd, "(genoma_grande.txt, pos_genes_grande.csv, fragmentos_pequeno.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_grande.txt", "pos_genes_grande.csv", "pos_fragmentos(1).csv", "fragmentos_pequeno.txt", 10000, 300, "atividade_genica(1).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);


  fprintf(fd, "(genoma_grande.txt, pos_genes_grande.csv, fragmentos_medio.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_grande.txt", "pos_genes_grande.csv", "pos_fragmentos(2).csv", "fragmentos_medio.txt", 10000, 3000, "atividade_genica(2).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);


  fprintf(fd, "(genoma_grande.txt, pos_genes_grande.csv, fragmentos_grande.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_grande.txt", "pos_genes_grande.csv", "pos_fragmentos(3).csv", "fragmentos_grande.txt", 10000, 30000, "atividade_genica(3).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);


  fprintf(fd, "(genoma_grande.txt, pos_genes_pequeno.csv, fragmentos_grande.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_grande.txt", "pos_genes_pequeno.csv", "pos_fragmentos(4).csv", "fragmentos_grande.txt", 100, 30000, "atividade_genica(4).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);
  
  fprintf(fd, "(genoma_grande.txt, pos_genes_medio.csv, fragmentos_grande.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_grande.txt", "pos_genes_medio.csv", "pos_fragmentos(5).csv", "fragmentos_grande.txt", 1000, 30000, "atividade_genica(5).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);
  
  fprintf(fd, "(genoma_grande.txt, pos_genes_grande.csv, fragmentos_grande.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_grande.txt", "pos_genes_grande.csv", "pos_fragmentos(6).csv", "fragmentos_grande.txt", 10000, 30000, "atividade_genica(6).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);

  fprintf(fd, "(genoma_pequeno.txt, pos_genes_grande.csv, fragmentos_grande.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_pequeno.txt", "pos_genes_grande.csv", "pos_fragmentos(7).csv", "fragmentos_grande.txt", 10000, 30000, "atividade_genica(7).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);
  
  fprintf(fd, "(genoma_medio.txt, pos_genes_grande.csv, fragmentos_grande.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_medio.txt", "pos_genes_grande.csv", "pos_fragmentos(8).csv", "fragmentos_grande.txt", 10000, 30000, "atividade_genica(8).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);
  
  fprintf(fd, "(genoma_grande.txt, pos_genes_grande.csv, fragmentos_grande.txt)\n");
  ciclos_ini = clock();
  Contagem_Leituras("genoma_grande.txt", "pos_genes_grande.csv", "pos_fragmentos(9).csv", "fragmentos_grande.txt", 10000, 30000, "atividade_genica(9).txt");
  soma_ciclos += clock() - ciclos_ini;
  fprintf(fd, "%lf\n", ((double) soma_ciclos) / CLOCKS_PER_SEC);

  fclose(fd);
  return 0;

}