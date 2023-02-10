CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89

all:
	$(CC) $(CFLAGS) *.c -o hsh

clean:
	rm -f hsh

.PHONY: all clean





