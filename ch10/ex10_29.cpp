/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-23 15:40:51
 * LastEditors: loeije
 * LastEditTime: 2020-05-23 15:46:54
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main() {
    ifstream ifs("./string.txt");
    istream_iterator<string> in(ifs), eof;
    vector<string> vec;
    copy(in, eof, back_inserter(vec));

    copy(vec.cbegin(), vec.cend(), ostream_iterator<string>(cout, "\n"));
    return 0;
}