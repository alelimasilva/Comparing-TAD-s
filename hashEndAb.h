#include<stdio.h>  //biblioteca de inputs e outputs
#include<stdlib.h> //biblioteca para utilização do malloc
#include<time.h>   //para utilizar a função time
#include<string.h>  //manipulação de arquivos

#ifdef Linux //Esse ifdef serve para escolher o SO da maquina para a funcao limpaTela()
   #include <unistd.h> 
#elif defined(_WIN32) || defined(WIN32) 
   #define OS_Windows
   #include <windows.h>
#endif 

//Structs que compõe o TAD

typedef struct{ //struct para armazenar os itens do tipo dicionario 
	int chave;  //chave de cada célula da struct dicionário
	int indice; //variavel para guardar o valor do indice em que a chave se encontra
}dicionario;

typedef struct{			 //struct para armazenar os valores do tipo hash
	int quantidade; 	 //variavel para armazenar a quantidade de itens na tabela
	int tam_tabela; 	 //variavel para armazenar o tamanho da tabela
	dicionario **celula; //apontador para um apontador do tipo dicionario
}Hash;					 //cada um desses será uma célula do nosso dicionario

//Declarações de funções utilizadas

void limpaTela(); 						   //Limpa o terminal para melhorar a aparencia do programa
Hash* inicializa_hash(int tam); 				   //função para inicializar uma tabela HASH
int insere_hash(Hash* tabela, dicionario* d, int chave); 	   //função para inserir chaves na tabela HASH
void exclui_hash(Hash* tabela);					   //função para excluir uma tabela HASH
int calculaPos(int chave, int tam); 				   //função que faz o calculo da posição em que a chave se encontrara na tabela HASH (1ª função de dispersão)
int tratamentoDuploHash(int hash1, int chave, int indice, int tam);//função para tratamento de colisão através de um duplo HASH (2ª função de dispersão)
int busca_hash(Hash* tabela, int chave, dicionario* d); 	   //função para pesquisar na tabela HASH através da chave
int buscaI_hash(Hash* tabela, int chave, dicionario* d); 	   //função para pesquisar na tabela HASH através da chave e descobrir se pode adicionar na tabela
void retira_hash(Hash* tabela, int chave, dicionario* d);	   //função para remover chaves da tabela HASH através de uma busca por essa chave
