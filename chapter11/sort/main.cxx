#include "../../std_lib_facilities.h"
#include <ios>

void clear_to_int(istream& is)
{
    for(char ch; is && !isdigit(ch); is >> ch) { }
    if(is.good()) { is.unget(); }
}
int main()
{
    ifstream is{"test"};

    if(!is) { error("Coudln't open file"); }
    is.exceptions(is.exceptions() | ios_base::badbit);

    vector<int> numbers;

    try {
        for(int tmp;is >> tmp;) { numbers.push_back(tmp); }

    }
    catch(...) {
        cerr << "Unexpected Error!\n";
    }

    sort(numbers.begin(), numbers.end());
    unsigned cnt = 1;
    bool state_in = false;
    for(unsigned i = 0; i < numbers.size(); ++i) {
        if( i > 0 && numbers[i-1] == numbers[i] ) {
            ++cnt;
            state_in = true;
            continue;
        }
        else if(i > 0 && state_in && numbers[i] != numbers[i-1]) {
            cout << ' ' << cnt << '\n';
            cnt = 0;
            state_in = false;
        }
        else {
            cout << '\n';
        }
        cout << numbers[i];
    }
}