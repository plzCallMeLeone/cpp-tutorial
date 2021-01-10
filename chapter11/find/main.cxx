#include "../../std_lib_facilities.h"
#include <sstream>

int main()
{
    string fname, target;
    cout << "Input file name\n";
    cin >> fname;

    ifstream is{fname};
    if (!is) { error("Can't open file"); }
    cout << "Input word\n";
    cin >> target;

    istringstream ss;

    unsigned cnt = 1;

    [&] {
        for(string line;is;getline(is, line), ++cnt) {
            if(line.find(target)!=string::npos) {
                cout << '[' << cnt << "] " << line <<'\n';
            }
        }
        return;
    }();
}