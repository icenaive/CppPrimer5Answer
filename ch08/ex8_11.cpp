/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-17 11:17:06
 * LastEditors: loeije
 * LastEditTime: 2020-05-17 11:28:11
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct PeopleInfo
{
    string name;
    vector<string> phones;
};

string format(const string &str) {
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

bool valid(const string &str) {
    return str.size() == 11 && isdigit(str[0]);
}

int main() {
    fstream fs("./phone.txt");
    
    if(fs) {
        string line, word;
        vector<PeopleInfo> people;
        
        while(getline(fs, line)) {
            istringstream record(line);
            PeopleInfo info;
            record >> info.name;
            
            while(record >> word) {
                info.phones.push_back(word);
            }
            
            people.push_back(info);
        }  
        
        for(const auto &entry : people) {
            ostringstream badnums, formatnums;
            
            for(const string &nums : entry.phones) {
                if(!valid(nums)) badnums << " " << nums;
                else formatnums << " " << format(nums);
            }
            if(badnums.str().empty()) cout << entry.name << formatnums.str() << endl;
            else cout << entry.name << badnums.str() << endl; 
        }   
    } else {
        cerr << "open fail" << endl;
    }
    
    return 0;
}