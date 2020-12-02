#include<stdio.h>
#include<stdlib.h>
//#include <sys/time.h>
#include "hashLiEnc.h" 
#include "hashEndAb.h" 
#include "arvore.h" 


int main(){

	int escolha1, escolha2;
	while(1){
		printf("Bem vindo!\n");
		printf("Com quantos numeros deseja ultilizar o TAD?\n");
		printf("1| 100\n");
		printf("2| 1000\n");
		printf("3| 10000\n");
		printf("4| 100000\n");
		printf("Outro para sair\n");
		printf("Escolha: ");
		scanf("%d",&escolha1);
		if(escolha1 != 1 && escolha1 != 2 && escolha1 != 3 && escolha1 !=4) break; // condiçao de saida
		int tam; // variavel para o tamanho do arquivo
		if(escolha1 == 1) tam = 100;
		if(escolha1 == 2) tam = 1000;
		if(escolha1 == 3) tam = 10000;
		if(escolha1 == 4) tam = 100000;
		// inicializem as parada aqui
		No *hash[tam];
		inicializahash(hash, tam);
		int vetor[tam];

		printf("1| Arvore binaria nao balanceada\n");
		printf("2| Hash com enderecamento aberto\n");
		printf("3| Hash com tratamento por lista encadeada\n");
		printf("Escolha: ");
		scanf("%d",&escolha2);	

		FILE *arquivo;
		arquivo = fopen("100000n.txt" , "r");
		if(arquivo == NULL){
			printf("Erro ao carregar o arquivo.\n");
			exit(1);
		}
		for(int i=0;i<tam;i++){
			fscanf(arquivo, "%d\n", &vetor[i]);
	}

		//struct timeval utime;
    	//double tInicio_I, tFim_I; // variaveis de tempo de inserçao
    	//double tInicio_R, tFim_R; // variaveis de tempo de remoçao
    	//double tInicio_B, tFim_B; // variaveis de tempo de busca
		if(escolha2 == 1){
			// funçoes arvore
			printf("oi");
		}
		if(escolha2 == 2){
			// funçoes hash end aberto
			printf("oi");
		}
		if(escolha2 == 3){
			//gettimeofday(&utime, NULL);
			//tInicio_I = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
    		for(int i=0;i<tam;i++){
        		inserehash(i, hash, tam);
   			}
			//gettimeofday(&utime, NULL);
			//tFim_I = utime.tv_sec + ( utime.tv_usec / 1000000.0 );

			//gettimeofday(&utime, NULL);
			//tInicio_B = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			if(buscalista(50, hash, tam) == 1) printf("Valor encontrado!\n");
			else printf("Valor nao encontrado!\n");
			//gettimeofday(&utime, NULL);
			//tFim_B = utime.tv_sec + ( utime.tv_usec / 1000000.0 );

			//gettimeofday(&utime, NULL);
			//tInicio_R = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
    		for(int i=0;i<tam;i++){
        		apaga_hash(i, hash, tam);
   			}
			//gettimeofday(&utime, NULL);
			//tFim_R = utime.tv_sec + ( utime.tv_usec / 1000000.0 );

			//printf("%.3f - Tempo percorrido para insercao.\n", tFim_I - tInicio_I);
			//printf("%.3f - Tempo percorrido para busca.\n", tFim_B - tInicio_B);
			//printf("%.3f - Tempo percorrido para remocao.\n", tFim_R - tInicio_R);


		}
		// coloquei assim pro usuario poder parar e ver os dados da parada
		int escolha3;
		printf("\nLimpar a tela?\n1 para sim, outro para nao\nEscolha: ");
		scanf("%d",&escolha3);
		if(escolha3 == 1) limpaTela();
	}
	return 0;
}
