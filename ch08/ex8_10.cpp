/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-17 10:52:19
 * LastEditors: loeije
 * LastEditTime: 2020-05-17 10:58:41
*/
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    vector<string> vec;
    ifstream ifs("./stream.dat");

    if(ifs) {
        string line;
        while(getline(ifs, line)) {
            vec.push_back(line);
        }

        for(auto &it : vec) {
            istringstream iss(it);
            string word;
            while(iss >> word) {
                cout << word << endl;
            }
        }
    } else {
        cerr << "open fail" << endl;
    }
    
    return 0;
}