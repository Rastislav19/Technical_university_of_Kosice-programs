OUTPUT=ps1
CC=gcc
CFLAGS=-std=c11 -Werror -Wall
LDLIBS=-lm
SOURCE= main.c bmp.c playfair.c
CLEAN=clean

all: codanalysis $(OUTPUT)

codanalysis: $(SOURCE)
	 cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o playfair.o bmp.o
	echo "Running compilation";
	$(CC) $(CFLAGS) $^  $(LDLIBS) -o $@

main.o: main.c
	echo "Building object files";
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

playfair.o: playfair.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

bmp.o: bmp.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

push: pushing clean

clean:
	rm -r *.o ps1

pushing:
	git commit -a
	git push


