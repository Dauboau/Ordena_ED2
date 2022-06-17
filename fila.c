#include <stdio.h>
#include <stdlib.h>
#include "declara.h"  //inclui os Prot�tipos

// Cria a fila
Fila* cria_fila()
{
    Fila* pi = (Fila*) malloc(sizeof(Fila));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

// Insere no final da fila
int insere_fila(Fila* fila, Tipo_Dado ini,Tipo_Dado fim)
{
    if(fila == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dado[0] = ini;
    no->dado[1] = fim;
    no->prox = NULL;
    if((*fila) == NULL){ //fila vazia: insere no início
        *fila = no;
    }else{
        Elem *aux;
        aux = *fila;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

// Pega o dado solicitado do primeiro da fila
int primeiro_fila(Fila* pi,int p){

  if(pi == NULL)
    return -1;

  if((*pi) == NULL) //lista vazia
    return -1;

  Elem *no = *pi;

  return  no->dado[p];
  
}

// Remove o primeiro da fila
int remove_fila(Fila* pi)
{
    if(pi == NULL)
        return 0;
    if((*pi) == NULL) //lista vazia
        return 0;

    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

// Imprime a fila
void imprime_fila(Fila* pi)
{
    if(pi == NULL)
        return;
    printf("início da fila\n");
    Elem* no = *pi;
    while(no != NULL){
        printf("%d %d\n",no->dado[0],no->dado[1]);
        no = no->prox;
    }
    printf("fim da fila\n");
}