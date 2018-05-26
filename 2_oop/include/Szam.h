#ifndef SZAM_H
#define SZAM_H

#include <iostream>
using namespace std;

class Szam
{
    protected:
        double re = 0;

    public:
        Szam() {}

        Szam(double re) {
            this->re = re;
        }

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
