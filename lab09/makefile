
# lab09.o is also compiled using -ggdb option

CC = gcc
CFLAGS = -Wall -std=c99 -ggdb
LDLIBS = -lm

executable = ex9q1
objects = ex9q1.o ex9q10.o ex9q11.o ex9q12.o lab09.o
submit = submit.tar

$(executable): $(objects)
    
ex9q1.o: ex9q1.c    
ex9q10.o: ex9q10.c    
ex9q11.o: ex9q11.c    
ex9q12.o: ex9q12.c

tar:
	tar -cvf $(submit) lab09.h ex9q1.c ex9q10.c ex9q11.c ex9q12.c lab09.o makefile
clean:
	rm -f $(executable) *.out core ex9q1.o ex9q10.o ex9q11.o ex9q12.o
