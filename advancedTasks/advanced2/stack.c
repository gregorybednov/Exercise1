#include "stack.h"

const minCapacity = 100;

unsigned *stackMemory = NULL;
size_t stackCapacity = 0;
size_t here = 0;

size_t size(void) {
	return here;
}

unsigned pop(void) {
	if (!here) return 0;
	return stackMemory[--here];
}

unsigned back(void) {
	if (!here) return 0;
	return stackMemory[here-1];
}

void moreCapacity (void) {
	if (stackCapacity<minCapacity) stackCapacity = minCapacity;
	else stackCapacity = (stackCapacity*3)/2;
	stackMemory = realloc(stackMemory, stackCapacity*sizeof(unsigned));
}

void push (unsigned x) {
	if (!here) moreCapacity();
	if (here==stackCapacity) moreCapacity();
	stackMemory[here++] = x;
}

void clear(void) {
	free(stackMemory);
	here = 0;
	stackCapacity = 0;
}
