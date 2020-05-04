#include "ex12_02.h"

int main() {
    StrBlob s1;
    // cout << s1.back();
    // cout << s1.front();
    // s1.pop_back();
    cout << s1.empty();
    s1.push_back("s1");
    // cout << s1.back();
    StrBlob s2 {"this", "test", "is"};
    cout << s2.front() << " " << s2.back() << " ";
    s2.pop_back();
    cout << s2.back();
    return 0;
}