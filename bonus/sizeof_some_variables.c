/**
 * File: sizeof_some_variables.c
 *
 * Fichier source à compiler pour connaître la taille en octet
 * de vos types de variable sur votre machine.
 *
 */

#include <stdio.h>

int main(int argc, char **argv) {
    char c;
    int i;
    long l;
    float f;
    double d;

    c = 42;
    i = 42;
    l = 42;
    f = 42;
    d = 42;

    printf("char: %lu\n", sizeof(c));
    printf("int: %lu\n", sizeof(i));
    printf("long: %lu\n", sizeof(l));
    printf("float: %lu\n", sizeof(f));
    printf("double: %lu\n", sizeof(d));
    printf("\n");
    printf("void*: %lu\n", sizeof(void*));
    printf("int*: %lu\n", sizeof(int*));
    printf("float*: %lu\n", sizeof(float*));
    printf("long*: %lu\n", sizeof(long*));
    printf("double*: %lu\n", sizeof(double*));

    return 0;
}
