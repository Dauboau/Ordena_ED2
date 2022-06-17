#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declara.h"

void Contagem_Leituras(char* arq_genoma, char* arq_pos_genes, char* arq_pos_fragmentos, char* arq_fragmentos, int n_genes, int n_fragmentos, char* arq_saida){
 
  Ctrl_F(arq_genoma, arq_fragmentos, arq_pos_fragmentos);
  ContagemIntersecoes(arq_pos_genes, arq_pos_fragmentos, n_genes, n_fragmentos, arq_saida);

}

/*
int main(void){

  Contagem_Leituras("genoma_pequeno.txt", "pos_genes_pequeno.txt", "pos_fragmentos.csv", "fragmentos_pequeno.txt", 100, 300, "atividade_genica.txt");

}
*/