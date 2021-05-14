/*Lab #6. Task 1.
 * Dynamic memory allocation */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define MAXSIZE 100
#define MINVALUE -1000
#define MAXVALUE 1000

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

int randomfromxtoy (int x, int y) {
	return x+rand()%(y-x+1);
}

int main(void) {
	int **arr, minvalue, maxvalue;
	size_t i, j, n, *rowsizearr, maxrowsize;
	srand(time(NULL));
	printf("Enter maximum number of rows in matrix: ");
	n = scansize(stdin);
	n = rand()%n;
	printf("Enter maximum numnber of columns in each row: ");
	maxrowsize = scansize(stdin);
	printf("Enter minimum value of element in array: ");
	scanf("%d",&minvalue);
	printf("Enter maximum value of element in array: ");
	scanf("%d",&maxvalue);
	arr = (int**)malloc(n*sizeof(int*));
	if (arr==NULL) return errno;
	rowsizearr = (size_t*)malloc(n*sizeof(size_t));
	if (rowsizearr==NULL) {
		free(arr);
		return errno;
	}
	
	/*allocating memory*/
	for (i=0; i<n; ++i) {
		rowsizearr[i] = rand()%maxrowsize;
		arr[i] = (int*)malloc(rowsizearr[i]*sizeof(int));
		if (arr==NULL) {
			cleverfree(arr,i);
			free(rowsizearr);
			return errno;
		}
	}

	/*generating elements of array*/
	for (i=0; i<n; i++) {
		for (j=0; j<rowsizearr[i]; ++j) {
			arr[i][j] = randomfromxtoy(minvalue, maxvalue);
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
