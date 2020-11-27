#ifdef Linux //Esse ifdef serve para escolher o SO da maquina para a funcao limpaTela()
   #include <unistd.h> 
#elif defined(_WIN32) || defined(WIN32) 
   #define OS_Windows
   #include <windows.h>
#endif 

#define TAM 100 //constante definida para determinar o tamanho da tabela HASH

//Structs que compõe o TAD

typedef struct{ //struct para armazenar os itens do tipo dicionario 
	int chave;  //chave de cada célula da struct dicionário
	int indice; //variavel para guardar o valor do indice em que a chave se encontra
}dicionario;

typedef struct hash Hash; //apelidando a struct hash como Hash

struct hash{			 //struct para armazenar os valores do tipo hash
	int quantidade; 	 //variavel para armazenar a quantidade de itens na tabela
	int tam_tabela; 	 //variavel para armazenar o tamanho da tabela
	dicionario **celula; //apontador para um apontador do tipo dicionario
};						 //cada um desses será uma célula do nosso dicionario

//Declarações de funções utilizadas

void limpaTela(); 													//Limpa o terminal para melhorar a aparencia do programa
Hash* inicializa_hash(int tam); 									//função para inicializar uma tabela HASH
void exclui_hash(Hash* tabela);										//função para excluir uma tabela HASH
int calculaPos(int chave, int tam); 								//função que faz o calculo da posição em que a chave se encontrara na tabela HASH (1ª função de dispersão)
int tratamentoDuploHash(int hash1, int chave, int tam, int indice); //função para tratamento de colisão através de um duplo HASH (2ª função de dispersão)
int busca_hash(Hash* tabela, int chave, dicionario* d); 			//função para pesquisar na tabela HASH através da chave
int buscaI_hash(Hash* tabela, int chave, dicionario* d); 			//função para pesquisar na tabela HASH através da chave e descobrir se pode adicionar na tabela
