#include <sys/time.h>  //para as funções de tempo em linux
#include "hashLiEnc.h" //arquivos cabeçalho 
#include "hashEndAb.h" //dos módulos
#include "arvore.h"    //do programa


int main(){

	int escolha1, escolha2;//variaveis de suporte para o menu
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
		
		limpaTela();
		
		int tam;//variavel para o tamanho do arquivo
		if(escolha1 == 1) tam = 100;
		if(escolha1 == 2) tam = 1000;
		if(escolha1 == 3) tam = 10000;
		if(escolha1 == 4) tam = 100000;
		
		//inicializando os TAD's
		No *hash[tam]; 		       //criando um apontador para o tipo No
		inicializahash(hash, tam);     //inicializando a HashLiEnc
		Hash *tabela; 		       //criando um apontador do tipo HashEndAb
		tabela = inicializa_hash(tam); //inicializando a tabela HashEndAb
		dicionario *d; 		       //criando um apontador do tipo dicionario para a HashEndAb
		int vetor[tam];		       //vetor de suporte para operações nos TAD's
        	Arvore a;		       //criando uma variavel para o tipo Arvore
        	inicializar(&a); 	       //Inicializando a Arvore
		
		if(escolha1 != 1 && escolha1 != 2 && escolha1 != 3 && escolha1 !=4){//condiçao de saida e finalização do programa
			free(a);             //liberando espaço de memória
			exclui_hash(tabela); //liberando espaço de memória
			free(hash);	     //liberando espaço de memória
			free(d);	     //liberando espaço de memória
			break;		     //encerrando programa
		}
		
		printf("1| Arvore binaria nao balanceada\n");
		printf("2| Hash com enderecamento aberto\n");
		printf("3| Hash com tratamento por lista encadeada\n");
		printf("Escolha: ");
		scanf("%d",&escolha2);	

		FILE *arquivo; 				//declarando um apontador do tipo FILE
		arquivo = fopen("100000n.txt" , "r");   //abrindo arquivo
		if(arquivo == NULL){
			printf("Erro ao carregar o arquivo.\n");
			exit(1);
		}
		for(int i=0;i<tam;i++){
			fscanf(arquivo, "%d\n", &vetor[i]);//copiando dados do arquivo pro vetor auxiliar
		}

		struct timeval utime;
    	double tInicio_I, tFim_I; //variaveis de tempo de inserçao
    	double tInicio_R, tFim_R; //variaveis de tempo de remoçao
    	double tInicio_B, tFim_B; //variaveis de tempo de busca

		if(escolha2 == 1){
			//funçoes arvore
			gettimeofday(&utime, NULL);
            tInicio_I = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
            
			for(int i = 0; i < tam; i++){
			inserir(vetor[i], &a);
            }
            
			gettimeofday(&utime, NULL);
			tFim_I = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			//---------------------------------------------------------
			gettimeofday(&utime, NULL);
			tInicio_B = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
            
			pesquisar(vetor[tam/2], a);
            
			gettimeofday(&utime, NULL);
			tFim_B = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			//---------------------------------------------------------
			gettimeofday(&utime, NULL);
			tInicio_R = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
            
			for(int i = 0; i < tam; i++){
			retirar(vetor[i], &a);
            }
            
			gettimeofday(&utime, NULL);
			tFim_R = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
            
			printf("%.6lf - Tempo percorrido para insercao.\n", tFim_I - tInicio_I);
			printf("%.6lf - Tempo percorrido para busca.\n", tFim_B - tInicio_B);
			printf("%.6lf - Tempo percorrido para remocao.\n", tFim_R - tInicio_R);

		}
		if(escolha2 == 2){
			//funções Hash Endereçamento Aberto
			gettimeofday(&utime, NULL);
			tInicio_I = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
    		
			for(int i=0;i<tam;i++){
        		//insere_hash(tabela, d, vetor[i]); problemas para remoção utilizando dados do arquivo
				insere_hash(tabela, d, i); //por isso utilizamos a inserção por índice
			}
			
			gettimeofday(&utime, NULL);
			tFim_I = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			//---------------------------------------------------------
			gettimeofday(&utime, NULL);
			tInicio_B = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
            
			//busca_hash(tabela, vetor[tam/2], d); problemas para a remoção utilizando dados do arquivo
            busca_hash(tabela, tam/2, d);//por isso utilizamos a busca dessa forma tam/2
			
			gettimeofday(&utime, NULL);
			tFim_B = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			//---------------------------------------------------------
			gettimeofday(&utime, NULL);
			tInicio_R = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
    		
			for(int i=0;i<tam;i++){
        		//retira_hash(tabela, vetor[i], d); problemas para remover utilizando dados do arquivo
				retira_hash(tabela, i, d);//por isso utilizamos a remoção por índice
			}
			
			gettimeofday(&utime, NULL);
			tFim_R = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			
			printf("%.3f - Tempo percorrido para insercao.\n", tFim_I - tInicio_I);
			printf("%.3f - Tempo percorrido para busca.\n", tFim_B - tInicio_B);
			printf("%.3f - Tempo percorrido para remocao.\n", tFim_R - tInicio_R);
		}
		if(escolha2 == 3){
			//Funções Hash Lista Encadeada
			gettimeofday(&utime, NULL);
			tInicio_I = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
    		
			for(int i=0;i<tam;i++){
        		inserehash(vetor[i], hash, tam);
   			}
			
			gettimeofday(&utime, NULL);
			tFim_I = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			//---------------------------------------------------------
			gettimeofday(&utime, NULL);
			tInicio_B = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			
			if(buscalista(vetor[tam/2], hash, tam) == 1) printf("Valor encontrado!\n");
			else printf("Valor nao encontrado!\n");
			
			gettimeofday(&utime, NULL);
			tFim_B = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			//---------------------------------------------------------
			gettimeofday(&utime, NULL);
			tInicio_R = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
    		
			for(int i=0;i<tam;i++){
        		apaga_hash(vetor[i], hash, tam);
   			}
			
			gettimeofday(&utime, NULL);
			tFim_R = utime.tv_sec + ( utime.tv_usec / 1000000.0 );
			
			printf("%.3f - Tempo percorrido para insercao.\n", tFim_I - tInicio_I);
			printf("%.3f - Tempo percorrido para busca.\n", tFim_B - tInicio_B);
			printf("%.3f - Tempo percorrido para remocao.\n", tFim_R - tInicio_R);
		}
		//dessa forma o usuario pode parar e ver os dados.
		int escolha3;
		printf("\nLimpar a tela?\n"
			   "1 para sim, outro para nao\n"
			   "Escolha: ");
		scanf("%d",&escolha3);
		if(escolha3 == 1) limpaTela();
	}

	return 0;
}
