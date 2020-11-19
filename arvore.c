#include"arvore.h"
#include<stdio.h>
#include<stdlib.h>

void pesquisar(Registro *x, Apontador p){
    if (p == NULL){ //condição de saida da recursao caso nao seja encontrado o valor
        printf("Erro: Registro nao esta presente na arvore\n");
        return;
    }
    if (x->chave < p->registro.chave){ //analisa se a chave do registro a ser procurado é menor do que a chave do no
        pesquisar(x, p->esq); // procura novamente no nó filho a esquerda
    }
    else if (x->chave > p->registro.chave){  //analisa se a chave do registro a ser procurado é maior do que a chave do no
        pesquisar(x, p->dir); // procura novamente no nó filho a direita
    }
    else{// se o valor for encontrado
        printf("Registro encontrado na arvore\n");
        *x = p->registro; // o registro x recebe o registro da nó encontrado
    }
}

void inserir(Registro x, Apontador *p){
    if (*p == NULL){ // so insere se o que p aponta for NULL
        *p = (Apontador)malloc(sizeof(No)); // p passa a apontar para um no
        (*p)->registro = x; (*p)->esq = NULL; (*p)->dir = NULL; // adiciona os valores e o esq e dir dele se tornam NULL
        return;
    }
    if (x.chave < (*p)->registro.chave){ //analisa se a chave do registro a ser procurado é menor do que a chave do no
        inserir(x, &(*p)->esq); return; // entao tenta inserir no nó a esq 
    }
    else if (x.chave > (*p)->registro.chave){ //analisa se a chave do registro a ser procurado é maior do que a chave do no
        inserir(x, &(*p)->dir); // entao tenta inserir no nó a esq 
    }
    else{ //caso ele nao seja nem maior ou menor ele ja existe na arvore 
        printf("Erro : Registro ja existe na arvore\n");
    }
}

void inicializar(Apontador *arvore){
    *arvore = NULL;
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

