
#ifndef __CHRONO__
#define __CHRONO__

#include "../std_lib_facilities.h"
#include <istream>

namespace Chrono {
    enum class Month {
        Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec,
    };

    class Date {

    private:
        long days;

    public:
        class Invalid { };

        Date(unsigned y, Month m, unsigned d);
        Date();

        unsigned  year()  const;
        Month  month() const;
        unsigned  date()  const;

        void add_day(unsigned n);
        void add_month(unsigned n);
        void add_year(unsigned n);

    };

    long monthToDate(Month m, bool is_leap_year);
    long yearToDate(unsigned y);

    Month dateToMonth(long date, bool is_leap_year);
    unsigned dateToYear(long date);
    bool is_leap_year(unsigned y);
    bool is_valid(unsigned y, Month m, unsigned d);

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    ostream& operator<<(ostream& os, Month m);
    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);

}


#endif