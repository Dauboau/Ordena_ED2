#include <stdio.h>
#include <stdlib.h>
#include "declara.h"  //inclui os Prot�tipos

// Cria a fila
Fila* cria_fila()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

// Insere no final da fila
int insere_fila(Fila* fi, Tipo_Dado ini,Tipo_Dado fim)
{
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dado[0]=ini;
    no->dado[1]=fim;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    return 1;
}

// Pega o dado solicitado do primeiro da fila
int primeiro_fila(Fila* fi,int p){

  if(fi == NULL)
    return -1;

  if((fi->inicio) == NULL) //lista vazia
    return -1;

  Elem *no = fi->inicio;

  return  no->dado[p];
  
}

// Remove o primeiro da fila
int remove_fila(Fila* fi)
{
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    return 1;
}

// Imprime a fila
void imprime_fila(Fila* fi)
{
    if(fi == NULL)
        return;
    printf("início da fila\n");
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("%d %d\n",no->dado[0],no->dado[1]);
        no = no->prox;
    }
    printf("fim da fila\n");
}