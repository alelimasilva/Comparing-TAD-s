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
typedef struct registro No; // Nó da hash

void limpaTela();//Limpa o terminal para melhorar a aparencia do programa
void inicializa_hash(No **hash); // inicializa a hash
int calcula_posicao(int chave); // calcula a posição da hash
void insere_hash(int chave, No **hash); // verifica se pode ser inserido, se sim insere a chave na hash
void imprime_hash(No **hash); // imprime toda a hash
void remove_hash(int chave, No **hash); // apaga um dado da hash
void imprime_listaenc(int pos, No **hash); // percorre uma lista encadeada em uma posição da hash e a imprime
int buscalista(int chave, No **hash); // busca um dado em uma lista encadeada
