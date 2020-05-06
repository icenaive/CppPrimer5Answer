#include <iostream>
#include "ex2_40.h"

int main() {
    Sales_data data1, data2;
    // read data1 data2
    double price = 0.0;
    std::cin >> data1.book_no >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    
    std::cin >> data2.book_no >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    // 检查isbn
    if(data1.book_no == data2.book_no) {
        unsigned total_cnt = data1.units_sold + data2.units_sold;
        double total_revenu = data1.revenue + data2.revenue;
        std::cout << data1.book_no << total_cnt << total_revenu << std::endl;
        if(total_cnt) 
            std::cout << total_revenu / total_cnt << std::endl;
        else {
            std::cout << "no sale" << std::endl;
        }

        return 0;
    } else {
        std::cerr << "don't same" << std::endl;
        return -1;
    }
    // 如果相同求和

}