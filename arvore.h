typedef struct Registro{
    int chave;
} Registro;
typedef struct No * Apontador;
typedef struct No {
Registro registro;
Apontador esq, dir;
} No;
typedef Apontador Dicionario;
