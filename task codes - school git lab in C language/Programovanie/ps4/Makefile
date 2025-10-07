CC = gcc
OUTPUT = ps4
CFLAGS = stc=c11 -Wall -Werror
SOURCES = transformations.c bmp.c main.c
LDLUBS = -lm

all : ps4

$(OUTPUT) : main.o bmp.o transformations.o
	cppcheck == --enable=unusedFunction --error-exitcode=1 $(SOURCES)
	$(CC) $(CFLAGS) $(LDLIBS) -o $(OUTPUT)


main.o : main.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

transformations.o : transformations.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

bmp.o : bpm.c
	$(CC) $(CFLLAGS) -c $^ $(LDLIBS) -o $@


clean : rm -rf *.o $(OUTPUT)

	
