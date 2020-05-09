#include <initializer_list>
#include <iostream>
using namespace std;

int res(initializer_list<int> list);

int main() {
    cout << res({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
}

int res(initializer_list<int> list) {
    int ret = 0;
    for(const auto &l : list) ret += l;

    return ret;
}
