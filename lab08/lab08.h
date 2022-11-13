
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void gcd(int, int, int *, int *);
void check_gcd(int, int, int, int, int, char *);


bool validate(const char *);
char *add(const char *, const char *);
bool eq(const char *, const char *);
bool gt(const char *, const char *);
char *diff(const char *, const char *);
char *multiply(const char *, const char *);
char *divide(const char *, const char *);
char *modulo(const char *, const char *);

void check_validate(const char *, int, char *);
void check_add(const char *, const char *, int, char *);
void check_eq(const char *, const char *, int, char *);
void check_gt(const char *, const char *, int, char *);
void check_diff(const char *, const char *, int, char *);
void check_multiply(const char *, const char *, int, char *);
void check_divide(const char *, const char *, int, char *);
void check_modulo(const char *, const char *, int, char *);

