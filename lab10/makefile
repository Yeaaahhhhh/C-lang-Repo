
# lab10.o is also compiled using -ggdb option

ex10q1: ex10q1.c lab10.h
	gcc -Wall -std=c99 -ggdb ex10q1.c lab10.o -o ex10q1

all: lab10.o ex10q1

lab10.o: lab10.c lab10.h
	gcc -Wall -std=c99 -ggdb -c lab10.c

tar:
	tar -cvf submit.tar lab10.h lab10.o ex10q1.c makefile
