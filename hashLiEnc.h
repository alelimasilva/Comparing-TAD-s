#ifdef Linux //Esse ifdef serve para escolher o SO da maquina para a funcao limpaTela()
   #include <unistd.h> 
#elif defined(_WIN32) || defined(WIN32) 
   #define OS_Windows
   #include <windows.h>
#endif 

struct registro{
	int chave; 
	struct registro *prox; 
};
typedef struct registro No;

void inicializahash(No **hash, int tam); // inicializa a hash
int calcula_posicao(unsigned int chave, int tam); // calcula a posição da hash
int buscalista(unsigned int chave, No **hash, int tam); // busca um dado em uma lista encadeada
void inserehash(unsigned int chave, No **hash, int tam); // verifica se pode ser inserido, se sim insere a chave na hash
void apaga_hash(unsigned int chave, No **hash, int tam); // apaga uma chave da hash
