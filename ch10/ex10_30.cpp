/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-23 15:52:53
 * LastEditors: loeije
 * LastEditTime: 2020-05-23 15:58:42
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec(istream_iterator<int>(cin), istream_iterator<int>());
    // vector<int> vec(10, 10);
    sort(vec.begin(), vec.end());
    copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, "\n"));
    return 0;
}