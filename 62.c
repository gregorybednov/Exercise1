#include <stdio.h>
#include <stdlib.h>

#define N 100
#define N2 200
#define N3 50
void printarray (int *arr, size_t size) {
	size_t index;
	for (index = 0; index<size; ++index) {
		printf("%d ", arr[index]);
	}
	printf("\n");
}

void printall (int *arr, size_t size, char *name) {
	printf("Address of %s: %p; size of %s: %u. Contains:\n", name, arr, name, (unsigned int)size);
	printarray(arr, size);
}

int printrealloc (int *arr, size_t newsize, char *name) {
	int *oldArr = arr;
	arr = realloc(arr, newsize);
	if (oldArr == arr) printf("Address of %s changed!",name);
}

int main(void) {
	int *A = calloc(N,sizeof(int));
	int *B = malloc(N*sizeof(int));
	printall(A, N, "A");
	printall(B, N, "B");
	A = realloc(A, N2*sizeof(int));
	B = realloc(B, N3*sizeof(int));
	printf("A = %p, B = %p\n", A, B);
	printrealloc(A,N3*sizeof(int), "A");
	printrealloc(B,N2*sizeof(int), "B");
	printf("A = %p, B = %p\n", A, B);
	free(A);
	free(B);
	return 0;
}
