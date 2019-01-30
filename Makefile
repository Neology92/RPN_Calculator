CC=gcc
CFLAGS=
LDLIBS=

all: program

program: main.o funkcje.o 
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	
main.o: main.c main.h funkcje.h
	$(CC) $(CFLAGS) -c $< -o $@

funkcje.o: funkcje.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	-rm *.o $(objects)