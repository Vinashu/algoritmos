int* shellSort(int arquivo[], int tamanho) {
	int i , j , tmp;
	int gap = 1;
	do {
		gap = 3*gap+1;
	} while(gap < tamanho);
	do {
		gap /= 3;
		for(i = gap; i < tamanho; i++) {
			tmp = arquivo[i];
			j = i - gap;
			while (j >= 0 && tmp < arquivo[j]) {
				arquivo[j + gap] = arquivo[j];
				j -= gap;
			}
			arquivo[j + gap] = tmp;
		}
	} while ( gap > 1);
	return arquivo;
}
