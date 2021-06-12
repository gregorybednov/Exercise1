#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE -10
#define MAX_VALUE  10
#define SIZE 50

void fillArray (int *array, int minimum, int maximum, size_t size) {
	size_t i;
	for (i = 0; i<size; ++i) {
		array[i] = minimum + rand()%(1+maximum-minimum);
	}
}

void printArray (int *array, size_t size) {
	size_t i;
	for (i = 0; i<size; ++i) {
		printf("%d ",array[i]);
	}
}

int minimumArray (int *array, size_t size) {
	int res = array[0];
	size_t i;
	for (i = 0; i<size; ++i) {
		if (res>array[i]) res = array[i];
	}
	return res;
}

void replaceInArrayByCondition (int *array, size_t size, int (*P)(void*), int val) {
	size_t i = 0;
	for (i = 0; i<size; ++i) {
		if (P(&array[i])) array[i] = val;
	}
}

int isPositive (void *pointer) {
	int *pint = (int*)pointer;
	return (*pint>0);
}	

int main(void) {
	int arr[SIZE];
	int m;
	srand(time(NULL));
	fillArray(arr, MIN_VALUE, MAX_VALUE, SIZE);
	m = minimumArray(arr, SIZE);
	if (m<0) replaceInArrayByCondition(arr, SIZE, isPositive, -m);
	printArray(arr, SIZE);
	printf("\n");
	return 0;
}
