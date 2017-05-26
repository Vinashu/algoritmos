
#include <stdio.h>
#include <locale.h>

int arquivo[11] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int argumento;
int posicao;

int buscaBinaria(int arquivo[], int argumento, int tamanho);
void imprimeArquivo(int arquivo[], int tamanho);

int main(void){
	setlocale(LC_ALL, "Portuguese");	
	int tamanho = sizeof(arquivo)/sizeof(arquivo[0]);
	imprimeArquivo(arquivo, tamanho);
	printf("Digite o valor a ser pesquisado: ");
	scanf("%d", &argumento);
	posicao = buscaBinaria(arquivo, argumento, tamanho);
	if (posicao == -1) {
		printf("Valor %d não encontrado no vetor.\n", argumento);
	} else {
		printf("Valor %d está na posição %d.\n", argumento, posicao);		
	}
	return(0);
}

int buscaBinaria(int arquivo[], int argumento, int tamanho){
	int menor, maior, meio;
	menor = 0;
	maior = tamanho-1;
	while(menor <= maior){
		meio = (maior + menor)/2;		
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
