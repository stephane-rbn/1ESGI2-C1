# Tableaux et pointeurs

## I - Construction de tableaux statiques à 1 dimension

> Définition : Un tableau en C est un ensemble de valeurs de même type et de taille fixe, identifié par un nom de variable unique.

- Construction : **type id[taille];**

```c
/* exemple */

int array[6];
```

- Accès : **id[indice]**

Remarque : **type id[T] = {v0, v1, ... vT-1};**

```c
/* exemple */

char array[3] = {'a', 'b', 'c'};
/* type id[] = {v0, v1, ..., vT-1}; */
```

## II - Exemples

(cf. exercices/)

## III - Pointeurs

***Objectifs :***

- fonctions
- chaines
- fichiers
- structures de données dynamiques, tableaux, listes chainées...

>Définition : Un pointeur est une variable dont le contenu est une adresse mémoire (RAM).

***Construction :*** 2 types de pointeur

Les pointeurs typés (pointent vers un type de données précis) :
```c
/* exemples */

/* type * nomPointer; */

int * p;
double * q;
char * r;
```

Les pointeurs non typés (pointent vers n'importe quel type de données) :

```c
void * ptr;
/* génériques */
```

***Opérateurs :***

- `&` -> opérateur d'adressage : **&variable**

Retourne l'adresse d'une variable en particulier.

```c
/* exemples */

int n = 15;
int *p;
p = &n;
```
- `*` -> opérateur d'indirection (ou de déréférencement) : ***pointeur**

Retourne la valeur qui se trouve à une adresse précise.

```c
  /* En sachant que n est stocké à l'adresse 10 000
   * et qu'il prend 4 octets en mémoire.
   */

  int n = 15;
  int *p;
  int **q;
  p = &n;
  q = &p;

  printf("%p", p); /* -> 10 000 */
  printf("%p", &p); /* -> 10 004 */
  printf("%d", *p); /* -> 15 */

  printf("%p", q); /* -> 10 004 */
  printf("%p", &q); /* -> 10 008 */
  printf("%p", *q); /* -> 10 000 */
  printf("%d", **q); /* -> 15 */
```
Autre exemple :

```c
#include <stdio.h>

int main(void) {
    int i;
    int *ptr;

    i = 100;
    ptr = &i;

    printf("%d\n", i);            /* valeur de i => 100 */
    printf("%p\n", (void*) ptr);  /* adresse de i => 0x7ffee50ce3a8 */
    printf("%p\n", (void*) &i);   /* adresse de i => 0x7ffee50ce3a8 */
    printf("%p\n", (void*) &ptr); /* adresse de ptr => 0x7ffee50ce3a0 */
    printf("%d\n", *ptr);         /* valeur qui se trouve à l'adresse stockée dans ptr => 100 */
    printf("%d\n", *(&i));        /* valeur qui se trouve à l'adresse de i => 100 */

    return 0;
}
```

- `+` -> Addition de pointeurs (de même nature !)

```c
/* ptr = ptr + entier */

/* exemple */

p = p + 1;
/* (*sizeof(type)) */
```
- `-` -> Soustraction de pointeurs (de même nature !)

```c
nb = ptr1 - ptr2
/* = entier */
```
- `=` ->
