CC=gcc
CFLAGS=-Wall -g

all: uimain

uimain: uimain.o tokenizer.o history.o
	$(CC) $(CFLAGS) -o uimain uimain.o tokenizer.o history.o

uimain.o: uimain.c tokenizer.h history.h
tokenizer.o: tokenizer.c tokenizer.h
history.o: history.c history.h

clean:
	rm -f *.o uimain
