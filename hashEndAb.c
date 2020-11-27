#include<stdio.h>  //biblioteca de inputs e outputs
#include<stdlib.h> //biblioteca para utilização do malloc
#include "hashEndAb.h"  //incluindo arquivo cabeçalho com declarações de funções e estruturas de dados

void limpaTela(){ 		 //Limpa o terminal para melhorar a aparencia do programa
	#ifdef OS_Windows
		system("cls");   //Caso seja Windows
	#else
		system("clear"); //Caso seja Linux
	#endif 
}	

Hash* inicializa_hash(int tam){ 				//função para inicializar uma tabela HASH
	Hash* tabela = (Hash*)malloc(sizeof(Hash)); //alocando espaço de memória para a tabela
	
	if(tabela != NULL){ 													//se a tabela não estiver inicializada em NULL
		tabela->tam_tabela = tam; 											//aqui ela recebe o tamanho passado por parâmetro
		tabela->celula = (dicionario**)malloc((sizeof(dicionario*) * tam)); //aqui será inicializado o espaço de memória para cada célula, ou seja, cada item do dicionário
		if(tabela->celula == NULL){ 										//se estiver vazio, a célula será desalocada, esse caso se dá por correção de erro na inserção de algum valor
			free(tabela); 													//desalocando a memória
			return NULL; 													//retornando NULL
		}
		tabela->quantidade = 0; 											//setando a quantidade de itens como 0, pois a tabela está sendo inicializada
	for(int i = 0; i < tam; i++){
		tabela->celula[i] = NULL; 											//inicializando a tabela com NULL em todas as células
	}
	}
	printf("Tabela Hash inicializada!\n");
	return tabela;															//retornando a tabela, pois a função pede um retorno a um ponteiro do tipo estrutura Hash
}

void exclui_hash(Hash* tabela){ 					 //função para excluir uma tabela HASH
	if(tabela != NULL){ 							 //se a tabela conter elementos armazenados ela será excluida
		for(int i = 0; i < tabela->tam_tabela; i++){ //percorrendo a tabela HASH
			if(tabela->celula[i] != NULL) 			 //caso tenha algum elemento armazenado na celula ele será desalocado
				free(tabela->celula[i]);			 //desalocando espaço de memória na célula de indice i
		}
		free(tabela->celula); 						 //desalocando o ponteiro para as células da tabela
		free(tabela); 								 //desalocando a tabela;
	}
	printf("Tabela Hash excluida!\n");
}

int calculaPos(int chave, int tam){ //função que faz o calculo da posição em que a chave se encontrara na tabela HASH
	return chave % tam; 			//a posição se dará de acordo com o valor do resto da divisão da chave pelo tamanho da tabela
}

int tratamentoDuploHash(int hash1, int chave, int tam, int indice){ //função para tratamento de colisão através de um duplo HASH
	int hash2 = calculaPos(chave, tam/2) + 1;						//hash2 = (chave % (tam_lista/2)) + 1
	return (hash1 + (indice * hash2)) % tam; 						//retornando o valor da posição da chave através do cálculo entre hash1 + (indice em que a chave se encontra no momento * hash2) % tamanho da tabela HASH
}

int insere_hash(Hash* tabela, dicionario* d, int chave){ //função para inserir chaves na tabela HASH
	int posicao, novaPosicao; 							 //variaveis de suporte para funções de hashing (gerar as posições em casos de colisão)
	posicao = calculaPos(chave, tabela->tam_tabela); 	 //posição recebe o primeiro tratamento de colisão chave % tamanho da tabela
	
	if(tabela == NULL){ 														//se a tabela estiver vazia
		printf("\n");
		printf("Tabela vazia!\n");
		printf("\n");
		return 0; 																//retornando que falhou a inserção
	}else if(tabela->quantidade == tabela->tam_tabela){ 						//se a tabela estiver cheia
		printf("\n");
		printf("A tabela esta cheia!\n");
		printf("\n");
		return 0; 																//retorna que falhou a inserção
	}else if(buscaI_hash(tabela, chave, d) == 1){ 								//se a chave ja estiver na tabela
		printf("\n");
		printf("Item ja esta na tabela!\n");
		printf("\n");
		return 0; 																//retorna falha na inserção
	}
	for(int i = 0; i < tabela->tam_tabela; i++){ 
		novaPosicao = tratamentoDuploHash(posicao, chave, tabela->tam_tabela, i); //novaPosicao recebe o retorno da segunda função de tratamento de colisão tratamentoDuploHash
		if(tabela->celula[novaPosicao] == NULL){ 								  //se a nova posição estiver vazia
			dicionario* novaCelula;  											  //declarando uma auxiliar do tipo dicionario
			novaCelula = (dicionario*) malloc(sizeof(dicionario)); 				  //alocando espaço de memoria para um apontador do tipo dicionario
			if(novaCelula == NULL) 												  //conferindo se novaCelula foi certamente inicializada
				return 0;    													  //retornando que houve erro com o apontador novaCelula
			else{ 																  //caso esteja tudo correndo de maneira correta
				novaCelula->chave = chave; 										  //novaCelula->chave vai receber o valor da chave a ser inserida
				novaCelula->indice = i; 										  //novaCelula->indice vai receber o indice atual
				tabela->celula[novaPosicao] = novaCelula; 						  //novaCelula sendo armazenada na tabela em sua posição determinada através das hashings
				tabela->quantidade++; 											  //incrementando a quantidade de itens na tabela			 		  
				printf("\n|CHAVE INSERIDA COM SUCESSO\n"
					   "|CHAVE: %d                   \n"
					   "|Posicao: %d                 \n"
					   "|Indice: %d                \n\n"
				, tabela->celula[novaPosicao]->chave, novaPosicao, i);
				return 1; 														  //retornando êxito na inserção
			}
		}
	}
	return 0; 																	  //caso faça o loop até que o tamanho da tabela e não consiga inserir, retorna que falhou
}

int busca_hash(Hash* tabela, int chave, dicionario* d){ 						  //função para pesquisar na tabela HASH através da chave
	int posicao, novaPosicao; 													  //variaveis de suporte para funções de hashing (gerar as posições em casos de colisão)
	posicao = calculaPos(chave, tabela->tam_tabela);   							  //posição recebe o primeiro tratamento de colisão chave % tamanho da tabela
	
	if(tabela == NULL){ 														  //caso a tabela esteja vazia 
		printf("\n");
		printf("Tabela vazia!\n");
		printf("\n");
		return 0;    															  //retornando falha na busca
	}
	
	for(int i = 0; i < tabela->tam_tabela; i++){
		novaPosicao = tratamentoDuploHash(posicao, chave, tabela->tam_tabela, i); //novaPosicao recebe o retorno da segunda função de tratamento de colisão tratamentoDuploHash
		if(tabela->celula[novaPosicao] == NULL){ 								  //caso não haja nada na posição o item não foi encontrado
			printf("\n");
			printf("Item nao foi encontrado!\n"); 
			printf("\n");
			return 0; 															  //retornando falha na busca
		}
		if(tabela->celula[novaPosicao]->chave == chave){ 						  //caso tenha algo na posição e as chaves sejam iguais
			*d = *(tabela->celula[novaPosicao]); 		 						  //o apontador d do tipo dicionario apontará para a posição em que se encontra a chave
			printf("\n");
			printf("|CHAVE ENCONTRADA\n");
			printf("|CHAVE: %d       \n", tabela->celula[novaPosicao]->chave);
			printf("|POSICAO: %d     \n", novaPosicao);
			printf("|INDICE: %d      \n", tabela->celula[novaPosicao]->indice);
			printf("\n");
			return 1; 									 						  //retornando êxito na busca
		}
	}
	return 0; 																	  //caso faça o loop até que o tamanho da tabela e não consiga encontrar a chave, retorna que falhou
}

int buscaI_hash(Hash* tabela, int chave, dicionario* d){ 						  //função para pesquisar na tabela HASH através da chave e descobrir se pode adicionar/remover da tabela
	int posicao, novaPosicao; 													  //variaveis de suporte para funções de hashing (gerar as posições em casos de colisão)
	posicao = calculaPos(chave, tabela->tam_tabela);   							  //posição recebe o primeiro tratamento de colisão chave % tamanho da tabela
	
	if(tabela == NULL)  														  //caso a tabela esteja vazia 
		return 0;    															  //retornando falha na busca
	
	for(int i = 0; i < tabela->tam_tabela; i++){
		novaPosicao = tratamentoDuploHash(posicao, chave, tabela->tam_tabela, i); //novaPosicao recebe o retorno da segunda função de tratamento de colisão tratamentoDuploHash
		if(tabela->celula[novaPosicao] == NULL) 
			return 0; 															  //retornando falha na busca
		if(tabela->celula[novaPosicao]->chave == chave)
			return 1; 									 						  //retornando êxito na busca
	}
	return 0; 																	  //caso faça o loop até que o tamanho da tabela e não consiga encontrar a chave, retorna que falhou
}

void retira_hash(Hash* tabela, int chave, dicionario* d){							  //função para remover chaves da tabela HASH através de uma busca por essa chave
	int posicao, novaPosicao; 													  	  //variaveis de suporte para funções de hashing (gerar as posições em casos de colisão)
	posicao = calculaPos(chave, tabela->tam_tabela);   							 	  //posição recebe o primeiro tratamento de colisão chave % tamanho da tabela
	
	if(tabela == NULL){															 	  //se a tabela estiver vazia
		printf("\n");
		printf("Tabela vazia!\n");
		printf("\n");
		return;																		  //saindo da função
	}
	else if(buscaI_hash(tabela, chave, d) == 0){									  //se a chave não estiver na tabela
		printf("\n");
		printf("Item nao esta presente na tabela!\n");
		printf("\n");
		return;																		  //saindo da função
	}		
	else{
		for(int i = 0; i < tabela->tam_tabela; i++){
			novaPosicao = tratamentoDuploHash(posicao, chave, tabela->tam_tabela, i); //novaPosicao recebe o retorno da segunda função de tratamento de colisão tratamentoDuploHash
			if(tabela->celula[novaPosicao]->chave == chave){						  //se a chave pesquisada for igual a chave na posição, ela será removida					
				free(tabela->celula[novaPosicao]);									  //desalocando a memória utilizada para armazenar a chave
				tabela->quantidade--;												  //decrementando a quantidade de itens na tabela
				printf("\n");
				printf("|CHAVE REMOVIDA!\n");
				printf("\n");
				return; 															  //saindo da função
			}
		}
	}
}
