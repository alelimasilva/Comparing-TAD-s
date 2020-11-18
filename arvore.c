#include"arvore.h"
#include<stdio.h>
#include<stdlib.h>

void pesquisar(Registro *x, Apontador p){
    if (p == NULL){
        printf("Erro: Registro nao esta presente na arvore\n");
        return;
    }
    if (x->chave < p->registro.chave){
        pesquisar(x, p->esq);
    }else if (x->chave > p->registro.chave)
        pesquisar(x, p->dir);
    else{
    *x = p->registro;
    }
}

void inserir(Registro x, Apontador *p){
    if (*p == NULL) {
        *p = (Apontador)malloc(sizeof(No));
        (*p)->registro = x; (*p)->esq = NULL; (*p)->dir = NULL;
        return;
    }
    if (x.chave < (*p)->registro.chave){
        inserir(x, &(*p)->esq); return;
    } else if (x.chave > (*p)->registro.chave)
        inserir(x, &(*p)->dir);
    else {
        printf("Erro : Registro ja existe na arvore\n");
    }
}

void inicializar(Apontador *dicionario){
    *dicionario = NULL;
}

void retirar(Registro x, Apontador *p){
    Apontador aux;
    if (*p == NULL) {
        printf("Erro : Registro nao esta na arvore\n");
    } else if (x.chave < (*p)->registro.chave){
        retirar(x, &(*p)->esq); return;
    } else if (x.chave > (*p)->registro.chave){
        retirar(x, &(*p)->dir); return;
    } else if ((*p)->dir == NULL){
        aux = *p;
        *p = (*p)->esq;
        free(aux);
    }else if ((*p)->esq == NULL){
        aux = *p;
        *p = (*p)->dir;
        free(aux);
    }
    else{
        antecessor(*p, &(*p)->esq);
    }
}

void antecessor(Apontador q, Apontador *r){
    if ((*r)->dir != NULL) {
        antecessor(q, &(*r)->dir);
        return;
    } else{
        q->registro = (*r)->registro;
        q = *r;
        *r = (*r)->esq;
        free(q);
    }
}

