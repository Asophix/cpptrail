#ifndef KOMPLEX2_H_INCLUDED
#define KOMPLEX2_H_INCLUDED

#include <math.h>
#include "Szam.h"

using namespace std;

//Komplex2 osztály.
//Szam típusból örököl, képes két komplex számon alapmûveleteket végezni.

class Komplex2 : public Szam {
    //A komplex szám valós részét nem soroltuk fel.
    //Mivel a valós rész az alaposztályban létrejön, ezért itt csak a
    //képzetes rész tárolását kell megoldani.
    private:
        int im = 0;

    public:

    //Üres paraméter nélküli konstruktor. Megtehetnénk, hogy az im-et
    //itt is 0-ra állítjuk, de már adtunk neki alapértelmezett értéket.
    Komplex2() {}


    Komplex2(double re, int im) {
        this->re = re;
        this->im = im;
    }

    Komplex2 add(Komplex2 rhs) {
        Komplex2 result;
        result.re = this->re + rhs.re;
        result.im = this->im + rhs.im;
        return result;
    }

    Komplex2 subtract(Komplex2 rhs) {
        Komplex2 result;
        result.re = this->re - rhs.re;
        result.im = this->im - rhs.im;
        return result;
    }

    //Egyedi kiírató függvény. A plusz jelet nem érdemes mínuszhoz is kiírni...
    void write() {
        cout << this->re << "+" << this->im << "i" << endl;
    }

    //Visszaadja a vektorként is felfogható komplex szám pithagoraszi hosszát.
    double length() {
        return sqrt(pow(this->re, 2) + pow(this->im, 2));
    }

    //Destruktor, ami 0-ra állít mindent.
    ~Komplex2() {
        this->re = 0.0;
        this->im = 0;
    }


};

#endif // KOMPLEX2_H_INCLUDED
