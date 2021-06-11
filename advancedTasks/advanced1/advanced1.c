#include <stdio.h>
#include "queue.h"

#define FIRST 5
#define SECOND 5
#define VERY_BIG_NUMBER 1000000

unsigned readUnsigned (void) {
	unsigned tmp;
	scanf("%u", &tmp);
	return tmp;
}

void printCorrectly (int turns) {
	if (turns<0) printf("first %u", (unsigned)(-turns));
	if (turns==0) printf("botva");
	if (turns>0) printf("second %u", (unsigned)turns);
	printf("\n");
}

int game (queue *g1, queue *g2) {
	int turn = 0;
	while (!isEmpty(*g1) && !isEmpty(*g2)) {
		unsigned v1 = get(g1);
		unsigned v2 = get(g2);
		if ((v1<v2 && !(v1==0 && v2==9)) || (v2==0 && v1==9)) {
		       	append(g2, v1);
			append(g2, v2);
		}
		if (v1==v2) return 0;
		if ((v1>v2 && !(v2==0 && v1==9)) || (v1==0 && v2==9)) {
			append(g1, v1);
			append(g1, v2);
		}
		++turn;
		if (turn>=VERY_BIG_NUMBER) return 0; 
	}
	if (isEmpty(*g1)) return turn;	/* g2 is winner */
	if (isEmpty(*g2)) return -turn;	/* g1 is winner */
}

int main(void) {
	size_t i;
	queue *g1, *g2;
	g1 = allocQueue();
	g2 = allocQueue();
	for (i = 0; i < FIRST; ++i) {
		append(g1, readUnsigned());
	}
	for (i = 0; i < SECOND; ++i) {
		append(g2, readUnsigned());
	}
	printCorrectly(game(g1, g2));
	freeQueue(g1);
	freeQueue(g2);
	return 0;
}
