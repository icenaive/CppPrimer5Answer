/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-17 10:20:09
 * LastEditors: loeije
 * LastEditTime: 2020-05-17 10:26:57
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void read(const string &file_name, vector<string> &vec) {
    ifstream ifs(file_name);
    
    if(ifs) {
        string buf;    
        //while(getline(ifs, buf)) {
        // 8_5
        while(ifs >> buf){
            vec.push_back(buf);
        }
    } else {
        cerr << "open fail!" << endl;
    }
}

int main() {
    string file = "./data.dat";
    vector<string> vec;
    read(file, vec);
    for(const auto &it : vec) {
        cout << it << endl;
    }
    return 0;
}