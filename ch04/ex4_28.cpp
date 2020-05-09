#include <iostream>
using namespace std;

int main() {
    bool b;
    char c;
    wchar_t wc;
    char16_t c16;
    char32_t c32;
    short st;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;
    cout << "bool sizeof is: "<<sizeof b << endl;
    cout << "char sizeof is: "<<sizeof c << endl;
    cout << "wchar_t sizeof is: "<<sizeof wc << endl;
    cout << "char16_t sizeof is: "<<sizeof c16 << endl;
    cout << "char32_t sizeof is: "<<sizeof c32 << endl;
    cout << "short sizeof is: "<<sizeof st << endl;
    cout << "int sizeof is: "<<sizeof i << endl;
    cout << "long sizeof is: "<<sizeof l << endl;
    cout << "long long sizeof is: "<<sizeof ll << endl;
    cout << "float sizeof is: "<<sizeof f << endl;
    cout << "double sizeof is: "<<sizeof d << endl;
    cout << "long double sizeof is: "<<sizeof ld << endl;
    return 0;
}