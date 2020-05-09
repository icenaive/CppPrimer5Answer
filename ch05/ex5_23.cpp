#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    try {
        int c  = a / b;
    } catch (runtime_error err) {
        cout << err.what()
             << "again \n";
    }
    cout << a / b << endl;
}