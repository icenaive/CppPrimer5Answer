#include <vector>
#include <iostream>
using namespace std;

int main() {
    int arr[4] = { 0, 1, 2, 3};
    // vector<int> vec(begin(arr), end(arr));
    vector<int> vec(arr, arr + 4);
    int arr_copy[4];
    for(auto v : vec)  
    for(auto v : vec) cout << v << endl;
}