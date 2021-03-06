#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <locale.h>
#include <windows.h>

#define C "#"
#define M "@"
#define S 20
#define T 100	

int* bubleSort(int arquivo[], int tamanho);
void imprimirVetor(int vetor[], int tamanho, int i, int j);
void inicializarLetras(void);
void inicializarMarcas(void);
void imprimirLetras(void);

struct letra {
	char c[S];
};

int arquivo[S] = {9, 13, 5, 1, 14, 3, 11, 6, 7, 12, 4, 2, 8, 0, 15, 10, 18, 17, 16, 19};
letra letras[S];
letra marcas[S];

int main(void){
	int* ordenado;
	inicializarLetras();
	inicializarMarcas();
	//imprimirLetras();
	ordenado = bubleSort(arquivo, S);
	return(0);
}

int* bubleSort(int arquivo[], int tamanho){
	int i, j, tmp;
	for (i = 0; i < tamanho -1; i++){
		for (j = i+1; j < tamanho; j++){
			if (arquivo[i] > arquivo[j]){
				tmp = arquivo[i];
				arquivo[i] = arquivo[j];
				arquivo[j] = tmp;
			}
			imprimirVetor(arquivo, S, i, j);		
		}
	} 
	imprimirVetor(arquivo, S, -1, -1);		
	return arquivo;
}

void inicializarLetras(void){
	for(int i=0; i < S; i++){
		for(int j=0; j <= i; j++){
			strcat(letras[i].c, C);
		}
	}
}

void inicializarMarcas(void){
	for(int i=0; i < S; i++){
		for(int j=0; j <= i; j++){
			strcat(marcas[i].c, M);
		}
	}
}

void imprimirLetras(void){
	for (int i = 0; i < S; i++){
		printf("%s\n", letras[i].c);
	}	
}

void imprimirVetor(int vetor[], int tamanho, int i, int j){
	system("cls");
	for (int k = 0; k < tamanho; k++){
		if(k == i || k == j){
			printf("%s\n", marcas[vetor[k]].c);						
		} else {
			printf("%s\n", letras[vetor[k]].c);			
		}
	}	
	Sleep(T);	
}
