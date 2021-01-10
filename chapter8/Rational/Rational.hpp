#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__
#include "../../std_lib_facilities.h"
#include <cmath>

class Rational {
private:
    unsigned num;
    unsigned denom;
    bool is_minus;
public:
    Rational(): num{1}, denom{1}, is_minus{false} { };
    Rational(int n, int d);
    Rational(int n): num (abs(n)), denom{1}, is_minus(n>>31) { };
    Rational(unsigned n): num{n}, denom{1} { };
    Rational(unsigned n, unsigned d);
    Rational(unsigned n, unsigned d, bool sign);

    unsigned numinator() const { return num; }
    unsigned denominator() const { return denom; }
    bool     minus() const { return is_minus; }

    class DivideByZero { };
};
Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator-(const Rational& a);

Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);

ostream& operator<<(ostream&os, const Rational& r);
Rational reciprocal(const Rational& r);

unsigned gcd(unsigned a, unsigned b);
unsigned lcm(unsigned a, unsigned b);
#endif