#ifndef KOMPLEX2_H_INCLUDED
#define KOMPLEX2_H_INCLUDED

#include <math.h>
#include "Szam.h"

using namespace std;

class Komplex2 : public Szam {
    private:
        int im = 0;

    public:

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

    void write() {
        cout << this->re << "+" << this->im << "i" << endl;
    }

    double length() {
        return sqrt(pow(this->re, 2) + pow(this->im, 2));
    }

    ~Komplex2() {
        this->re = 0.0;
        this->im = 0;
    }


};

#endif // KOMPLEX2_H_INCLUDED
