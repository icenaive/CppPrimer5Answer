#include <string>
#include <iostream>
using namespace std;

int main() {
    string s = "124345";
    for(char& c : s) 
        c = 'X';
    cout << s << endl;
}