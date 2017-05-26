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


//Aplica o modo MergeSort 
int mergeSort(int vetor[], int tamanho);
void junta(int vetor[], int tamanho);
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
	mergeSort(arquivo, S);
	imprimirVetor(arquivo, S, -1, -1);		
	return(0);
}

//Aplica o modo MergeSort 
int mergeSort(int vetor[], int tamanho) {
  int mid;
   
  if (tamanho > 1) {
    mid = tamanho / 2;
    mergeSort(vetor, mid);
    mergeSort(vetor + mid, tamanho - mid);
    junta(vetor, tamanho);   
  } 
}

//Junta os pedaços num novo vetor ordenado
void junta(int vetor[], int tamanho) {
  int i, j, k;
  int mid;
  int* tmp;
 
  tmp = (int*) malloc(tamanho * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }
 
  mid = tamanho / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < tamanho) {
    if (vetor[i] < vetor[j]) {
      tmp[k] = vetor[i];
      ++i;
    }
    else {
      tmp[k] = vetor[j];
      ++j;
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < tamanho) {
    	tmp[k] = vetor[j];
    	++j;
    	++k;
    }
  }
  else {
    while (i < mid) {
      	tmp[k] = vetor[i];
      	++i;
      	++k;
    }
  }
 
  for (i = 0; i < tamanho; ++i) {
	vetor[i] = tmp[i];
	imprimirVetor(vetor, tamanho, i,j);	
  }
 
  free(tmp);
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
