#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main() {
    // 使用strlen计算长度然后在赋值
    
    string s;
    cin >> s;
    char *c = new char[strlen(s.c_str()) - 4];
    
    c = (char*)s.c_str();
    cout << strlen(c) << endl;
    cout << c << endl;
    
    delete[] c;
    return 0;
}