/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-17 09:42:26
 * LastEditors: loeije
 * LastEditTime: 2020-05-17 10:44:40
*/
#include <iostream>
#include <sstream>
using namespace std;

istream& test(istream &in) {
    string a;
    while(in >> a)
        cout << a << endl;
    in.clear();
    return in;
}

int main() {
    // istream &in = test(cin);
    istringstream iss("hell0");
    test(iss);
    return 0;
}