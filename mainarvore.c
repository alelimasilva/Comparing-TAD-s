#include "arvore.h" 
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

int main(){
    
    Arvore a;
	inicializar(&a);
	

    int vetor[TAM];
    FILE *arquivo;
    arquivo = fopen("teste10000n.txt" , "r");
    if(arquivo == NULL){
        printf("Erro ao carregar a arquivo.\n");
        exit(1);
    }
    for(int i=0;i<TAM;i++){
        fscanf(arquivo, "%d\n", &vetor[i]); 
    }
    struct timeval utime;
    double tInicio;
    double tFim;
    int i;

    gettimeofday(&utime, NULL);

    tInicio = utime.tv_sec + ( utime.tv_usec / 1000000.0 );

    for(int i=0;i<TAM;i++){
        inserir(vetor[i],&a);
    }

	gettimeofday(&utime, NULL);

    tFim = utime.tv_sec + ( utime.tv_usec / 1000000.0 );

    printf("%.4lf - Tempo percorrido\n", tFim - tInicio);
	
    return 0;
}
