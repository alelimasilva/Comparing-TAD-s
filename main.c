#include "hashEndAb.c" //importando biblioteca de funções

int main(){
	
Hash *tabela; 				   //declarando um apontador para o tipo Hash
tabela = inicializa_hash(TAM); //inicializando a tabela HASH
dicionario* d; 				   //declarando um apontador para o tipo dicionario
int x, y; 					   //variaveis de suporte para os loops do menu



do{ // inicio do loop do menu
	limpaTela();
	printf("|1 adicionar valores a HASH\n"
		   "|2 buscar uma chave na HASH\n"
	       "|3 remover uma chave na HASH\n"
		   "|4 quantidade de itens na HASH\n"
		   "|0 sair\n"
		   "|Opcao escolhida: ");
	scanf("%d", &x);
	switch(x){
		case 1:			
			do{
				limpaTela();
				printf("|Insira o valor da chave: ");
				scanf("%d", &y);
				insere_hash(tabela, d, y);
				printf("|0 voltar: ");
				scanf("%d", &y);
			}while(y != 0);
			break;
		case 2:
			do{
				limpaTela();
				printf("|Insira o valor da chave a ser buscada: ");
				scanf("%d", &y);
				busca_hash(tabela, y, d);
				printf("|0 voltar: ");
				scanf("%d", &y);
			}while(y != 0);
			break;
		case 3:
			do{
				limpaTela();
				limpaTela();
				printf("|Insira o valor da chave a ser buscada: ");
				scanf("%d", &y);
				retira_hash(tabela, y, d);
				
				printf("|0 voltar: ");
				scanf("%d", &y);
			}while(y != 0);
			break;
		case 4: 
			do{
				limpaTela();
				printf("|A quantidade eh: %d\n", tabela->quantidade);
				printf("|0 voltar: ");
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
