.PHONY: all clean install unistall
CFLAGS = -Wextra -Wcast-qual -Wconversion -Wshadow -Wunreachable-code -Winit-self -O2 -std=c89
all:
	advanced1
clean:
	rm -rf advanced1 *.o
main.o: advanced1.c queue.h
	cc -c $(CFLAGS) -o advanced1.o advanced1.c
queue.o:queue.c queue.h
	cc -c $(CFLAGS) -o queue.o queue.c
advanced1: advanced1.o queue.o
	cc -o advanced1 advanced1.o queue.o
install:
	install ./advanced1 /usr/local/bin
uninstall:
	rm -rf /usr/local/bin/advanced1
