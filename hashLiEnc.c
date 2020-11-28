#include<stdio.h>  //biblioteca de inputs e outputs
#include<stdlib.h> //biblioteca para utilização do malloc
#include "hashLiEnc.h"  //incluindo arquivo cabeçalho com declarações de funções e estruturas de dados

void limpaTela(){ 		 //Limpa o terminal para melhorar a aparencia do programa
	#ifdef OS_Windows
		system("cls");   //Caso seja Windows
	#else
		system("clear"); //Caso seja Linux
	#endif 
}	

void inicializa_hash(Celula **hash){ // incializa o hash
	for(int i=0; i<TAM; i++) hash[i]=NULL;		 
}

int calcula_posicao(int chave){ // calcula a posição da hash
	return chave % TAM;
}

void insere_hash(int chave, Celula **hash){
	int posicao = calcula_posicao(chave); // calcula a posição para ser inserido
	if (hash[posicao]!=NULL) { // se ocorreu colisao
		if (buscalista(chave,hash)){ // verificando se a chave ja existe
			printf("A chave %d ja foi cadastrado\n",chave);
			return; // caso ja exista ele nao insere e sai da função
		}
	}	
    // se nao existir ele é inserido
    Celula **lista = &hash[posicao]; 
	if (*lista == NULL){
		*lista = (Celula *) malloc(sizeof(Celula)); // alocando memoria para a lista
  		if (*lista == NULL){
			printf("\nErro alocacao memoria!"); // caso aconteca algum erro na alocacao 
			exit(1); 
  		}
  		(*lista)->chave=chave;
  		(*lista)->prox=NULL;	
  		printf("-> Inserido hash[%d]",posicao); 
 	}
	else{ // Se ocorreu colisao
		printf("-> Colisao  hash[%d]",posicao);
	    Celula *guarda= hash[posicao]; // guardando posicao inicial ponteiro
		while ((*lista)->prox != NULL) *lista=(*lista)->prox; // Caminha para fim da lista caso contenha mais de 2 itens	
		(*lista)->prox=(Celula *) malloc(sizeof(Celula)); // alocando memoria para o proximo elemento
		if ((*lista)->prox == NULL) {
			printf("\nErro na alocacao de memoria."); // caso aconteca algum erro na alocacao 
			exit(1);
  		}	
		*lista=(*lista)->prox;
  		(*lista)->chave=chave;
  		(*lista)->prox=NULL; 
  		hash[posicao]=guarda; // retornando ponteiro para a posiçao inicial
	}
}

void imprime_hash(Celula **hash){ // Imprime tabela hash
    printf("\n");
	for (int i=0; i<TAM; i++){ // percorre toda as posiçoes da hash
		printf("\nhash[%d] ->",i); // imprime a posição da hash
		imprime_listaenc(i,hash); // imprime a lista da posição
	}
}

void imprime_listaenc(int posicao, Celula **hash){ // Percorre lista de uma posiçao e a imprime
	Celula *lista = hash[posicao];
	while (lista != NULL){  // enquanto nao chegar no fim da lista
		printf(" %d ->",lista->chave); // imprime um elemento da lista
		lista = lista->prox; // vai para o proximo elemento da lista
	}
	printf(" NULL");
} 

int buscalista(int chave, Celula **hash){
	int posicao = calcula_posicao(chave);
	Celula *lista = hash[posicao];
	while (lista != NULL){ // enquanto nao chegar no fim da lista
		if (chave == lista->chave) return 1; // Se encontrou retorna 1
		lista = lista->prox; // lista recebe o proximo elemento da lista
	}
	return 0;  // Se nao encontrou retorna 0
}

void remove_hash(int chave, Celula **hash) { 
 int posicao = calcula_posicao(chave);
 if (!buscalista(chave,hash)) { // verificando se chave pertence a tabela
 	puts("\nchave nao encontrado");
	return;
 }
	
 Celula **lista = &hash[posicao]; // apontando os ponteiros para os valores que serao utilizados
 Celula *ant = *lista;
 Celula *prox = (*lista)->prox;
 Celula *guarda = hash[posicao]; // guardando posicao do ponteiro 

 while (*lista!=NULL) { // laço percorre lista		
	if ((*lista)->chave == chave) { // Se encontrou a chave		
		if (*lista == ant) { // Se a chave esta no inicio
			if ((*lista)->prox==NULL) { // Se a lista possui uma unica chave
				free(*lista); // libera a lista
				hash[posicao]=NULL; // lista recebe NULL
			}
			else { 
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
