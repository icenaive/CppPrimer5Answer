#include "ex1_20.hpp"

// 这个循环读取计算相同记录很好

int main() {
    sales_item total;
    if(cin >> total) {
        sales_item cur;
        while(cin >> cur) {
            if(compareIsbn(total, cur)) {
                total += cur;
            } else {
                cout << total << endl;
                total = cur;
            }
        }
        // print the last
        cout << total << endl;
    } else {
        cerr << "NO dataa?" << endl;
        return -1;
    }
    return 0;
}