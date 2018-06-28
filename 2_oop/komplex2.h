#ifndef KOMPLEX2_H_INCLUDED
#define KOMPLEX2_H_INCLUDED

#include <math.h>
#include "Szam.h"

using namespace std;

//Komplex2 oszt�ly.
//Szam t�pusb�l �r�k�l, k�pes k�t komplex sz�mon alapm�veleteket v�gezni.

class Komplex2 : public Szam {
    //A komplex sz�m val�s r�sz�t nem soroltuk fel.
    //Mivel a val�s r�sz az alaposzt�lyban l�trej�n, ez�rt itt csak a
    //k�pzetes r�sz t�rol�s�t kell megoldani.
    private:
        int im = 0;

    public:

    //�res param�ter n�lk�li konstruktor. Megtehetn�nk, hogy az im-et
    //itt is 0-ra �ll�tjuk, de m�r adtunk neki alap�rtelmezett �rt�ket.
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

    //Egyedi ki�rat� f�ggv�ny. A plusz jelet nem �rdemes m�nuszhoz is ki�rni...
    void write() {
        cout << this->re << "+" << this->im << "i" << endl;
    }

    //Visszaadja a vektork�nt is felfoghat� komplex sz�m pithagoraszi hossz�t.
    double length() {
        return sqrt(pow(this->re, 2) + pow(this->im, 2));
    }

    //Destruktor, ami 0-ra �ll�t mindent.
    ~Komplex2() {
        this->re = 0.0;
        this->im = 0;
    }


};

#endif // KOMPLEX2_H_INCLUDED
