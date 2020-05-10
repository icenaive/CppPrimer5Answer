#ifndef EX7_2_H
#define EX7_2_H

#include <string>
#include <vector>
#include <iostream>

class Sales_data {
public:
    Sales_data() : units_sold(0), revenue(0.0) { }
    Sales_data(const Sales_data &rhs) : book_no(rhs.book_no), units_sold(rhs.units_sold), revenue(rhs.revenue) { }
    std::string isbn() const { return this->book_no; }
    Sales_data &combine(const Sales_data &rhs);
    Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:
    std::string book_no;
    unsigned units_sold;
    double revenue;
};

inline Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline Sales_data Sales_data::add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum(lhs);
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &in, Sales_data &item) {
    double price = 0;
    in >> item.book_no >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return in;
}

std::ostream &print(std::ostream &out, const Sales_data &item) {
    out << item.book_no << " " << item.units_sold << " " << item.revenue;
    return out;
}
#endif // EX7_2_H