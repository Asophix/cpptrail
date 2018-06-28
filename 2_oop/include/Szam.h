#ifndef SZAM_H
#define SZAM_H

#include <iostream>
using namespace std;

//Szam oszt�ly.
//Eg�sz sz�m t�rol�s�ra �s alapm�veleteire k�pes objektum.

class Szam
{
    //Protected kulcssz�val el�rhet�v� tessz�k a bels� v�ltoz�t a konkr�tabb sz�moknak.
    //C++ priv�t szembemegy az UML priv�ttal! (UML-ben gyerek el�ri a priv�t v�ltoz�t is)
    protected:
        double re = 0;

    public:
        Szam() {}

        Szam(double re) {
            this->re = re;
        }

        //Amikor �ltal�nos t�pust adunk meg, figyelni kell arra, hogy a gyerek t�pus
        //is fel legyen k�sz�tve:
        //N�h�ny alapeset:
        // - rendelkezzen l�that� f�ggv�nnyel �s v�ltoz�val
        // - k�pes legyen megfelel� oper�torok haszn�lat�ra
        // - esetleges const objektum kezel�se legyen megoldva
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
