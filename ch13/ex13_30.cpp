/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-06-01 15:49:21
 * LastEditors: loeije
 * LastEditTime: 2020-06-01 16:08:54
*/
/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-06-01 09:51:41
 * LastEditors: loeije
 * LastEditTime: 2020-06-01 09:57:17
*/
#include <string>
#include <algorithm>
using namespace std;


class HasPtr {
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) { }
    // HasPtr& operator=(const HasPtr &hp) {
    //     auto new_p = new string(*hp.ps);
    //     delete ps;
    //     ps = new_p;
    //     i = hp.i;
    //     return *this;
    // }

    HasPtr& operator=(HasPtr hp) {
        using std::swap;
        swap(*this, hp);
        return *this;
    }
    
    ~HasPtr() {
        delete ps;
    }

public:

private:
    string *ps;
    int i;
};


inline 
void swap(HasPtr &lhs, HasPtr &rhs) {
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
    return *lhs.ps < *rhs.ps;
}