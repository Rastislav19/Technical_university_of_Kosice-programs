CC=gcc
SOURCES=backpack.c main.c command.c container.c game.c item.c parser.c room.c world.c  
LDLIBS=-lm
CFLAGS=-std=c11 -Wall -Werror -fstack-protector -Wconversion
OUTPUT=ps5


$(OUTPUT): main.o container.o command.o game.o backpack.o parser.o item.o world.o room.o
	$(CC) $(CFLAGS) main.o container.o command.o game.o backpack.o parser.o item.o world.o room.o $(LDLIBS) -o $(OUTPUT)

container.o: container.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

command.o: command.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

game.o: game.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

backpack.o: backpack.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

parser.o: parser.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

item.o: item.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

world.o: world.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

room.o: room.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@


clean:
	rm -rf *.o $(OUTPUT)

push:
	git commit -a
	git push

all: ps5

co: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^
val: $(SOURCES)
	valgrind --leak-check=yes $^ 

