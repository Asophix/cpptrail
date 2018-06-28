/** C++ kurzus - 2. program
*	Objektumorient�lt programoz�s alapjai:
*   oszt�lyok, l�that�s�g, �r�kl�s, polimorfizmus, f�ggv�nyt�lterhel�s
*/

/* Az OOP-elv alapja az egym�ssal kommunik�l� �s kapcsol�d� oszt�lyok, objektumok.
*  Az oszt�ly egy objektumle�r�s, melyeket - v�ltoz�k form�j�ban - p�ld�nyos�thatunk.
*  Egy ugyanazon oszt�lyb�l ak�rh�ny p�ld�ny l�tezhet, melyek a mem�ri�ban is l�trej�nnek.
*  A C++ oszt�ly k�lcs�n�z l�that�s�got a tagelemeunek, amivel hozz�f�r�st szab�lyozhatunk.
*  A f�ggv�nyek �s tagelemek �r�kl�si viszonyt�l f�gg�en lem�sol�dnak, illetve m�s �rtelmet nyernek.
*/

#include <iostream>
// Szervez� elvk�nt �rdemes minden oszt�lynak egy k�l�n le�r� f�jlt fenntartani.
#include "komplex.h"
#include "komplex2.h"
#include "Szam.h"
#include "calc.h"

using namespace std;

int main()
{
    //Oszt�ly: strukt�ra, amelyben a f�ggv�nyeknek �s mez�knek van l�that�s�ga:
    // - private: oszt�ly t�rzs�n bel�lr�l �rhet� el
    // - protected: lesz�rmazottakb�l is el�rhet�
    // - public: b�rhonnan el�rhet�

    //Az oszt�lyra, amikor bel�lr�l hivatkozzuk meg saj�t mag�t,
    //a this referenci�val tehetj�k meg. Ilyenkor -> oper�tort haszn�lunk.

    /*Az egyes oszt�lyokban a l�nyeges r�szekn�l tal�lhat�k komment�rok.
    */

    //Az oszt�lyra mindig nev�vel hivatkozunk. P�lda:
    //Komplex - oszt�lyn�v (t�pus)
    //a, b - p�ld�ny neve
    Komplex a, b;
    Komplex2 c(3.0, -4), d(4.5, 2);
    Szam n(12.5), o(-3.0);

    a.re = 1.4;
    a.im = 2;

    b.re = 6.0;
    b.im = -4;

    //1. p�lda: k�t Komplex oszt�ly
    //F�ggv�nyek visszat�r�si �rt�k�n is h�vhat�k f�ggv�nyek!
    (a.add(b)).write();
    (a.subtract(b)).write();
    a.write();

    //2. p�lda: k�t Komplex2 oszt�ly
    (c.add(d)).write();
    (c.subtract(d)).write();
    c.write();
    cout << c.length() << endl;

    //3. p�lda: k�t Szam oszt�ly.
    (o.add(n)).write();
    (o.subtract(n)).write();
    o.write();

    //4. p�lda: Szam-hoz adunk Komplex2-t, majd ki�ratjuk...
    //Mivel Komplex2 egy�ttal Szam is, ez�rt ez v�grehajthat�.
    n.add(c).write();

    //5. p�lda: Calc egy Szam t�pust t�rol el a mem�ri�ban
    //Itt egy �j Komplex p�ld�nyt adtunk �t, ami a konstruktorban �l;
    //viszont mivel elt�roljuk bels�leg, ez�rt ut�na is!
    Calc szamgep(Komplex2(5.0, -2));

    //Calc k�pes Szam t�pussal dolgozni. V�gezhet�k rajta a m�veletek
    //az alaposzt�llyal �s a lesz�rmazottaival is!
    szamgep.add(20).write();
    szamgep.add(Komplex2(4.0, -3)).write();
    szamgep.subtract(Komplex2(12.4, 8)).write();
    szamgep.getMemory().write();

    szamgep.clear();
    szamgep.getMemory().write();



    return 0;
}
