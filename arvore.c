#include"arvore.h"
#include<stdio.h>
#include<stdlib.h>

void pesquisar(int chave, Apontador p){
    if (p == NULL){ //condição de saida da recursao caso nao seja encontrado o valor
        printf("Erro: Registro nao esta presente na arvore\n");
        return;
    }
    if (chave < p->chave){ //analisa se a chave do registro a ser procurado é menor do que a chave do no
        pesquisar(chave, p->esq); // procura novamente no nó filho a esquerda
    }
    else if (chave > p->chave){  //analisa se a chave do registro a ser procurado é maior do que a chave do no
        pesquisar(chave, p->dir); // procura novamente no nó filho a direita
    }
    else{// se o valor for encontrado
        printf("Registro encontrado na arvore\n");
        //*x = p->chave; // o registro x recebe o registro da nó encontrado
    }
}

void inserir(int chave, Apontador *p){
    if (*p == NULL){ // so insere se o que p aponta for NULL
        *p = (Apontador)malloc(sizeof(Celula)); // p passa a apontar para um no
        (*p)->chave = chave; (*p)->esq = NULL; (*p)->dir = NULL; // adiciona os valores e o esq e dir dele se tornam NULL
        return;
    }
    if (chave < (*p)->chave){ //analisa se a chave do registro a ser procurado é menor do que a chave do no
        inserir(chave, &(*p)->esq); return; // entao tenta inserir no nó a esq 
    }
    else if (chave > (*p)->chave){ //analisa se a chave do registro a ser procurado é maior do que a chave do no
        inserir(chave, &(*p)->dir); // entao tenta inserir no nó a esq 
    }
    else{ //caso ele nao seja nem maior ou menor ele ja existe na arvore 
        printf("Erro : Registro ja existe na arvore\n");
    }
}

void inicializar(Apontador *arvore){ // inicializar a arvore
    *arvore = NULL;
}

void retirar(int chave, Apontador *p){ // funcao para retirar um registro da arvore
    Apontador aux; // ponteiro auxiliar utilizado para receber o valor o ponteiro *p passado na funcao
    if (*p == NULL) { // checando se o registro esta presente na arvore
        printf("Erro : Registro nao esta na arvore\n");
    } else if (chave < (*p)->chave){ // caso a chave seja menor que o registro a funcao é chamada novamente com os valores de x e com o ponteiro *p apontando pra sua esquerda
        retirar(chave, &(*p)->esq); return;
    } else if (chave > (*p)->chave){ // caso a chave seja maior que o registro a funcao é chamada novamente com os valores de x e com o ponteiro *p apontando pra sua direita
        retirar(chave, &(*p)->dir); return;
    } else if ((*p)->dir == NULL){ // verificando se a direita do ponteiro esta vazia, se estiver, o auxiliar recebe *p e *p aponta para a esquerda do ponteiro, liberando a memoria do auxiliar apos o processo 
        aux = *p;
        *p = (*p)->esq;
        free(aux);
    }else if ((*p)->esq == NULL){ // verificando se a esquerda do ponteiro esta vazia, se estiver, o auxiliar recebe *p e *p aponta para a direita do ponteiro, liberando a memoria do auxiliar apos o processo 
        aux = *p;
        *p = (*p)->dir;
        free(aux);
    }
    else{
        antecessor(*p, &(*p)->esq); // funcao chamada para organizar a arvore apos a retirada do registro
    }
}

void antecessor(Apontador q, Apontador *r){ // funcao que recebe 2 ponteiros e verifica se a direita esta vazia e caso estiver vazia a ligacao entre os nos é feita 
    if ((*r)->dir != NULL) { // caso nao esteja vazia, a funcao é chamada novamente com o segundo ponteiro apontando para sua direita
        antecessor(q, &(*r)->dir);
        return;
    } else{
        q->chave = (*r)->chave;
        q = *r;
        *r = (*r)->esq;
        free(q);
    }
}