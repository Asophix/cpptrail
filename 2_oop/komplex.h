#ifndef KOMPLEX_H_INCLUDED
#define KOMPLEX_H_INCLUDED

using namespace std;

//Komplex osztály.
//Önmagában is komplex számot tároló osztály, nem OOP-elven megvalósított objektum.
struct Komplex {
    double re = 0;
    int im = 0;

    Komplex add(Komplex rhs) {
        Komplex result;
        result.re = this->re + rhs.re;
        result.im = this->im + rhs.im;
        return result;
    }

    Komplex subtract(Komplex rhs) {
        Komplex result;
        result.re = this->re - rhs.re;
        result.im = this->im - rhs.im;
        return result;
    }

    void write() {
        cout << this->re << "+" << this->im << "i" << endl;
    }
};

#endif // KOMPLEX_H_INCLUDED
