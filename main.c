#include <stdio.h>
#include <stdlib.h>
#include "declara.h"

int main(void) {

  ContagemIntersecoes("A.csv","B.csv",3,7,"contagens.txt");

  Pilha* pilha=cria_pilha();

  insere_pilha(pilha, 27);
  insere_pilha(pilha, 14);
  insere_pilha(pilha, 34);

  remove_pilha(pilha);

  imprime_pilha(pilha);

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