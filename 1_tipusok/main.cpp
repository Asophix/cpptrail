/** C++ kurzus - 1. program
*	Primit�v t�pusok, pointer, felsorolt t�pus (enum)
*/

/* A C++ projekt ugyan�gy �p�l fel, mint a C-ben �rt is.
*  L�nyeges k�l�nbs�g, hogy a szintaktik�ra kicsit laz�bb szab�lyok vonatkoznak:
*  - haszn�lhat� �kezetes bet�, kis- �s nagybet�s v�ltozat k�l�nb�zik
*  - k�t f�ggv�ny akkor egyezik meg, ha szignat�r�ja (bek�rt v�ltoz�inak list�ja) is
*  - az oper�torok jelent�se kicsit egy�rtelm�bb.
*/

// Include ugyan�gy t�rt�nik, kiv�ve itt el�g a f�jl nev�t kiterjeszt�s n�lk�l megadni.
// P�r rendszerk�nyvt�r: iostream, chrono
#include <iostream>

// N�vt�r: szintaktikai csoport, k�nyvt�rf�le, melyen bel�l defini�lhat� met�dus �s �lland�.
// A n�vt�r rendszerint egy oszt�ly: mindig ki kell tenni, hogy melyikben keressen az IDE.
// Ha using namespace-t haszn�lunk, akkor ezt elker�lhetj�k.
// Alant az std::-b�l haszn�lunk r�szeket (cout, cin)
using namespace std;

int main()
{
    // Primit�v t�pusok: C-ben megismertek, plusz:
	// bool: logikai v�ltoz� George Boole ut�n. Igaz / hamis �rt�ket vesz fel.
	// Sz�mmal is inicializ�lhat�: 0 - hamis, nem 0 - igaz.
	// stream: be- �s kimenet olvas�s�ra-�r�s�ra haszn�lhat�. Std r�sze. (cin, cerr, cout)
	// P�lda stringre (char*, char[]):
    char szoveg[6];
    szoveg[0] = 'a';
    szoveg[1] = 'l';
    szoveg[2] = 'm';
    szoveg[3] = 'a';
    szoveg[4] = 'f';
    szoveg[5] = 'a';
	// A t�mb m�rete fix, �s azonos t�pus� elemeket tartalmazhat. V�ltoztatni nem lehet rajta k�nnyen.
	// Elemeit [] oper�torral �rhetj�k el.

    for (int i = 0; i < 6; i++) cout << szoveg[i];

	// Minden v�ltoz�nak van egy eleve elfoglalt helye a mem�ri�ban, ahogy az p�ld�nyt kap (referencia).
	// Ezt egy 16-os rendszerben �rt c�mmel �rj�k el, az & oper�torral.
    cout << endl << "Address:" << &szoveg << endl;

	//==================================

	// Pointer: c�mre mutat� t�pusos v�ltoz�, ami nem kap kezd��rt�ket.
	// Seg�ts�g�vel k�nny� a v�ltoz�inkat helytakar�kosan kezelni �s megv�ltoztatni.
	// Egy mutat� mutathat konkr�t c�mre, vagy pedig sehova (nullpointer).
	// Szintaktik�ja: [t�pus]* [n�v];
	// Pointer eset�n k�tf�le �rt�ket �r�nk el:
	// - c�m c�mk�pz� oper�torral: &ptr = 0x123abc;
	// - mutatott �rt�k derefer�l� oper�torral: *ptr = 65;
	// A fenti k�t utas�t�s eset�n int* pointerrel dolgoztunk.

	// P�lda karakter t�pus� pointer haszn�lat�ra (ami a string is):
    char* text;

	// Mutat�val lehet helyet foglalni a mem�ri�ban.
	// new[] oper�tor: dinamikus t�mb�t defini�l.
    text = new char[2];
    text[0] = 'e';
    text[1] = 'j';

	// P�lda string ny�jt�s�ra (2-r�l 3 m�ret� lesz):
	// - 1. l�trehozunk egy ideiglenes t�rol�t
    char* temp;
    temp = new char[3];

	// - 2. �tm�soljuk a megl�v� sz�veget
    for (int i = 0; i < 2; i++) temp[i] = text[i];

	// - 3. plusz karaktereket bele�rjuk
    temp[2] = 'h';

	// - 4. mivel az eredeti sz�veg m�r nem kell, ez�rt annak hely�t felszabad�tjuk (m�s program haszn�lhassa)
	// delete[] oper�tor: felszabad�tja a v�ltoz�hoz rendelt mem�ri�t.
    delete[] text;

	// - 5. eredeti sz�vegnek odaadjuk a dummy v�ltoz� referenci�j�t
    text = temp;

	// - 6. a dummy v�ltoz� pointerj�t elterelj�k, kinull�zzuk
    temp = 0; //null pointer


	// T�mb eset�n a pointer mindig a kezdetre mutat.
	// Ha +1-et adunk hozz� a pointerhez, a k�vetkez� foglalt elemre tudunk hivatkozni.
	// Ellent�tes m�don, -1-gyel el�r�bb l�p�nk a mem�ri�ban.
    for (int i = 0; i < 3; i++) {
        cout << "Letter:" << *text << endl;
        text = text + 1;
    }

	// Strukt�ra: olyan szerkezetle�r�s, melynek neve van, tov�bb� lehetnek v�ltoz�i �s f�ggv�nyei (C-ben is van).
	// Miut�n p�ld�nyosodott, f�ggv�nyei �s mez�i b�rhonnan el�rhet�k.
    struct Doboz{
        char* nev = "Kispista";
        int tomeg = 88;
        void kiir() {cout << "Nev: " << nev << endl << "Tomeg: " << tomeg << endl; }
    };

	// L�trehozunk k�t dobozt, az egyiket pointerrel. A nem mutat�st felparam�terezz�k.
    Doboz d;
    Doboz* e;

	// . oper�tor: objektum tagelemei �gy �rhet�k el
    d.kiir();

	// A m�sodik doboz mutat�ja az els�re fog mutatni.
    e = &d;

	// Ki�ratjuk a hivatkozott doboz t�meg�t.
	// -> oper�tor: pointer tagelemei �gy �rhet�k el.
    cout << e->tomeg << endl;


	// Felsorolt t�pus - enumer�ci� - �llapotg�p: �llapotokat tartalmaz� le�r�s. Sz�mmal is helyettes�thet�.
	// Ha nem adunk �rt�ket az �llapotnak, mindig 1-gyel t�bbet kap, mint az el�z�.
    enum Hitetlen {
        megtert = 2,
        eretnek
    };

	// Enum is p�ld�nyosodik
    Hitetlen h;

    h = eretnek;

	// �llapotg�pnek az �llapot�t ki�rt�kelhetj�k, �s m�s viselked�st k�lcs�n�zhet�nk egy programnak.
	// Tipikusan men�pontok k�zti navig�ci�t, vagy j�t�kosok k�r�nek figyel�s�t enummal szok�s megoldani.
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
