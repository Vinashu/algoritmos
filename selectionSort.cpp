int* selectionSort(int arquivo[], int tamanho){ 
	int i, j, menor, tmp;
	for (i = 0; i < (tamanho-1); i++) 
		{
			menor = i;
			for (j = (i+1); j < tamanho; j++) {
				if(arquivo[j] < arquivo[menor]) {
	 			menor = j;
			}
		}
		if (i != menor) {
			tmp = arquivo[i];
			arquivo[i] = arquivo[menor];
			arquivo[menor] = tmp;     	
		}
	}
	return arquivo;
}
