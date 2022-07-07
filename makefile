CC=gcc
CF=-g -Wall
OF=-g -Wall -c
NME=test

all: clean build

build: main.c llist.o io.o merge.o file.o
	$(CC) $(CF) $^ -o $(NME)
llist.o: llist.c llist.h
	$(CC) $(OF) $<
io.o: io.c io.h
	$(CC) $(OF) $<
merge.o: merge.c merge.h
	$(CC) $(OF) $<
file.o: file.c file.h
	$(CC) $(OF) $<
clean:
	clear
	rm -f $(NME)
	rm -f *.o