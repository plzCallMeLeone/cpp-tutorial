
#include "Rational.hpp"

Rational::Rational(int n, int d)
    :num(abs(n)),
     denom(abs(d)),
     is_minus (n>>31 ^ d >>31) 
{
    if(!d) { throw DivideByZero{ }; }
}
Rational::Rational(unsigned n, unsigned d)
    :num{n},
     denom{d},
     is_minus{false}
{
    if(!d) { throw DivideByZero{ }; }
}
Rational::Rational(unsigned n, unsigned d, bool sign)
    :num{n},
     denom{d},
     is_minus{sign}
{
    if(!d) { throw DivideByZero{ }; }
}


Rational operator+(const Rational& a, const Rational& b)
{
    unsigned denom = lcm(a.denominator(),b.denominator());

    unsigned a_numinator = a.numinator()*denom/a.denominator();
    unsigned b_numinator = b.numinator()*denom/b.denominator();

    if ( a.minus() == b.minus() ) { return Rational{a_numinator+b_numinator, denom, a.minus()}; }

    bool sign = a_numinator > b_numinator ? a.minus():b.minus();
    return Rational{max(a_numinator, b_numinator) - min(a_numinator, b_numinator), denom, sign};
}

ostream& operator<<(ostream&os, const Rational& r)
{
    if (!r.numinator()) { return os << "0"; }
    return os << (r.minus()? "-":"")
              << r.numinator() << '/' 
              << r.denominator();
}

unsigned gcd(unsigned a, unsigned b)
{
    while(a%b) {
        unsigned tmp = a;
        a = tmp/b;
        b = tmp%b;
    }
    return b;
}

unsigned lcm(unsigned a, unsigned b)
{
    return a*b / gcd (a, b);
}

double RationalToDouble(const Rational& r)
{
    return double(r.numinator()) / double(r.denominator());
}
Rational operator-(const Rational& a, const Rational& b)
{
    return a + (-b);
    
}
Rational operator-(const Rational& a)
{
    return Rational{a.numinator(), a.denominator(), !a.minus()};
}
Rational operator*(const Rational& a, const Rational& b)
{
    return Rational {a.numinator()*b.numinator(), a.denominator()*b.denominator(), a.minus() != b.minus()};
}
Rational reciprocal(const Rational& r)
{
    if (!r.numinator()) { throw Rational::DivideByZero{ }; }
    return Rational {r.denominator(), r.numinator(), r.minus()};
}
Rational operator/ (const Rational& a, const Rational& b)
{
    return a * reciprocal(b);
}