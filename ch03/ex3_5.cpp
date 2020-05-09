#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    string res;
    while((cin >> s) && s != "q") {
        if( res == "" )
            res += s;
        else 
            res += " " + s;
    }
    cout << res << endl;
}