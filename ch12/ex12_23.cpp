#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void link(char *a, char *b, char *c) {
    strcat(c, a);
    strcat(c, b);
}

int main() {
    char *a = (char*)"123";
    char *b = (char*)"321";
    char *c = new char[strlen(a) + strlen(b) + 1]();
    link(a, b, c);
    cout << c << endl;
    string s1("hello");
    string s2(" string");
    cout << s1 + s2 << endl;
    delete[] c;
}