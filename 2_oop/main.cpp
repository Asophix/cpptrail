#include <iostream>
#include "komplex.h"
#include "komplex2.h"
#include "Szam.h"
#include "calc.h"

using namespace std;

int main()
{
    Komplex a, b;
    Komplex2 c(3.0, -4), d(4.5, 2);
    Szam n(12.5), o(-3.0);

    a.re = 1.4;
    a.im = 2;

    b.re = 6.0;
    b.im = -4;

    (a.add(b)).write();
    (a.subtract(b)).write();
    a.write();

    (c.add(d)).write();
    (c.subtract(d)).write();
    c.write();
    cout << c.length() << endl;

    (o.add(n)).write();
    (o.subtract(n)).write();
    o.write();

    n.add(c).write();

    Calc szamgep(Komplex2(5.0, -2));

    szamgep.add(20).write();
    szamgep.add(Komplex2(4.0, -3)).write();
    szamgep.subtract(Komplex2(12.4, 8)).write();
    szamgep.getMemory().write();

    szamgep.clear();
    szamgep.getMemory().write();



    return 0;
}
