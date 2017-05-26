//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define tamanho 10

//Variáveis
int lista[tamanho];
int ordenado[tamanho];
int indice;
int opt=-1;
int qtd;

//Prototipação
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);
void troca(int* a, int* b);
int bubleSort(int vec[]);
int quickSort(int vec[], int left, int right, int qtd);
int particiona(int vec[], int left, int right);
int mergeSort(int vec[], int tam, int qtd);
void junta(int vec[], int tam);
int selectionSort(int vec[], int tam);
int shellSort(int vec[], int tam);
int insertionSort(int vec[], int tam);

//Função Principal
int main(void){
  srand(time(NULL));	
  do {
    system("cls");  
	lista_mostrar();	
	lista_mostrar_ordenado();
    menu_mostrar();
    scanf("%d",&opt);
    switch (opt){
      case 1:
      	lista_gerar();
      break;
      case 2:
      	lista_ler();
      break;
      case 3:
  		lista_limpar();      	
      	qtd = bubleSort(ordenado);
      break; 
      case 4:
  		lista_limpar();      	
      	qtd = selectionSort(ordenado, tamanho);
      break;  
      case 5:
  		lista_limpar();      	
      	qtd = mergeSort(ordenado, tamanho, 0);
      break;  
      case 6:
  		lista_limpar();      	
      	qtd = quickSort(ordenado, 0, tamanho, 0);
      break;  
      case 7:
  		lista_limpar();      	
      	qtd = insertionSort(ordenado, tamanho);
      break; 
      case 8:
  		lista_limpar();      	
      	qtd = shellSort(ordenado, tamanho);
      break; 
    }
  }	while(opt!=0);
  system("pause");
  return(0);
}

//Mostra o conteúdo da lista
void lista_mostrar(void){
  printf("[  ");	
  for (int i = 0; i < tamanho; i++ ){
  	printf("%d  ",lista[i]);
  }
  printf("]\n\n");
}

//Mostra o menu
void menu_mostrar(void){
  printf("1 - Gerar lista aleatoriamente\n");
  printf("2 - Criar lista manualmente\n");
  printf("3 - Ordenar pelo metodo da BubleSort\n");  
  printf("4 - Ordenar pelo metodo do SelectionSort\n"); 
  printf("5 - Ordenar pelo metodo do MergeSort\n");             
  printf("6 - Ordenar pelo metodo do QuickSort\n");    
  printf("7 - Ordenar pelo metodo do InsertionSort\n");     
  printf("8 - Ordenar pelo metodo do ShellSort\n");          
  printf("0 - Sair...\n\n");
}

//Gera uma lista aleatória
void lista_gerar(void){
  for (int i = 0; i < tamanho; i++){
  	lista[i] = rand()%50;
  }
}

//Permite que o usuário entre com os valores da lista
void lista_ler(void){
  for (int i = 0; i < tamanho; i++){
  	system("cls");
  	lista_mostrar();
  	printf("\nDigite o valor para a posicao %d: ", i);
  	scanf("%d", &lista[i]);
  }
}

//Preparar a lista para ordenação
void lista_limpar(void){
  for (int i = 0; i < tamanho; i++)	{
  	ordenado[i] = lista[i];
  }
}

//Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(void){
  printf("[  ");	
  for (int i = 0; i < tamanho; i++ ){
  	printf("%d  ",ordenado[i]);
  }
  printf("] Tempo = %d iteracoes\n\n", qtd);
}

//Função genéria de troca de valores
void troca(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//Aplica o metodo do bubleSort
int bubleSort(int vec[]){
  int qtd, i, j, tmp;
  qtd = 0;
  for (i = 0; i < tamanho -1; i++){
  	for (j = i+1; j < tamanho; j++){
  	  if (vec[i] > vec[j]){
  	  	troca(&vec[i], &vec[j]);
  	  }
  	  qtd++;	
  	}
  } 
  return(qtd);
}

//Aplica o modo do Quicksort
int quickSort(int vec[], int left, int right, int qtd) {
  int r;
  if (right > left) {
    r = particiona(vec, left, right);
    qtd = quickSort(vec, left, r - 1, qtd);
    qtd = quickSort(vec, r + 1, right, qtd);
  }
  return (qtd +1);
}

//Divide o vetor em pedaços menores
int particiona(int vec[], int left, int right) {
  int i, j;
  i = left;
  for (j = left + 1; j <= right; ++j) {
    if (vec[j] < vec[left]) {
      ++i;
      troca(&vec[i], &vec[j]);
    }
  }
  troca(&vec[left], &vec[i]);
  return i;
}

//Aplica o modo MergeSort 
int mergeSort(int vec[], int tam, int qtd) {
  int mid;
 
  if (tam > 1) {
    mid = tam / 2;
    qtd = mergeSort(vec, mid, qtd);
    qtd = mergeSort(vec + mid, tam - mid, qtd);
    junta(vec, tam);
  }
  return (qtd+1);
}

//Junta os pedaços num novo vetor ordenado
void junta(int vec[], int tam) {
  int i, j, k;
  int mid;
  int* tmp;
 
  tmp = (int*) malloc(tam * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }
 
  mid = tam / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < tam) {
    if (vec[i] < vec[j]) {
      tmp[k] = vec[i];
      ++i;
    }
    else {
      tmp[k] = vec[j];
      ++j;
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < tam) {
      tmp[k] = vec[j];
      ++j;
      ++k;
    }
  }
  else {
    while (i < mid) {
      tmp[k] = vec[i];
      ++i;
      ++k;
    }
  }
 
  for (i = 0; i < tam; ++i) {
    vec[i] = tmp[i];
  }
 
  free(tmp);
}

//Aplica o modo selectionSort 
int selectionSort(int vec[], int tam){ 
  int i, j, min, qtd=0;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(vec[j] < vec[min]) {
         min = j;
       }
       qtd++;
     }
     if (i != min) {
       troca(&vec[i], &vec[min]);
     }
  }
  return(qtd);
}

//Aplica o shellSort
int shellSort(int vec[], int tam) {
  int i , j , valor, qtd=0;
  int gap = 1;
  do {
    gap = 3*gap+1;
  } while(gap < tam);
  do {
    gap /= 3;
    for(i = gap; i < tam; i++) {
      valor = vec[i];
      j = i - gap;
      while (j >= 0 && valor < vec[j]) {
        vec[j + gap] = vec[j];
        j -= gap;
        qtd++;
      }
      vec[j + gap] = valor;
    }
  } while ( gap > 1);
  return (qtd);
}

//Aplicando o insetionSort
int insertionSort(int vec[], int tam)
{               
  int i, j, qtd=0;
  for(i = 1; i < tam; i++){
    j = i;
    while((vec[j] < vec[j - 1]) && (j!=0)){
      troca(&vec[j], &vec[j-1]);	
      j--;    
      qtd++;
    }               
  }
  return(qtd);
}

