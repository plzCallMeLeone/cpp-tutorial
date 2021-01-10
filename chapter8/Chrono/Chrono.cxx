#include "Chrono.hpp"


namespace Chrono {

    constexpr unsigned month_date[12] =      {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    constexpr unsigned month_date_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 


    unsigned Date::year() const {
        return dateToYear(days);
    }
    Month Date::month() const {
        unsigned date = days;
        for(unsigned cnt = 1970; date >= 365 + is_leap_year(cnt);
             date -= 365 + is_leap_year(cnt),++cnt) { }

        return dateToMonth(date, is_leap_year(this->year()));
    }
    unsigned Date::date() const {
        unsigned date = days;
        for(unsigned cnt = 1970; date >= 365 + is_leap_year(cnt);
             date -= 365 + is_leap_year(cnt),++cnt) { }
        
        if (!is_leap_year(this->year())) {
            for(unsigned cnt = 0;date >= month_date[cnt];  date-=month_date[cnt], ++cnt) { }
        }
        else {
            for(unsigned cnt = 0;date >= month_date_leap[cnt];  date-=month_date_leap[cnt], ++cnt) { }
        }
        return date + 1;
    }

    Date::Date(unsigned yy, Month mm, unsigned dd) 
    {
        days = monthToDate(mm, is_leap_year(yy)) + yearToDate(yy) + dd - 1;
    }

    Date::Date() :days{0} { }

    bool is_valid(unsigned y, Month m, unsigned d)
    {
        if (!(unsigned(m) - 1 <= 11)) { return false; }
        if (is_leap_year(y))          { return d - 1 <= (month_date_leap[unsigned(m) - 1] - 1); } 
        return d - 1 <= month_date[unsigned(m) - 1] - 1;
    }

    bool is_leap_year(unsigned y)
    { 
        return (y%4 == 0) && ((y%400 == 0)||(y%100 != 0)); 
    }

    bool operator==(const Date& a, const Date& b)
    {
        return (a.date()  == b.date()) 
            && (a.month() == b.month())
            && (a.year()  == b.year());
    }
    bool operator!=(const Date& a, const Date& b)
    {
        return !(a==b);
    }

    ostream& operator<<(ostream& os, Month m)
    {
        os << int(m);
        return os;
    }
    ostream& operator<<(ostream& os, const Date& d)
    {
        os << "(" << d.year() << ',' << d.month() << ',' << d.date() << ")\n";
        return os;
    }

    istream& operator>>(istream& is, Date& dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if(!is) { return is; }
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
            is.clear(ios_base::failbit);
            return is;
        }
        dd = Date(y, Month(m), d);
        return is;
    }

    long monthToDate(Month m, bool is_leap_year)
    {
        unsigned date = is_leap_year;
        for(unsigned i = 0; i < unsigned(m) - 1; ++i) {
            date += month_date[i];
        }
        return date;
    }

    long yearToDate(unsigned year) {
        unsigned date = 0;
        for(unsigned i = 1970; i < year; ++i) {
            date += 365 + is_leap_year(i);
        }
        return date;
    }

    unsigned dateToYear(long date) {
        unsigned cnt = 0;
        for( cnt = 1970; date >= 365 + is_leap_year(cnt);
             date -= 365 + is_leap_year(cnt),++cnt) { }
        return cnt;
    }

    Month dateToMonth(long date, bool is_leap_year) {
        unsigned cnt = 0;
        if (!is_leap_year) {
            for(;date >= month_date[cnt];  date-=month_date[cnt], ++cnt) { }
        }
        else {
            for(;date >= month_date_leap[cnt];  date-=month_date_leap[cnt], ++cnt) { }
        }
        return Month(cnt+1);
    }
}