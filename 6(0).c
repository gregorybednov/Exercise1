/*Lab #6. Step 0.
 * Dynamic memory allocation */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

size_t scansize(FILE *fp) { /* scans a size value from FILE*/
	unsigned int tmp;
	fscanf(fp, "%u", &tmp);
	return (size_t)tmp;
}

void cleverfree(int** dim2arr, size_t fail_index) {
	while (fail_index--) free(dim2arr[fail_index]);
	free(*dim2arr);
	free(dim2arr);
}

int main(void) {
	int **arr;
	size_t i, j, n, *rowsizearr;
	printf("Enter number of rows in matrix: ");
	n = scansize(stdin);
	arr = (int**)malloc(n*sizeof(int*));
	if (arr==NULL) return errno;
	rowsizearr = (size_t*)malloc(n*sizeof(size_t));
	if (rowsizearr==NULL) {
			free(arr);
			return errno;
	}
	
	/*allocating memory*/
	for (i=0; i<n; ++i) {
		printf("Enter number of columns of row#%u: ",(unsigned int)i);
		rowsizearr[i] = scansize(stdin);
		arr[i] = (int*)malloc(rowsizearr[i]*sizeof(int));
		if (arr==NULL) {
			cleverfree(arr,i);
			free(rowsizearr);
			return errno;
		}
	}

	/*scanning elements of array*/
	for (i=0; i<n; i++) {
		for (j=0; j<rowsizearr[i]; ++j) {
			printf("arr[%u][%u] = ", (unsigned int)i,(unsigned int)j);
			scanf("%d", &arr[i][j]);
		}
	}

	/*printing elements of array*/
	for (i=0; i<n; ++i) {
		for (j=0; j<rowsizearr[i]; ++j) {
		       printf("%5d", arr[i][j]);
		}
 		printf("\n");
	}

	/*freeing elements of array*/
	cleverfree(arr, n);
	free(rowsizearr);

	return 0;
} 