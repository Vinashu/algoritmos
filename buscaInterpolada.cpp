#include <stdio.h>
#include <locale.h>

int arquivo[10] = {1, 2, 3, 5, 7, 11, 13, 17, 23, 31};
int argumento;
int posicao;

int buscaInterpolada(int arquivo[], int argumento, int tamanho);
void imprimeArquivo(int arquivo[], int tamanho);

int main(void){
	setlocale(LC_ALL, "Portuguese");	
	int tamanho = sizeof(arquivo)/sizeof(arquivo[0]);
	imprimeArquivo(arquivo, tamanho);
	printf("Digite o valor a ser pesquisado: ");
	scanf("%d", &argumento);
	posicao = buscaInterpolada(arquivo, argumento, tamanho);
	if (posicao == -1) {
		printf("Valor %d não encontrado no vetor.\n", argumento);
	} else {
		printf("Valor %d está na posição %d.\n", argumento, posicao);		
	}
	return(0);
}

int buscaInterpolada(int arquivo[], int argumento, int tamanho){
	int menor, maior, meio;
	menor = 0;
	maior = tamanho-1;
	while(menor <= maior){
		meio = menor+(maior-menor)*((argumento-arquivo[menor])/(arquivo[maior]-arquivo[menor]));		
		printf("menor = %d\tmeio = %d\tmaior = %d\targumento = %d\n", menor, meio, maior, argumento);			
		printf("valor no meio = %d\n", arquivo[meio]);
		if(arquivo[meio] == argumento){
			return(meio);
		} else if(arquivo[meio] > argumento){
			maior = meio - 1;
		} else {			
			menor = meio + 1;
		}
	}
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
