//
//  Exercise 12.15
//
//  Created by loeije on 20/5/4.
//
// 观察拷贝和复制unique_ptr指针的错误

#include <memory>
#include <iostream>

using namespace std;

int main() {
    unique_ptr<int> p(new int(9));
    
    // copy
    // unique_ptr<int> q(p);
    // error msg    
    // use of deleted function....
    // assign
    // unique_ptr<int> q = p;
    // error msg
    // use of deleted function ...
    cout << *p << endl;
    p.reset(nullptr);
    return 0;
}