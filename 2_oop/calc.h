#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include <iostream>
#include "Szam.h";
using namespace std;

//Calc oszt�ly.
//Kezdetleges sz�mol�g�p, mely a mem�ri�ban t�rolt sz�mmal v�gez m�veletet.
//Mivel a sz�m t�pus�nak megfelel� f�ggv�nyeket h�vja, ez�rt csomagol� (wrapper)
//oszt�lynak is nevezhetj�k.

class Calc {
    private:
        Szam memory;

    public:
    Calc(Szam memory) {
        this->memory = memory;
    }

    //A t�rolt sz�m t�pus�nak megfelel� .add() f�ggv�ny h�v�dik!
    Szam add(Szam rhs) {
        memory = memory.add(rhs);
        return memory;
    }

    Szam subtract(Szam rhs) {
        memory = memory.subtract(rhs);
        return memory;
    }

    //Getter f�ggv�ny: bels� priv�t v�ltoz� �rt�k�t adja vissza.
    Szam getMemory() {
        return memory;
    }

    //(F�l) setter f�ggv�ny: bels� priv�t v�ltoz� �rt�k�t �ll�tja be.
    void clear() {
        memory = 0;
    }

};

#endif // CALC_H_INCLUDED
