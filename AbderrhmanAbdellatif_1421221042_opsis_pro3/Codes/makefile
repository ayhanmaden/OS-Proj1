CC=gcc
CFLAGS=-c -Wall

all:readreader  xyztotalizer

readreader: readreader.c
	$(CC) readreader.c -lm -o readreader

xyztotalizer: xyztotalizer.c
	$(CC) xyztotalizer.c -pthread -o xyztotalizer
clean: 
	rm -rf *o myshell
