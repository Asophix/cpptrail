/** C++ kurzus - 0. program
*	A C nyelv bemutatása nagyvonalakban
*/

/* Egy C projekt az alábbi részekből áll: header (.h) és programfájl (.c).
*  Header:
*  - Újrafelhasználható logikát tartalmaz, amit a programfájl felhasznál.
*  - Vannak rendszerszintű (<>) és egyéni könyvtárak ("").
*  - A header-t include-olva az összes itt szereplő függvény és kód felhasználható.
*/

// Rendszer headerek
#include <stdio.h>
#include <stdlib.h>

// Egyéni header
#include "demo.h"

// main() - fő függvény, a program első belépési pontja.
// Visszatérési értéke van, ami a futás során keletkezett hibakód.
// 0-val tér vissza, ha nincs semmi gond.
int main()
{

	// 1. lépés: demo.h-ban megírt két egész számot összeadó függvény használata
	// Változó deklarációjának menete: [típus] [név] = [kezdőérték];
    int result = add(3, 4);

	// printf (szöveg, változó1, változó2, ...) - kiíró utasítás.
	// A szöveg "" között, változó behelyettesítése esetén %-os direktívával van megadva.
	//%d: int (decimal)
    //%lf: double (long float)
    //%s: char* (string, karakterek egymásutánja)
    //%c: char
    printf("The result: %d\n", result);

	// 2. lépés: ugyanúgy add() használata, de itt a standard bemenetről kérjük a bemenetet.
    int a, b;
    printf("Please enter the two numbers to add:");

	// scanf (szöveg, &változó1, &változó2, ...) - beolvasó utasítás.
	// A bekérendő formátum a szöveg, paraméterek pedig a beolvasott változók címe (&).
    scanf("%d %d", &a, &b);
    printf("Your result: %d\n", add(a, b));

	// 3. lépés: addFloat() - egész és valós szám összeadása. C tizedespontot használ.
    int c;
    double d;
    printf("Enter an int, then a float:");
    scanf("%d %lf", &c, &d);
    printf("Your result: %lf\n", addFloat(c, d));

	// 4. lépés: karakter típus használata.
	// Egy karakter megadható a konkrét betűvel (''), vagy pedig a helyettesítő kódjával.
	// A kettő kölcsönösen használható, vagyis az értéknövelés a kódot is növeli.
    char e = 'g';
    char f = 47;

	// Itt a-tól g-ig íratjuk ki a karaktereket, számláló ciklussal.
    char i = 'a';
    for (i; i < 'h'; i++) printf("Character: %c\n", i);

	// Itt pedig egy érdekes jelenséget látunk: ha a char-ból kivonjuk a '0' karaktert,
	// megkapjuk a szöveg szám reprezentációját.
	// A for ciklust int változóval iteráljuk végig, és működik :)
    i = '0';
    int j;
    for (j = i - '0'; j < '8' - '0'; j++) printf("Haraktyir: %d\n", j);

    // Példa tömb:
    int tomb[3] = {4, 5, 6};
    printf("%d", tomb[2]);

    return 0;
}
