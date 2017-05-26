int* bubleSort(int arquivo[], int tamanho){
	int i, j, tmp;
	for (i = 0; i < tamanho -1; i++){
		for (j = i+1; j < tamanho; j++){
			if (arquivo[i] > arquivo[j]){
				tmp = arquivo[i];
				arquivo[i] = arquivo[j];
				arquivo[j] = tmp;
			}
		}
	} 
	return arquivo;
}


