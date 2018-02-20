/**
 * File: sizeof_some_variables.c
 *
 * Fichier source à compiler pour connaître la taille en octet
 * de vos types de variable sur votre machine.
 *
 */

#include <stdio.h>

int main(int argc, char **argv) {
    printf("char: %lu\n", sizeof(char));
    printf("int: %lu\n", sizeof(int));
    printf("long: %lu\n", sizeof(long));
    printf("float: %lu\n", sizeof(float));
    printf("double: %lu\n", sizeof(double));
    printf("\n");
    printf("void*: %lu\n", sizeof(void*));
    printf("int*: %lu\n", sizeof(int*));
    printf("float*: %lu\n", sizeof(float*));
    printf("long*: %lu\n", sizeof(long*));
    printf("double*: %lu\n", sizeof(double*));

    return 0;
}
