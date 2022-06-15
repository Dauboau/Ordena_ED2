#include <stdio.h>
#include <stdlib.h>
#include "declara.h"  //inclui os Prot�tipos

Pilha* cria_pilha()
{
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

int insere_pilha(Pilha* pi, Tipo_Dado dt)
{
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dado = dt;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_pilha(Pilha* pi)
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

void imprime_pilha(Pilha* pi)
{
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("%d\n",no->dado);
        no = no->prox;
    }
}

/*
void libera_lista(Lista* li)
{
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
*/

/*
int consulta_lista_pos(Lista* li, int pos, Elem **el)
{
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *el = no;
        return 1;
    }
}
*/

/*
int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el)
{
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dado != dt){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *el = no;
        return 1;
    }
}
*/

/*
int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dado = dt;
    no->prox = NULL;
    if((*li) == NULL){ //lista vazia: insere in�cio
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}
*/

/*
int insere_lista_ordenada(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dado = dt;
    if((*li) == NULL){ //lista vazia: insere in�cio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dado < dt){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ //insere in�cio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}
*/

/*
int remove_lista(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dado != dt){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) //n�o encontrado
        return 0;

    if(no == *li) //remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}
*/

/*
int remove_lista_final(Lista* li)
{
    if(li == NULL)
        return 0;
    if((*li) == NULL) //lista vazia
        return 0;

    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li)) //remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}
*/

/*
int tamanho_lista(Lista* li)
{
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li)
{
    return 0;
}

int lista_vazia(Lista* li)
{
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}
*/