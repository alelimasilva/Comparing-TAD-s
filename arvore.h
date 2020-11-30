#define TAM 900

typedef struct Celula * Apontador;
typedef struct Celula {
Apontador esq, dir;
int chave;
} Celula;
typedef Apontador Arvore;

void pesquisar(int chave, Apontador p);
void inserir(int chave, Apontador *p);
void inicializar(Apontador *arvore);
void retirar(int chave, Apontador *p);
void antecessor(Apontador q, Apontador *r);