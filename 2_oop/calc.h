#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include <iostream>
#include "Szam.h";
using namespace std;

class Calc {
    private:
        Szam memory;

    public:
    Calc(Szam memory) {
        this->memory = memory;
    }

    Szam add(Szam rhs) {
        memory = memory.add(rhs);
        return memory;
    }

    Szam subtract(Szam rhs) {
        memory = memory.subtract(rhs);
        return memory;
    }

    Szam getMemory() {
        return memory;
    }

    void clear() {
        memory = 0;
    }

};

#endif // CALC_H_INCLUDED
