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

void limpaTela();//Limpa o terminal para melhorar a aparencia do programa
void inicializa_hash(No **hash, int tam); // inicializa a hash
int calcula_posicao(unsigned int chave, int tam); // calcula a posição da hash
int buscalista(unsigned int chave, No **hash, int tam); // busca um dado em uma lista encadeada
void insere_hash(unsigned int chave, No **hash, int tam); // verifica se pode ser inserido, se sim insere a chave na hash
void imprime_hash(No **hash, int tam); // imprime toda a hash
void imprime_listaenc(int pos, No **hash); // percorre uma lista encadeada em uma posição da hash e a imprime
void apaga_hash(unsigned int chave, No **hash, int tam); // apaga uma chave da hash
