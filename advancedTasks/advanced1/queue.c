#include "queue.h"

queue *allocQueue(void) {
	queue *res = malloc(sizeof(queue));
	if (res==NULL) return NULL;
	res->size  = 0;
	res->begin = NULL;
	res->end   = NULL;
	return res;
}

unsigned get (queue *pQ) {
	unsigned tmp;
	struct queueNode *pnext;
	if (!pQ->size) return 0;
	pnext = pQ->begin->next;
	--(pQ->size);
	tmp = pQ->begin->value;
	free(pQ->begin);
	pQ->begin = pnext;
	return tmp;
}

int append (queue *pQ, unsigned val) {
	struct queueNode *newNode = malloc(sizeof(struct queueNode));
	if (newNode==NULL) return errno;
	newNode->value = val;
	newNode->next = NULL;
	if (pQ->size!=0) pQ->end->next = newNode;
	else pQ->begin = newNode;
	++(pQ->size);
	pQ->end = newNode;
	return 0;
}

int isEmpty(queue Q) {
	return !Q.size;
}

void freeQueue(queue *pQ) {
	while (!isEmpty(*pQ)) {
		get(pQ);
	}
	free(pQ);
}
