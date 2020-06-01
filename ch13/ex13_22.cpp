/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-31 16:01:07
 * LastEditors: loeije
 * LastEditTime: 2020-05-31 16:04:48
*/
#include <string>
using namespace std;


class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(const HasPtr &hp) {
        auto new_p = new string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }
    
    ~HasPtr() {
        delete ps;
    }
private:
    string *ps;
    int i;
};