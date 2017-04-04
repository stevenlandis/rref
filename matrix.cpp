#include<iostream>
#include"fraction.h"
#include"matrix.h"
using namespace std;

int main() {
    /*
    Fraction base[18] = {
        Fraction(2,1),
        Fraction(1,1),
        Fraction(-2,1),

        Fraction(1,1),
        Fraction(0,1),
        Fraction(0,1),

        Fraction(0,1),
        Fraction(1,1),
        Fraction(1,1),

        Fraction(0,1),
        Fraction(1,1),
        Fraction(0,1),

        Fraction(3,1),
        Fraction(5,1),
        Fraction(-3,1),

        Fraction(0,1),
        Fraction(0,1),
        Fraction(1,1)
    };
    Matrix a = Matrix(3,6, base);
    a.disp();
    a.rref();
    a.disp();
    */
    Fraction a = Fraction(1,3);
    cout << a << endl;
    cout << a+5 << endl;
    cout << 5+a << endl;
    return 0;
}
