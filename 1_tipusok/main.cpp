/** C++ kurzus - 1. program
*	Primitív típusok, pointer, felsorolt típus (enum)
*/

/* A C++ projekt ugyanúgy épül fel, mint a C-ben írt is.
*  Lényeges különbség, hogy a szintaktikára kicsit lazább szabályok vonatkoznak:
*  - használható ékezetes betû, kis- és nagybetûs változat különbözik
*  - két függvény akkor egyezik meg, ha szignatúrája (bekért változóinak listája) is
*  - az operátorok jelentése kicsit egyértelmûbb.
*/

// Include ugyanúgy történik, kivéve itt elég a fájl nevét kiterjesztés nélkül megadni.
// Pár rendszerkönyvtár: iostream, chrono
#include <iostream>

// Névtér: szintaktikai csoport, könyvtárféle, melyen belül definiálható metódus és állandó.
// A névtér rendszerint egy osztály: mindig ki kell tenni, hogy melyikben keressen az IDE.
// Ha using namespace-t használunk, akkor ezt elkerülhetjük.
// Alant az std::-bõl használunk részeket (cout, cin)
using namespace std;

int main()
{
    // Primitív típusok: C-ben megismertek, plusz:
	// bool: logikai változó George Boole után. Igaz / hamis értéket vesz fel.
	// Számmal is inicializálható: 0 - hamis, nem 0 - igaz.
	// stream: be- és kimenet olvasására-írására használható. Std része. (cin, cerr, cout)
	// Példa stringre (char*, char[]):
    char szoveg[6];
    szoveg[0] = 'a';
    szoveg[1] = 'l';
    szoveg[2] = 'm';
    szoveg[3] = 'a';
    szoveg[4] = 'f';
    szoveg[5] = 'a';
	// A tömb mérete fix, és azonos típusú elemeket tartalmazhat. Változtatni nem lehet rajta könnyen.
	// Elemeit [] operátorral érhetjük el.

    for (int i = 0; i < 6; i++) cout << szoveg[i];

	// Minden változónak van egy eleve elfoglalt helye a memóriában, ahogy az példányt kap (referencia).
	// Ezt egy 16-os rendszerben írt címmel érjük el, az & operátorral.
    cout << endl << "Address:" << &szoveg << endl;

	//==================================

	// Pointer: címre mutató típusos változó, ami nem kap kezdõértéket.
	// Segítségével könnyû a változóinkat helytakarékosan kezelni és megváltoztatni.
	// Egy mutató mutathat konkrét címre, vagy pedig sehova (nullpointer).
	// Szintaktikája: [típus]* [név];
	// Pointer esetén kétféle értéket érünk el:
	// - cím címképzõ operátorral: &ptr = 0x123abc;
	// - mutatott érték dereferáló operátorral: *ptr = 65;
	// A fenti két utasítás esetén int* pointerrel dolgoztunk.

	// Példa karakter típusú pointer használatára (ami a string is):
    char* text;

	// Mutatóval lehet helyet foglalni a memóriában.
	// new[] operátor: dinamikus tömböt definiál.
    text = new char[2];
    text[0] = 'e';
    text[1] = 'j';

	// Példa string nyújtására (2-rõl 3 méretû lesz):
	// - 1. létrehozunk egy ideiglenes tárolót
    char* temp;
    temp = new char[3];

	// - 2. átmásoljuk a meglévõ szöveget
    for (int i = 0; i < 2; i++) temp[i] = text[i];

	// - 3. plusz karaktereket beleírjuk
    temp[2] = 'h';

	// - 4. mivel az eredeti szöveg már nem kell, ezért annak helyét felszabadítjuk (más program használhassa)
	// delete[] operátor: felszabadítja a változóhoz rendelt memóriát.
    delete[] text;

	// - 5. eredeti szövegnek odaadjuk a dummy változó referenciáját
    text = temp;

	// - 6. a dummy változó pointerjét eltereljük, kinullázzuk
    temp = 0; //null pointer


	// Tömb esetén a pointer mindig a kezdetre mutat.
	// Ha +1-et adunk hozzá a pointerhez, a következõ foglalt elemre tudunk hivatkozni.
	// Ellentétes módon, -1-gyel elõrébb lépünk a memóriában.
    for (int i = 0; i < 3; i++) {
        cout << "Letter:" << *text << endl;
        text = text + 1;
    }

	// Struktúra: olyan szerkezetleírás, melynek neve van, továbbá lehetnek változói és függvényei (C-ben is van).
	// Miután példányosodott, függvényei és mezõi bárhonnan elérhetõk.
    struct Doboz{
        char* nev = "Kispista";
        int tomeg = 88;
        void kiir() {cout << "Nev: " << nev << endl << "Tomeg: " << tomeg << endl; }
    };

	// Létrehozunk két dobozt, az egyiket pointerrel. A nem mutatóst felparaméterezzük.
    Doboz d;
    Doboz* e;

	// . operátor: objektum tagelemei így érhetõk el
    d.kiir();

	// A második doboz mutatója az elsõre fog mutatni.
    e = &d;

	// Kiíratjuk a hivatkozott doboz tömegét.
	// -> operátor: pointer tagelemei így érhetõk el.
    cout << e->tomeg << endl;


	// Felsorolt típus - enumeráció - állapotgép: állapotokat tartalmazó leírás. Számmal is helyettesíthetõ.
	// Ha nem adunk értéket az állapotnak, mindig 1-gyel többet kap, mint az elõzõ.
    enum Hitetlen {
        megtert = 2,
        eretnek
    };

	// Enum is példányosodik
    Hitetlen h;

    h = eretnek;

	// Állapotgépnek az állapotát kiértékelhetjük, és más viselkedést kölcsönözhetünk egy programnak.
	// Tipikusan menüpontok közti navigációt, vagy játékosok körének figyelését enummal szokás megoldani.
    switch (h) {
    case megtert:
        cout << "I'm the zealot of oath" << endl;
        break;
    case eretnek:
        cout << "I deny my religion" << endl;
        break;
    }

    return 0;
}
