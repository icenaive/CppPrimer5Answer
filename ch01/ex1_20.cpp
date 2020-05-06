#include "ex1_20.hpp"

int main() {
    sales_item item1, item2;
    cin >> item1 >> item2;
    cout << "item1: " << item1 << endl;
    cout << "item2: " << item2 << endl;
    if(compareIsbn(item1, item2)) 
        cout << item1 + item2 << endl;
    else 
        std::cerr << "Data must refer to same ISBN" << endl;
    return 0;
}