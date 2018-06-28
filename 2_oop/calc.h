#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include <iostream>
#include "Szam.h";
using namespace std;

//Calc osztály.
//Kezdetleges számológép, mely a memóriában tárolt számmal végez mûveletet.
//Mivel a szám típusának megfelelõ függvényeket hívja, ezért csomagoló (wrapper)
//osztálynak is nevezhetjük.

class Calc {
    private:
        Szam memory;

    public:
    Calc(Szam memory) {
        this->memory = memory;
    }

    //A tárolt szám típusának megfelelõ .add() függvény hívódik!
    Szam add(Szam rhs) {
        memory = memory.add(rhs);
        return memory;
    }

    Szam subtract(Szam rhs) {
        memory = memory.subtract(rhs);
        return memory;
    }

    //Getter függvény: belsõ privát változó értékét adja vissza.
    Szam getMemory() {
        return memory;
    }

    //(Fél) setter függvény: belsõ privát változó értékét állítja be.
    void clear() {
        memory = 0;
    }

};

#endif // CALC_H_INCLUDED
