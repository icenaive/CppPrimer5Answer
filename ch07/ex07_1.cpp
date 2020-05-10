#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

struct Sales_data
{
    string book_no;
    unsigned units_sold = 0;
    double revenue = 0;
};

int main() {
    Sales_data total;
    if(cin >> total.book_no >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while(cin >> trans.book_no >>trans.units_sold >> trans.revenue) {
            if(total.book_no == trans.book_no) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                cout << total.book_no << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.book_no << " " << total.revenue << endl;
    } else {
        std::cerr << "NO DATA" << endl;
        return -1;
    }
    return 0;
}