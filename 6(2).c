#include <stdio.h>
#include <stdlib.h>

#define N 100
#define N2 200
#define N3 50

void printArray (int *arr, size_t size) {
	size_t index;
	for (index = 0; index<size; ++index) {
		printf("%d ", arr[index]);
	}
	printf("\n");
}

void printAll (int *arr, size_t size, char *name) {
	printf("Address of %s: %p; size of %s: %u. Contains:\n", name, (void*)arr, name, (unsigned int)size);
	printArray(arr, size);
}

int printRealloc (int *arr, size_t newSize, char *name) {
	int *oldArr = arr;
	arr = realloc(arr, newSize);
	if (oldArr == arr) printf("Address of %s changed!", name);
}

int main(void) {
	int *A = calloc(N,sizeof(int));
	int *B = malloc(N*sizeof(int));
	printAll(A, N, "A");
	printAll(B, N, "B");
	A = realloc(A, N2*sizeof(int));
	B = realloc(B, N3*sizeof(int));
	printf("A = %p, B = %p\n", (void*)A, (void*)B);
	printRealloc(A, N3*sizeof(int), "A");
	printRealloc(B, N2*sizeof(int), "B");
	printf("A = %p, B = %p\n", (void*)A, (void*)B);
	free(A);
	free(B);
	return 0;
} 
