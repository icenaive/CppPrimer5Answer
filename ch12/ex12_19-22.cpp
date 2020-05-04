#include <fstream>
#include "ex12_19.h"

int main() {
    // StrBlob s2 {"this", "test", "is"};
    // StrBlobPtr s(s2, 1);
    
    // s.incr();
    // s2.begin();
    // cout << s.deref();
    // // cout << s2.begin();

    ifstream ifs("./ex12_20.txt");
    StrBlob s;
    for(string line; getline(ifs, line); ) { s.push_back(line); }
    for(StrBlobPtr ptr_begin(s.begin()), ptr_end(s.end()); ptr_begin != ptr_end; ptr_begin.incr()) {
        cout << ptr_begin.deref() << endl;
    }
    
    return 0;
}