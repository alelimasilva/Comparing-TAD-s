#ifdef Linux //Esse ifdef serve para escolher o SO da maquina para a funcao limpaTela()
   #include <unistd.h> 
#elif defined(_WIN32) || defined(WIN32) 
   #define OS_Windows
   #include <windows.h>
#endif 

#define TAM 100 //constante definida para determinar o tamanho da tabela HASH

struct registro {
	int chave; 
	struct registro *prox; 
};
typedef struct registro Celula; // Nó da hash

void limpaTela();//Limpa o terminal para melhorar a aparencia do programa
void inicializa_hash(Celula **hash); // inicializa a hash
int calcula_posicao(int chave); // calcula a posição da hash
void insere_hash(int chave, Celula **hash); // verifica se pode ser inserido, se sim insere a chave na hash
void imprime_hash(Celula **hash); // imprime toda a hash
void remove_hash(int chave, Celula **hash); // apaga um dado da hash
void imprime_listaenc(int pos, Celula **hash); // percorre uma lista encadeada em uma posição da hash e a imprime
int buscalista(int chave, Celula **hash); // busca um dado em uma lista encadeada
