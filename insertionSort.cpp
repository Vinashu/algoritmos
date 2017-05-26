int* insertionSort(int arquivo[], int tamanho)
{               
	int i, j, tmp;
	for(i = 1; i < tamanho; i++){
		j = i;
		while((arquivo[j] < arquivo[j - 1]) && (j!=0)){
			tmp = arquivo[j];
			arquivo[j] = arquivo[j-1];
			arquivo[j-1] = tmp;
			j--;    
		}               
	}
	return arquivo;
}
