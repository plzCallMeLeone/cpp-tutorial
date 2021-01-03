#include "Rational.hpp"
int main()
{
    try {
        cout << Rational{4, -4} * Rational {-4, 4}<<'\n';
        cout << Rational{3, 4}<<'\n';
        cout << 1 / Rational{0,1} << '\n';
        cout << -1 / -Rational {-3, 4} << '\n';
    }
    catch(Rational::DivideByZero) {
        cerr << "Divide by Zero!!\n";
    }
    catch(...){
        cerr << "Unexpected Error!!\n";
    }
}
