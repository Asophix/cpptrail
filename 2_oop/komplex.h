#ifndef KOMPLEX_H_INCLUDED
#define KOMPLEX_H_INCLUDED

using namespace std;

//Komplex oszt�ly.
//�nmag�ban is komplex sz�mot t�rol� oszt�ly, nem OOP-elven megval�s�tott objektum.
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
