CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -O0

TARGETS = tokenizer test

all: $(TARGETS)

tokenizer: main.o tokenizer.o
	$(CC) $(CFLAGS) -o $@ $^

test: test_tokenizer.o tokenizer.o
	$(CC) $(CFLAGS) -o $@ $^
	./test

main.o: main.c tokenizer.h
	$(CC) $(CFLAGS) -c main.c

tokenizer.o: tokenizer.c tokenizer.h
	$(CC) $(CFLAGS) -c tokenizer.c

test_tokenizer.o: test_tokenizer.c tokenizer.h
	$(CC) $(CFLAGS) -c test_tokenizer.c

clean:
	rm -f *.o $(TARGETS)
