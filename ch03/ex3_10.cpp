#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    while(getline(cin, s) && s != "999") {
        string temp;
        for(auto c : s) {
            if(!ispunct(c)) {
                temp += c;
            }
        }

        cout << temp << endl;
    }

    cout << s << endl;
}