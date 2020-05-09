#include <initializer_list>
#include <iostream>
#include <vector>
using namespace std;
using Iter = vector<int>::iterator;
void res(const vector<int> &arr, int idx);
void iter(Iter start, Iter end);

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6};
    // res(arr, arr.size() - 1);
    iter(arr.begin(), arr.end());
}

void res(const vector<int> &arr, int idx) {
    if(idx != 0) {
        res(arr, idx - 1);
    }
    cout << arr[idx] << endl;
    return ;
}

void iter(Iter start, Iter end) {
    if(start != end) {
        cout << *start << endl;
        iter(++start, end);
    }
}
