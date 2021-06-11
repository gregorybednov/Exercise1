.PHONY: all clean install unistall
CFLAGS = -Wextra -Wcast-qual -Wconversion -Wshadow -Wunreachable-code -Winit-self -O2 -std=c89
all:
	advanced2
clean:
	rm -rf advanced2 *.o
main.o: advanced2.c stack.h
	cc -c $(CFLAGS) -o advanced2.o advanced2.c
stack.o:stack.c stack.h
	cc -c $(CFLAGS) -o stack.o stack.c
advanced2: advanced2.o stack.o
	cc -o advanced2 advanced2.o stack.o
install:
	install ./advanced2 /usr/local/bin
uninstall:
	rm -rf /usr/local/bin/advanced2
