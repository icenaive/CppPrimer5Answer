/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-31 11:32:38
 * LastEditors: loeije
 * LastEditTime: 2020-05-31 11:41:01
*/
#include <iostream>
using namespace std;

class numbered {
public:
    numbered() { mysn = unique++; }
    // 13.15
    numbered(const numbered &n) { mysn = unique++; }
    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered s) {
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a;
    // 13.16
    const numbered &b = a, &c = b;
    f(a);
    f(b);
    f(c);
}