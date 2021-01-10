#include "../../std_lib_facilities.h"
#include <cctype>

int main()
{
    string input_name;
    cin >> input_name;
    ifstream is{input_name};

    ofstream os{input_name + "_lowercase"};
    if(!is) { error("file open error!"); }

    for(char ch;is; ch = is.get()) {
        os << (char)tolower(ch);
    }
}