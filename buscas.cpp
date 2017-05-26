#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int arquivo[10] = {1, 2, 3, 5, 7, 11, 13, 17, 23, 31};
int argumento;
int posicao;

int buscaSequencial(int arquivo[], int argumento, int tamanho);
int buscaSequencialIndexada(int arquivo[], int argumento, int tamanho);
int buscaBinaria(int arquivo[], int argumento, int tamanho);
int buscaInterpolada(int arquivo[], int argumento, int tamanho);
void imprimeArquivo(int arquivo[], int tamanho);

int main(void){
	setlocale(LC_ALL, "Portuguese");	
	int tamanho = sizeof(arquivo)/sizeof(arquivo[0]);
	do {
		imprimeArquivo(arquivo, tamanho);
		printf("\nDigite o valor a ser pesquisado ou 0 para sair: ");
		scanf("%d", &argumento);
		if (argumento != 0){
			posicao = buscaSequencial(arquivo, argumento, tamanho);						
			posicao = buscaSequencialIndexada(arquivo, argumento, tamanho);						
			posicao = buscaBinaria(arquivo, argumento, tamanho);			
			posicao = buscaInterpolada(arquivo, argumento, tamanho);
			if (posicao == -1) {
				printf("\nValor %d não encontrado no vetor.\n\n", argumento);
			} else {
				printf("\nValor %d está na posição %d.\n\n", argumento, posicao);		
			}				
			system("pause");
		}
		system("cls");
	} while (argumento != 0);
	return(0);
}

int buscaSequencial(int arquivo[], int argumento, int tamanho){
	int indice = 0;
	int contador = 1;
	while(indice < tamanho){
		//printf("indice = %d\tvalor = %d\targumento = %d\n", indice, arquivo[indice],argumento);			
		if(arquivo[indice] == argumento){
			printf("Busca Sequencial = %d\n", contador);					
			return(indice);
		} 
		indice++;
		contador++;
	}
	printf("Busca Sequencial = %d\n", contador);						
	return(-1);
}

int buscaSequencialIndexada(int arquivo[], int argumento, int tamanho){
	int indice = 0;
	int contador = 1;	
	while(indice < tamanho){
		//printf("indice = %d\tvalor = %d\targumento = %d\n", indice, arquivo[indice],argumento);			
		if(arquivo[indice] == argumento){
			printf("Busca Sequencial Indexada = %d\n", contador);					
			return(indice);
		} else if(arquivo[indice] > argumento) {
			printf("Busca Sequencial Indexada = %d\n", contador);								
			return(-1);
		}
		indice++;
		contador++;
	}
	printf("Busca Sequencial Indexada = %d\n", contador);						
	return(-1);
}

int buscaBinaria(int arquivo[], int argumento, int tamanho){
	int menor, maior, meio, contador = 1;
	menor = 0;
	maior = tamanho-1;
	while(menor <= maior){
		meio = (maior + menor)/2;		
		//printf("menor = %d\tmeio = %d\tmaior = %d\targumento = %d\n", menor, meio, maior, argumento);			
		//printf("valor no meio = %d\n", arquivo[meio]);
		if(arquivo[meio] == argumento){
			printf("Busca Binária = %d\n", contador);			
			return(meio);
		} else if(arquivo[meio] > argumento){
			maior = meio - 1;
		} else {			
			menor = meio + 1;
		}
		contador++;
	}
	printf("Busca Binária = %d\n", contador);				
	return(-1);
}

int buscaInterpolada(int arquivo[], int argumento, int tamanho){
	int menor, maior, meio, contador = 1;
	menor = 0;
	maior = tamanho-1;
	while(menor <= maior){
		meio = menor+(maior-menor)*((argumento-arquivo[menor])/(arquivo[maior]-arquivo[menor]));		
		//printf("menor = %d\tmeio = %d\tmaior = %d\targumento = %d\n", menor, meio, maior, argumento);			
		//printf("valor no meio = %d\n", arquivo[meio]);
		if(arquivo[meio] == argumento){
			printf("Busca por Interpolação = %d\n", contador);					
			return(meio);
		} else if(arquivo[meio] > argumento){
			maior = meio - 1;
		} else {			
			menor = meio + 1;
		}
		contador++;
	}
	printf("Busca por Interpolação = %d\n", contador);					
	return(-1);
}

void imprimeArquivo(int arquivo[], int tamanho){
	printf("[\n");
	for (int i = 0; i < tamanho; i++){
		printf("%d\t", i);
	}	
	printf("\n");	
	for (int i = 0; i < tamanho; i++){
		printf("%d\t", arquivo[i]);
	}
	printf("\n]\n");	
}
