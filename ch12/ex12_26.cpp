#include <memory>
#include <iostream>
#include <string>
using namespace std;

void input_reverse_output_string(int n) {
    allocator<string> alloc;
    string *const p = alloc.allocate(n);
    string s;
    auto q = p;
    while(q != p + n && cin >> s) {
        // 在内存上构造元素
        alloc.construct(q++, s);
    }

    while(q != p) {
        cout << *--q << endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
}
int main() {
    input_reverse_output_string(3);
    return 0;
}