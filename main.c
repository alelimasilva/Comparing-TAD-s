#include "hashEndAb.c" //importando biblioteca de funções

int main(){
	
Hash *tabela; 				   //declarando um apontador para o tipo Hash
tabela = inicializa_hash(TAM); //inicializando a tabela HASH
dicionario* d; 				   //declarando um apontador para o tipo dicionario
int x, y; 					   //variaveis de suporte para os loops do menu



do{
	limpaTela();
	printf("Insira 1 pra adicionar valores a Hash\n"
		   "Insira 2 para ver a quantidade de itens na HASH\n"
	       "Insira 3 para buscar uma chave na HASH\n"
		   "Insira 0 para sair\n");
	scanf("%d", &x);
	switch(x){
		case 1:
			limpaTela();
			do{
			printf("Insira o valor da chave: ");
			scanf("%d", &y);
			insere_hash(tabela, d, y);
			printf("0 para voltar: ");
			scanf("%d", &y);
			}while(y != 0);
			break;
		case 2:
			limpaTela();
			do{
			printf("A quantidade eh: %d\n", tabela->quantidade);
			printf("0 para voltar: ");
			scanf("%d", &y);
			}while(y != 0);
			break;
		case 3:
			limpaTela();
			do{
			printf("Insira o valor da chave a ser buscada: ");
			scanf("%d", &y);
			busca_hash(tabela, y, d);
			printf("0 para voltar: ");
			scanf("%d", &y);
			}while(y != 0);
			break;
		default:			
			break;
	}
}while(x != 0);

free(tabela); //liberando espaço de memória alocado para tabela
free(d);      //liberando espaço de memória alocado para d

return 0;
}
