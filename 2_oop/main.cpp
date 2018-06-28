/** C++ kurzus - 2. program
*	Objektumorientált programozás alapjai:
*   osztályok, láthatóság, öröklés, polimorfizmus, függvénytúlterhelés
*/

/* Az OOP-elv alapja az egymással kommunikáló és kapcsolódó osztályok, objektumok.
*  Az osztály egy objektumleírás, melyeket - változók formájában - példányosíthatunk.
*  Egy ugyanazon osztályból akárhány példány létezhet, melyek a memóriában is létrejönnek.
*  A C++ osztály kölcsönöz láthatóságot a tagelemeunek, amivel hozzáférést szabályozhatunk.
*  A függvények és tagelemek öröklési viszonytól függõen lemásolódnak, illetve más értelmet nyernek.
*/

#include <iostream>
// Szervezõ elvként érdemes minden osztálynak egy külön leíró fájlt fenntartani.
#include "komplex.h"
#include "komplex2.h"
#include "Szam.h"
#include "calc.h"

using namespace std;

int main()
{
    //Osztály: struktúra, amelyben a függvényeknek és mezõknek van láthatósága:
    // - private: osztály törzsén belülrõl érhetõ el
    // - protected: leszármazottakból is elérhetõ
    // - public: bárhonnan elérhetõ

    //Az osztályra, amikor belülrõl hivatkozzuk meg saját magát,
    //a this referenciával tehetjük meg. Ilyenkor -> operátort használunk.

    /*Az egyes osztályokban a lényeges részeknél találhatók kommentárok.
    */

    //Az osztályra mindig nevével hivatkozunk. Példa:
    //Komplex - osztálynév (típus)
    //a, b - példány neve
    Komplex a, b;
    Komplex2 c(3.0, -4), d(4.5, 2);
    Szam n(12.5), o(-3.0);

    a.re = 1.4;
    a.im = 2;

    b.re = 6.0;
    b.im = -4;

    //1. példa: két Komplex osztály
    //Függvények visszatérési értékén is hívhatók függvények!
    (a.add(b)).write();
    (a.subtract(b)).write();
    a.write();

    //2. példa: két Komplex2 osztály
    (c.add(d)).write();
    (c.subtract(d)).write();
    c.write();
    cout << c.length() << endl;

    //3. példa: két Szam osztály.
    (o.add(n)).write();
    (o.subtract(n)).write();
    o.write();

    //4. példa: Szam-hoz adunk Komplex2-t, majd kiíratjuk...
    //Mivel Komplex2 egyúttal Szam is, ezért ez végrehajtható.
    n.add(c).write();

    //5. példa: Calc egy Szam típust tárol el a memóriában
    //Itt egy új Komplex példányt adtunk át, ami a konstruktorban él;
    //viszont mivel eltároljuk belsõleg, ezért utána is!
    Calc szamgep(Komplex2(5.0, -2));

    //Calc képes Szam típussal dolgozni. Végezhetõk rajta a mûveletek
    //az alaposztállyal és a leszármazottaival is!
    szamgep.add(20).write();
    szamgep.add(Komplex2(4.0, -3)).write();
    szamgep.subtract(Komplex2(12.4, 8)).write();
    szamgep.getMemory().write();

    szamgep.clear();
    szamgep.getMemory().write();



    return 0;
}
