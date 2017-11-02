# Les bases du C

## I - Introduction 

### Versions

Dans les années 70, création du C.

Dennis Ritchie : ingénieur en chef qui pilotait le programme de recherche.

1978: standard C (K et R)

1989/90 : norme ANSI/ISO (la plus utilisée)

1999 : C99 (ressemble un peu à du C++) 

### Vocabulaire

Différents types de language :

- Language machine : binaire
- Languages d'assemblage : mnémoniques (ADD SUB MOVE JUMP...) -> assembleur -> binaire (1000 1010...)
- Language évolués

Traducteurs :

- interpréteurs : logiciel qui traduit + exécute (HTML, CSS, PHP, JS, Ruby, Python)
- compilateurs : logiciel qui traduit + enregistre les instructions traduites dans un fichier programme tel que .exe sous Windows (C, Go)

### Étapes

- Édition de source : fichier.c
- Compilation
- Fichier objet : fichier.o ou fichier.obj
- Éditions des liens (linker) : intégration du fichier objet + bibliothèques (.lib, .a, .o)
- Fichier programme (.exe)

Erreurs :

- Syntaxe au niveau de la compilation
- Problèmes de fichier au niveau de l'édition des liens
- Problèmes d'exécutions et bugs du programme final

### Les IDE

- Code::Blocks
- Visual Studio
- XCode
- Eclipse
- NetBeans
- IntelliJ
- Android Studio
- CLion

## II - Exemples
(cf. premier code main.c)

## III - Règles de syntaxe

### Rappels

Toutes les lignes de finissent par `;`

Faire attention à la casse. Variables en majuscules, comme M_PI qui s'utilse avec la bibliothèque math.h

Les acolades `{}` délimitent le début et la fin.

Commentaires : `//` ou `/* */` pour du multiligne.

### Variables

On utilise que des caractères alphanumériques pour les variables. On commence par une lettre ou par `_`.

Possible : 

- prix
- Prix
- prix20
- prix_20

Pas possible :

- prix 20
- 20_prix
- PRIX

Conventions

- Écrire en anglais
- Donner un nom explicite
- studentMark (Camel Case, la plus utilisée)
- student_mark (Snake case)
- Utiliser une même casse pour les variables dans un même programme

Types de variables :

- entiers
- réels
- symboles


#### Entiers

- Signed : entiers relatifs
- Unsigned : entier naturels
- short (2 octets)
- int (4 octets)
- long (4 octets)

1 octet : de -128 à 127 (de 0 à 255 en non-signé)  
2 octets : - 32000 à 32000 (de 0 à 65000 en non-signé)  
4 octets : - 2,5 milliards à 2,5 milliards (ou de 0 à 5 milliards en non-signé)  
8 octets : -2.3E-308 to 1.7E+308 

Exemples :  
- `unsigned int zipcode`  
- `unsigned short n = 20`  
- `signed int p = 50`

Codes format :

- `%hd`
- `%hu`
- `%d`
- `%u`
- `%ld`
- `%lu`

u pour unsigned, h pour short et l pour long.

Les bases :

- n = 10; base 10
- n = 010; base 8
- n = 0x10; base 16

#### Réels

- float (4o), %f et %e
- double (8o) %lf et %le

float est non précis. Pour préciser x=1.2 : `fabs(x-1.2)<1e-6`

#### Symboles

Opérateurs :

- Calculs : `+ - / * %`
- Logiques : `-	< > <= >= == != && || !(cond)
`
- Affectation : `= += -= /= %= *= `

Pour obtenir le chiffre des dizaines avec `%`:

- `n = 123`
- `n = n/10 => 12`
- `n = n%10 => 2`

`z = pow(2, 3) => 2^3`

`z = pow(x, 1./3) => donne un double`

`int n = 1 ;`
`int p = 3 ;`

`pow(x, n/p) ; donne un int qui vaut 0
on peut changer : pow(x, n*1./p)

#### Format specifiers (codes format)

code format : dit au compilateur quel type de valeur on veut afficher avec printf par exemple

| Format specifiers | signed + - | unsigned + |
| ----- | ------ | -------- |
| char (1 octet) | `%c` | `%c` |
| short (2 octets) | `%hd` | `%hu` |
| int (4 octets) | `%d` | `%u` |
| long (4 octets) | `%ld` | `%lu` |
| float (4 octets) | `%f` | `%e` |
| double (8 octets) | `%lf` | `%le` |

`char` -> `short` -> `int` -> `long` -> `float` -> `double`

`char` (1 octet) permet de :

- stocker des petits nombres entiers
- stocker des symboles

`signed char c;`  
`unsigned char c;`

#### ASCII

| Caractère | Valeur Décimale |
| --- | --- |
| 0 | 48 |
| A | 65 |
| a | 97 |

La table ASCII standard possède 128 caractères (de 0 à 127).

La table ASCII extended en possèdent 256 (de 0 à 127 puis de 128 à 255) car :  
 
 - **1 caractère vaut 1 octet**  
 - **1 octet vaut 8 bits**
 - **8 bits représentent 8 cases dans lesquelles on peut mettre des 0 et des 1, donc 2^8 combinaisons**

 | Caractère | Décimale | Binaire |
 | --- | --- | --- |
 | `NUL` | 0 | 0000 0000 |
 | `SOH` | 1 | 0000 0001 |
 | ... | ... | ... |
 | `~` | 126 | 0111 1110 |
 | `DEL` | 127 | 0111 1111 |
 | ... | ... | ... |
 | `nbsp` | 255 | 1111 1111 |


> Un nombre entier en C est comme une condition : différent de 0 vaut VRAI, égal à 0 vaut FAUX