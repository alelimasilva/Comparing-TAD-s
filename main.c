#include "arvore.h" 
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>



int main(){
    clock_t t;
    Arvore a;
	inicializar(&a);

    int vetor[TAM];
    FILE *arquivo;
    arquivo = fopen("teste900n.txt" , "r");
    if(arquivo == NULL){
        printf("Erro ao carregar a arquivo.\n");
        exit(1);
    }
    for(int i=0;i<TAM;i++){
        fscanf(arquivo, "%d\n", &vetor[i]); 
    }
    t = clock();
    for(int i=0;i<TAM;i++){
        inserir(vetor[i],&a);
    }
    t = clock() - t;
	
    printf("Demorou %.3f segundos\n",((double)t)/((CLOCKS_PER_SEC)));
    return 0;
}
