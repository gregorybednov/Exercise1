#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int randomABCD () {
	return rand()%10000;
}

void fill (int *array, const size_t size, int (gen)(void) ) {
	size_t i;
	for (i=0; i<size; ++i) {
		array[i] = gen();
	}
}

int isInteresting (const int val) {
	const int ab = (val%10000)/100;
	const int cd = val%100;
	return (ab==cd);
}

size_t calcSize (const int *array, const size_t size) {
	size_t i;
	size_t result = 0;
	for (i=0; i<size; ++i) {
		if (isInteresting(array[i])) ++result;
	}
	return result;
}

int *filter (const int *array, size_t size, size_t *newSize) {
	size_t i;
	size_t ires = 0;
	const size_t sizeResult = calcSize(array, size);
	int *result = malloc(size*sizeof(int));
	if (result==NULL) return NULL;
	for (i=0; (i<size)&&(ires<sizeResult); ++i) {
		if (isInteresting(array[i])) result[ires++] = array[i];
	}
	*newSize = sizeResult;
	return result;
}

void print (const int *array, size_t size) {
	size_t i;
	for (i=0; i<size; ++i) {
		printf("%5d", array[i]);
	}
}

unsigned int toUnsigned (char *argv[], size_t argIndex) {
	size_t i = 0;
	unsigned int result = 0;
	while (isdigit(argv[argIndex][i])) {
		result *= 10;
		result += (unsigned int)(argv[argIndex][i]-'0');
		i++;
	}
	return result;
}

int main(int argc, char* argv[]) {
	int *abcd, *filtered;
	size_t mainSize, filteredSize, argIndex;
	if (argc==1) printf("usage: task5 <NUMBER OF ELEMENTS>\n");
	argIndex = 1;
	srand(time(NULL));
	while (argIndex<argc) {
		mainSize = toUnsigned(argv, argIndex);
		abcd = malloc(mainSize*sizeof(int));
		fill(abcd, mainSize, randomABCD);
		filtered = filter(abcd, mainSize, &filteredSize);
		print(filtered,filteredSize); printf("\n");
		free(abcd);
		free(filtered);
		argIndex++;
	}
	return 0;
}

