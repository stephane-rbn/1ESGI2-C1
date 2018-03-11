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

int main(int argc, char **argv) {
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

## Relations tableaux / pointeurs

L'adresse en mémoire d'un tableau et l'adresse de la 1ère valeur du tableau. Pour obtenir l'adresse d'un **tableau**, l'opérateur `&` n'est pas utile (on n'obtiendrait pas l'adresse attendue).

Ainsi : `array => &array[0]` donne l'adresse du tableau `array`.

Quand on fait un `printf()` de `array`, on obtient cette adresse et non l'affichage du tableau.

Aussi : (ceci sera illustré juste après)

> pointeur => tableau ET tableau => pointeur

- Equivalences :

```c
int array[5] = {11, 22, 33, 44, 55};
int *ptr;

ptr = array;
```

On suppose les adresses suivantes :

|valeurs|11|22|33|44|55|
|--|--|--|--|--|--|
|adresses|1000|1004|1008|1012|1016|

Alors :

```c
/*
    ptr => array => &array[0] => (ptr + 0) => 1000
    *ptr => *(array + 0) => *(ptr + 0) => ptr[0] => 11

    ptr + 1 => array + 1 => &array[1] => 1004
    *(ptr + 1) => *(array + 1) => array[1] => ptr[1] => 22

    ptr + i => array + i => &array[i] => adresse à la position i
    *(ptr + i) => *(array + i) => array[i] => ptr[i] => valeur à la position i
*/
```

- Autre exemple : à 1 dimension

```c
float array[10];

for (i = 0; i < 10; i++) {
    scanf("%f", array + i);
}

/*
 *     array <=> &array[0]
 * array + 1 <=> &array[1]
 * array + i <=> &array[i]
 *
 *       *array <=> array[0]
 * *(array + 1) <=> array[1]
 * *(array + i) <=> array[i]
 *
 */
```

- Création de tableau dynamique avec `malloc()` :
```c
int *p;

p = malloc(2500000 * sizeof(int));

if (p! = NULL) {
    for (i = 0; i < 2500000; i++) {
        p[i] = rand();
    }
}

free(p);

/* malloc(<nb d'octets> * sizeof(<type>)); */
```

Augmenter dynamiquement la taille d'un tableau d'une case :

| p |
| --- |
| @2000 |

| 0 | 1 | 2 | 3 | 4 |
| --- | --- | --- | --- | --- |
| 10 | 20 | 30 | 0 | 40 |

```c
int *q;

q = malloc(6 * sizeof(int));

for (i = 0; i < 5; i++) {
    q[i] = p[i];
}
```

| q |
| --- |
| @10000 |

| 0 | 1 | 2 | 3 | 4 |
| --- | --- | --- | --- | --- |
| 10 | 20 | 30 | 0 | 40 | 50 |

```c
q[5] = 50;

free(p);

p = q;
```

| p |
| --- |
| @10000 |

| 0 | 1 | 2 | 3 | 4 | 5 |
| --- | --- | --- | --- | --- | --- |
| 10 | 20 | 30 | 0 | 40 | 50 |
