#include<stdio.h>  //biblioteca de inputs e outputs
#include<stdlib.h> //biblioteca para utilização do malloc
#include "hashLiEnc.h"  //incluindo arquivo cabeçalho com declarações de funções e estruturas de dados

void inicializahash(No **hash, int tam){
	for(int i=0; i<tam; i++) hash[i]=NULL;		 
}

int calcula_posicao(unsigned int chave, int tam){ // calcula a posição da hash
	return chave % tam;
}

void inserehash(unsigned int chave, No **hash, int tam){
	int posicao = calcula_posicao(chave, tam); // calcula a posição para ser inserido
	if (hash[posicao]!=NULL) { // se ocorreu colisao
		if (buscalista(chave,hash,tam)){ // verificando se a chave ja existe
			printf("A chave %d ja foi cadastrado\n",chave);
			return; // caso ja exista ele nao insere e sai da função
		}
	}	
    // se nao existir ele é inserido
    No **lista = &hash[posicao]; 
	if (*lista == NULL){
		*lista = (No *) malloc(sizeof(No));
  		if (*lista == NULL){
			printf("\nErro alocacao memoria!");
			exit(1);
  		}
  		(*lista)->chave=chave;
  		(*lista)->prox=NULL;	
  		printf("-> Inserido hash[%d]\n",posicao);
 	}
	else{ // Se ocorreu colisao
		printf("-> Colisao  hash[%d]\n",posicao);
	    No *guarda= hash[posicao]; // guardando posicao inicial ponteiro
		while ((*lista)->prox != NULL) *lista=(*lista)->prox; // Caminha para fim da lista caso contenha mais de 2 itens	
		(*lista)->prox=(No *) malloc(sizeof(No));
		if ((*lista)->prox == NULL) {
			printf("\nErro na alocacao de memoria.");
			exit(1);
  		}	
		*lista=(*lista)->prox;// insere a chave no ultimo elemento da lista
  		(*lista)->chave=chave;
  		(*lista)->prox=NULL; 
  		hash[posicao]=guarda; // retornando ponteiro para a posiçao inicial
	}
}

int buscalista(unsigned int chave, No **hash, int tam){
	int posicao = calcula_posicao(chave,tam);
	No *lista = hash[posicao];
	while (lista != NULL){ // enquanto nao chegar no fim da lista
		if (chave == lista->chave) return 1; // Se encontrou retorna 1
		lista = lista->prox; // lista recebe o proximo elemento da lista
	}
	return 0;  // Se nao encontrou retorna 1
}

void apaga_hash(unsigned int chave, No **hash, int tam) { 
 int posicao = calcula_posicao(chave, tam);
 if (!buscalista(chave,hash,tam)) { // verificando se chave pertence a tabela
 	printf("\nchave nao encontrada");
	return;
 }
	
 No **lista = &hash[posicao];
 No *ant = *lista;
 No *prox = (*lista)->prox;
 No *guarda = hash[posicao]; // guardando posicao do ponteiro 

 while (*lista!=NULL) { // laço percorre lista		
	if ((*lista)->chave == chave){ // Se encontrou a chave		
		if (*lista == ant) { // Se a chave esta no inicio
			if ((*lista)->prox==NULL){ // Se a lista possui uma unica chave
				free(*lista); // libera a lista
				hash[posicao]=NULL; // lista recebe NULL
			}
			else{ 
				(*lista)->prox=prox->prox;
				(*lista)->chave=prox->chave;
				hash[posicao]=guarda;
			}
		}
		else { // Se a chave NAO esta no inicio
			ant->prox=prox; // anterior vai para o proximo
			free(*lista); // libera a lista
			hash[posicao]=guarda;
		}
		printf("Chave: %d removida.\n", chave);
		return;
 	} // fim laço encontrou o chave		
	ant = *lista;
	*lista = (*lista)->prox;
	prox = (*lista)->prox; 		
 } // fim laço percorre lista
	
 hash[posicao]=guarda; // retonando ponteiro para posicao inicial
 // libera a memoria de todos os ponteiros
 free(ant);
 free(prox);
 free(guarda);	
}
