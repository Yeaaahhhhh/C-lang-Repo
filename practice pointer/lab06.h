
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 10

void foo1(int *, int);
void foo2(int *, int);
int foo3(const int *, int);

void check_foo1(int *, int, int, char *);
void check_foo2(int *, int, int, char *);
void check_foo3(int *, int, int, char *);

bool keycomp(int, int);
void keyassign(int *, int);

void check_insert(const int [], int, int, char *file);
void insertionsort(int [], int);

void check_merge(const int [], int, int, char *file);
void mergesort(int [], int, int);
void merge(int [], int, int, int);
