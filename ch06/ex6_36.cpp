#include <iostream>
#include <vector>
#include <string>
using namespace std;

using vs = vector<string>;

vector<string> fun() {
    return vector<string>(10, "1");
}

vs fun_us() {
    return vector<string>(10, "1");
}

decltype()
int main() {
    for(auto v : fun()) cout << v << endl;
}