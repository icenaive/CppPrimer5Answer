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
using namespace std;


class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) { }
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr &rhs) {
        ++*rhs.use;
        if(--*use == 0) {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return  *this;
    } 

    ~HasPtr() {
        if(--*use == 0) {
            delete ps;
            delete use;
        }
    }
private:
    string *ps;
    int i;
    size_t *use;
};