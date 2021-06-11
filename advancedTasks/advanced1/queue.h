#include <stdlib.h>
#include <errno.h>
struct queueNode {
	unsigned value;
	struct queueNode *next;
};
typedef struct {
	size_t size;
	struct queueNode *begin;
	struct queueNode *end;
} queue;

/* NECESSARY TO CALL BEFORE ANY ANOTHER FUNCTION IN LIBRARY.
 * Returns errno if allocQueue() can't allocate queue in heap, else 0. */
queue *allocQueue(void);

/* NECESSARY TO CALL AFTER ALL USINGS OF QUEUES TO FREE MEMORY. */
void freeQueue(queue *pQ);

/* Returns a value from queue and free memory of it.
 * If it isn't availiable to return any value, return 0. */
unsigned get (queue *pQ);

/* Returns errno if append() can't allocate new element of queue, else 0. */
int append (queue *pQ, unsigned val);

/* Returns 1 if queue is empty and 0 if not. */
int isEmpty(queue Q);
