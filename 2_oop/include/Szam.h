#ifndef SZAM_H
#define SZAM_H

#include <iostream>
using namespace std;

//Szam osztály.
//Egész szám tárolására és alapmûveleteire képes objektum.

class Szam
{
    //Protected kulcsszóval elérhetõvé tesszük a belsõ változót a konkrétabb számoknak.
    //C++ privát szembemegy az UML priváttal! (UML-ben gyerek eléri a privát változót is)
    protected:
        double re = 0;

    public:
        Szam() {}

        Szam(double re) {
            this->re = re;
        }

        //Amikor általános típust adunk meg, figyelni kell arra, hogy a gyerek típus
        //is fel legyen készítve:
        //Néhány alapeset:
        // - rendelkezzen látható függvénnyel és változóval
        // - képes legyen megfelelõ operátorok használatára
        // - esetleges const objektum kezelése legyen megoldva
        Szam add(Szam rhs) {
            Szam result;
            result = this->re + rhs.re;
            return result;
        }

        Szam subtract(Szam rhs) {
            Szam result;
            result = this->re - rhs.re;
            return result;
        }

        void write() {
            cout << this->re << endl;
        }
};

#endif // SZAM_H
