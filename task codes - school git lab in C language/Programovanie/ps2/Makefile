CC=gcc
CFLAGS=-std=c11 -Werror -Wall -Wconversion
LDLIBS=-lm

all: hof.o k.o ui.o main.o
	echo "Running compilation";
	$(CC) $(CFLAGS) $^  $(LDLIBS) -o game

main.o: main.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

hof.o: hof.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

k.o: k.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

ui.o: ui.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

clean: 
	rm -rf *.o bin/*

