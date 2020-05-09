#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    // 一次读入一行
    // while(getline(cin, s)) {
    //     cout << s << endl;
    // }
    while(cin >> s) {
        cout << s << endl;
    }
}