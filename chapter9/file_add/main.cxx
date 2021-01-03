#include "../../std_lib_facilities.h"

int main()
{
    string file_name1, file_name2;
    cin >> file_name1 >> file_name2;

    ifstream fs1{file_name1};
    ifstream fs2{file_name2};

    ofstream out{file_name1 + file_name2};
    if(!fs1 || !fs2 || !out) { error("file open error"); }

    fs1.tie(nullptr);
    fs2.tie(nullptr);

    fs1 >> noskipws;
    fs2 >> noskipws;
    fs1.sync_with_stdio(false);
    fs2.sync_with_stdio(false);

    for(char ch; fs1>>ch;) { out << ch; }
    for(char ch; fs2>>ch;) { out << ch; }
    
}