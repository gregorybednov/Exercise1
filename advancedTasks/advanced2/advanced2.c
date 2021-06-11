#include <stdio.h>
#include "stack.h"

int flag = 1;

void scanPush(void) {
	unsigned tmp;
	scanf("%u", &tmp);
	push(tmp);
	printf("ok\n", tmp);
}

void sizePrint(void) {
	printf("%u ok\n", (unsigned)size());
}

void clearOk (void) {
	clear();
	printf("ok\n");
}

void clearBye (void) {
	clear();
	printf("bye\n");
	flag = 0;
}

void backPrint (void) {
	printf("%u ok\n", back());
}

void popPrint (void) {
	printf("%u ok\n", pop());
}

struct reader {
	size_t index;
	void (*function)(void);
	char name[6];
};

struct reader command[] = {
	{0,	scanPush,	"push"},
	{0,	popPrint,	"pop"},
	{0,	backPrint,	"back"},
	{0,	sizePrint,	"size"},
	{0,	clearOk,	"clear"},
	{0,	clearBye,	"exit"}
};

int main(void) {
	while (flag) {
		size_t i = 0;
		int c = fgetc(stdin);
		for (i = 0; i<(sizeof(command)/sizeof(struct reader)); ++i) {
			if (command[i].name[command[i].index]=='\0') command[i].function();
			if (command[i].name[command[i].index]==c) command[i].index++;
			else command[i].index = 0;
		}
	}
	return 0;
}
