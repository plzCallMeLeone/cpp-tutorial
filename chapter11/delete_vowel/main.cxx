#include "../../std_lib_facilities.h"

bool is_target_char(char target, const string& s) {
    for(char ch : s) {
        if(target == ch) { return true; }
    }
    return false;
}
int main()
{
    string vowel = "aeiou";
    string fname;
    cin >> fname;
    ifstream is{fname};

    ofstream os{fname + "_output"};
    if(!is) { error("file open error!"); }

    for(char ch; is; ch = is.get()) {
        if(!is_target_char(ch, vowel)) {
            os << ch;
        }
    }
}