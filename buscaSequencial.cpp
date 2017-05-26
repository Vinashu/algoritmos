#include <stdio.h>
#include <locale.h>

int arquivo[10] = {1, 2, 3, 5, 7, 11, 13, 17, 23, 31};
int argumento;
int posicao;

int buscaSequencial(int arquivo[], int argumento, int tamanho);
void imprimeArquivo(int arquivo[], int tamanho);

int main(void){
	setlocale(LC_ALL, "Portuguese");	
	int tamanho = sizeof(arquivo)/sizeof(arquivo[0]);
	imprimeArquivo(arquivo, tamanho);
	printf("Digite o valor a ser pesquisado: ");
	scanf("%d", &argumento);
	posicao = buscaSequencial(arquivo, argumento, tamanho);
	if (posicao == -1) {
		printf("Valor %d não encontrado no vetor.\n", argumento);
	} else {
		printf("Valor %d está na posição %d.\n", argumento, posicao);		
	}
	return(0);
}

int buscaSequencial(int arquivo[], int argumento, int tamanho){
	int indice = 0;
	while(indice < tamanho){
		printf("indice = %d\tvalor = %d\targumento = %d\n", indice, arquivo[indice],argumento);			
		if(arquivo[indice] == argumento){
			return(indice);
		} 
		indice++;
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
