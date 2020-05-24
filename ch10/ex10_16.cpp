/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-22 22:40:13
 * LastEditors: loeije
 * LastEditTime: 2020-05-22 22:42:25
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void elimdups(std::vector<std::string> &vs)
{
    sort(vs.begin(), vs.end());
    auto new_end = unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies(vector<string>, size_t sz) {
    elimdups(vs);
    
    stable_sort(vs.begin(), vs.end(), [](string const& lhs, string const& rhs){
        return lhs.size() < rhs.size();
    });
    
    auto wc = std::find_if(vs.begin(), vs.end(), [sz](string const& s){
            return s.size() >= sz;
    });

    std::for_each(wc, vs.end(), [](const string &s){
        std::cout << s << " ";
    }); 
}

int main()
{
    // ex10.16
    std::vector<std::string> v
    {
        "1234","1234","1234","hi~", "alan", "alan", "cp"
    };
    std::cout << "ex10.16: ";
    biggies(v, 3);
    std::cout << std::endl;

    return 0;
}