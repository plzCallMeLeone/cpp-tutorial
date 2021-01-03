#include "Chrono.hpp"
using namespace Chrono;
int main()
{
    try {
        cout << Date{2020, Month::Dec, 31};
        cout << Date{1970, Month::Dec, 30};
    }
    catch (Chrono::Date::Invalid) {
        cerr << "Invalid Date Error!\n";
    }
    return 0;
}