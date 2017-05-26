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

void troca(int* a, int* b);
int quickSort(int vetor[], int left, int right);
int particiona(int vetor[], int left, int right);
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
	quickSort(arquivo, 0, (int)S -1);
	imprimirVetor(arquivo, S, -1, -1);  	
	return(0);
}

//Função genéria de troca de valores
void troca(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//Aplica o modo do Quicksort
int quickSort(int vetor[], int left, int right) {
  int r;
  if (right > left) {
    r = particiona(vetor, left, right);
    quickSort(vetor, left, r - 1);
    quickSort(vetor, r + 1, right);
  }
}

//Divide o vetor em pedaços menores
int particiona(int vetor[], int left, int right) {
  int i, j;
  i = left;
  for (j = left + 1; j <= right; ++j) {
    if (vetor[j] < vetor[left]) {
      ++i;
      troca(&vetor[i], &vetor[j]);
    }
	imprimirVetor(vetor, S, i, j);    
  }
  troca(&vetor[left], &vetor[i]);
  return i;
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

