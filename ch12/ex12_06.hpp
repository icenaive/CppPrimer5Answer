// Created by loeije on 20/05/03.
// Exercise 12.6
// 编写函数返回有个动态分配的int的vector。将此vector传递给另一个函数
// 这个函数从标准读入输入，在将vector返回给另一个函数 打印vector然后delete vector
#include <vector>
#include <memory>
#include <string>
#include <iostream>
using namespace std;

// 声明
vector<int>* vector_pointor_genator();
void vector_pointor_process(vector<int>* ptr_v);
void vector_pointor_printer(vector<int>* ptr_v);

// 实现
vector<int>* vector_pointor_genator() {
    vector<int>* ptr_vec = new vector<int>();
    return ptr_vec;
}

void vector_pointor_process(vector<int>* ptr_v) {
    int i;
    while(cin >> i && i != 999) ptr_v->push_back(i);
}

void vector_pointor_printer(vector<int>* ptr_v) {
    for(const int& i : *ptr_v) cout << i << " ";
    cout << endl;
}