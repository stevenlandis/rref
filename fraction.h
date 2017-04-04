#ifndef FRACTION_H
#define FRACTION_H

#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;

class Fraction {
private:
    int num;
    int den;
public:
    void reduce() {
        int max = min(abs(num), abs(den));
        for (int i = max; i >= 2; i--) {
            while (num%i==0 && den%i==0) {
                num/=i;
                den/=i;
            }
        }
        if (num == 0) {
            den = 1;
        }
    }
    Fraction() {
        if (den == 0) {
            cout << "Invalid fraction!!\n";
        }
        num = 0;
        den = 0;
    }
    Fraction(int a, int b) {
        if (b < 0) {
            a *= -1;
            b *= -1;
        }
        num = a;
        den = b;
        reduce();
    }
    void disp() {
        cout << "(" << num << "/" << den << ")";
    }
    Fraction add(Fraction f) {
        int n = f.den * num + f.num * den;
        int d = den * f.den;
        Fraction rtn = Fraction(n,d);
        return rtn;
    }
    Fraction sub(Fraction f) {
        int n = f.den * num - f.num * den;
        int d = den * f.den;
        Fraction rtn = Fraction(n,d);
        return rtn;
    }
    Fraction mul(Fraction f) {
        Fraction rtn = Fraction(f.num * num, f.den * den);
        return rtn;
    }
    Fraction div(Fraction f) {
        Fraction rtn = Fraction(num * f.den, den * f.num);
        return rtn;
    }
    void increment(Fraction f) {
        num = f.den * num + f.num * den;
        den = den * f.den;
        reduce();
    }
    void decrement(Fraction f) {
        num = f.den * num - f.num * den;
        den = den * f.den;
        reduce();
    }
    Fraction scale(Fraction f) {
        num = f.num * num;
        den = f.den * den;
        reduce();
        return *this;
    }
    void zero() {
        num = 0;
        den = 1;
    }
    bool isZero() {
        return (num == 0);
    }
    Fraction inverse() {
        return Fraction(den, num);
    }
    friend bool operator==(Fraction,Fraction);
    friend ostream &operator<<(ostream&,Fraction);
};
ostream &operator<<(ostream &os, Fraction f) {
    return os << "(" << f.num << "/" << f.den << ")";
}
Fraction operator+(Fraction a, Fraction b) {
    return a.add(b);
}
Fraction operator+(int i, Fraction f) {
    return Fraction(i,1).add(f);
}
Fraction operator+(Fraction f, int i) {
    return Fraction(i,1).add(f);
}
Fraction operator-(Fraction a, Fraction b) {
    return a.sub(b);
}
Fraction operator-(int i, Fraction f) {
    return Fraction(i,1).sub(f);
}
Fraction operator-(Fraction f, int i) {
    return f.sub(Fraction(i,1));
}
Fraction operator*(Fraction a, Fraction b) {
    return a.mul(b);
}
Fraction operator*(int i, Fraction f) {
    return f.mul(Fraction(i,1));
}
Fraction operator*(Fraction f, int i) {
    return i*f;
}
Fraction operator/(Fraction a, Fraction b) {
    return a.div(b);
}
Fraction operator/(int i, Fraction f) {
    return Fraction(i,1).div(f);
}
Fraction operator/(Fraction f, int i) {
    return f.div(Fraction(i,1));
}
void operator+=(Fraction &a, Fraction b) {
    a.increment(b);
}
void operator-=(Fraction a, Fraction b) {
    a.decrement(b);
}
void operator*=(Fraction a, Fraction b) {
    a.scale(b);
}
bool operator==(Fraction a, Fraction b) {
    return a.num == b.num && a.den == b.den;
}
bool operator!=(Fraction a, Fraction b) {
    return !(a==b);
}

#endif
