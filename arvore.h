typedef struct Registro{
    int chave;
} Registro;
typedef struct Celula * Apontador;
typedef struct Celula {
Registro registro;
Apontador esq, dir;
} Celula;
typedef Apontador Arvore;

void pesquisar(Registro *x, Apontador p);
void inserir(Registro x, Apontador *p);
void inicializar(Apontador *arvore);
void retirar(Registro x, Apontador *p);
void antecessor(Apontador q, Apontador *r);
