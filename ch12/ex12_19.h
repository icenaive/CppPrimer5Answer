// Created by loeije on 20/05/03.
// Exercise 12.19
// 定义自己版本的strblobptr函数，添加strblob类的friend声明和begin，end函数

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>
#include <iostream>
using namespace std;

// 前置声明
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr begin() const ;
    ConstStrBlobPtr end() const ;

    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
    
    size_type size() { return data->size(); }
    bool empty() { return data->empty(); }
    
    void push_back(const string& s) { return data->push_back(s); } 
    string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    void pop_back() { 
        check(0, "pop_back on empty StrBlob");
        return data->pop_back();
    }
    

private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string& msg) const { 
        if(i >= data->size()) 
            throw out_of_range(msg);
    }
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr;} 
    string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
     
private:
    shared_ptr<vector<string>> check(size_t i, const string& msg) const {
        auto ret = wptr.lock();
        if(!ret) throw runtime_error("unbound StrBlobPtr");
        if(i >= ret->size()) throw out_of_range(msg);
        return ret;
    }

    weak_ptr<vector<string>> wptr;
    size_t curr;
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }

    const string& deref() const {
        const auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    const ConstStrBlobPtr incr() {
        check(curr, "dereference past end");
        ++curr;
        return *this;
    }
private:
    shared_ptr<vector<string>> check(size_t i, const string& msg) const {
        auto res = wptr.lock();
        if(!res) throw runtime_error("dereference past end");
        if(i >= res->size()) throw out_of_range(msg);
        return res;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { 
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); } 