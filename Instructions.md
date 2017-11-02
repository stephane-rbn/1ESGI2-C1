# Instructions de tests et boucles

## I - Instructions de test

### 3 façons :

* `?:` (ternaire)
* `if`
* `switch`

### Syntaxe du *if* :

```
if (comparaison)
{
	// alors
}
else
{
	if 
	{
		// alors
	}
}
```

> Remarques : les accolades { } sont facultatives quand il n'y a qu'une instruction, (à compléter) .. 

ex :

```
double a, b, result;
scanf("%lf %lf", &a &b);
if(b == 0)
{
	printf("Erreur");
}
else
{
	result = a/b;
	printf("Résultat : %lf", result);
}
```

ex :

```
// inférieur à 5 voitures -> 150 euros de bonus par voiture
// entre 5 et 10 exclu    -> 250
// entre 10 et 20 exclu   -> 800
// au moins 20            -> 1000

double salary;
int nb;

scanf("%d", &nb);

if (nb >= 20) {
	salary = nb * 1000;
} else if (nb >= 10) {
	salary = nb * 800;
} else if (nb >= 5) {
	salary = nb * 250;
} else {
	salary = nb * 150;
}
```

### Syntaxe du *switch* :

```
switch (variable) {
	case v1: inst;
			 break;
	case v2: inst;
			 break;
	     ...
	case vn: inst;
			 break;
	default: instructions;
}
```

ex :

```
char character;

scanf("Saisissez un caractère : %c", &character);

switch (character) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
		printf("C'est une voyelle\n");
		break;
	default:
		printf("Ce n'est pas une voyelle\n");
}
```

## II - Instructions de boucle

### 3 instructions :

* `while`    -> 0 -> infini
* `do while` -> 1 -> infini
* `for`      ->

```
// Compter le nombre de chiffres impairs dans l'entier saisi
// ex : 256

int digit;
int number;
int count_odd_numbers;

count_odd_numbers = 0;

scanf("Saisissez un nombre : %d", &number);

while (number > 0) {
	digit = number % 10;
	if (digit % 2 == 1) {
		count_odd_numbers++;
	}
	number /= 10;
}
```

```
for(e1; e2; e3) {
	// instructions
}
```
e1 = une instruction **quelconque** qui est exécutée q'une seule fois   
e2 = une condition de continuation (vraie)  
e3 = une instruction quelconque exécutée à chaque passage dans la boucle


### Annexe
===

* `break`
* `continue`

```
while(c) {
	if(c) {
		continue
	}
}
```

```
for (i = 1; i < 10000; i++) {
	if(i % 17 == 0) {
		continue;
		sum = sum + i;
	}
}
```

```
// a
// bb
// ccc
// dddd
// eeeee

char a = 'a';
int nb, i, j;
scanf("%d", &nb)

for(i = 0; i < nb; i++) {
	for(j = 0; j < i; j++) {
		printf("%c", a);
	}
	a++
# 	printf("\n");
}
```