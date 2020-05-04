// Created by loeije on 20/05/03.
// Exercise 12.2
// Write your own version of the StrBlob class including the const versions of front and back.

// initializer_list对象中的元素永远是常量值，我们无法改变initializer_list对象中元素的值。
// 并且，拷贝或赋值一个initializer_list对象不会拷贝列表中的元素，其实只是引用而已，原始列表和副本共享元素。

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>
#include <iostream>
using namespace std;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
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