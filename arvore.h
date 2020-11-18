typedef struct Registro{
    int chave;
} Registro;
typedef struct No * Apontador;
typedef struct No {
Registro registro;
Apontador esq, dir;
} No;
typedef Apontador Dicionario;

void pesquisar(Registro *x, Apontador p);
void inserir(Registro x, Apontador *p);
void inicializar(Apontador *dicionario);
void retirar(Registro x, Apontador *p);
void antecessor(Apontador q, Apontador *r);
