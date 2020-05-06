#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>
#include <string>
using namespace std;

class sales_item {
friend istream& operator>>(istream&, sales_item&);
friend ostream& operator<<(ostream&, const sales_item&);
friend bool operator<(const sales_item&, const sales_item&);
friend bool operator==(const sales_item&, const sales_item&);
public:
    sales_item() : units_sold(0), revenue(0.0) {}
    sales_item(const string& book) : book_no(book), units_sold(0), revenue(0.0) { }
    sales_item(istream& is) { is >> *this; } 
public:
    sales_item& operator+=(const sales_item&);
    string isbn() const { return book_no; }
    double avg_price() const;
private:
    string book_no;
    unsigned units_sold;
    double revenue;
};

inline
bool compareIsbn(const sales_item &lhs, const sales_item &rhs) 
{ return lhs.isbn() == rhs.isbn(); }


inline bool 
operator==(const sales_item& lhs, const sales_item& rhs) {
    return lhs.units_sold == rhs.units_sold && 
            lhs.revenue == rhs.revenue && 
            lhs.isbn() == rhs.isbn();
}

inline bool 
operator!=(const sales_item& lhs, const sales_item& rhs) {
    return !(lhs == rhs);
}

sales_item& sales_item::operator+=(const sales_item& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

sales_item 
operator+(const sales_item& lhs, const sales_item& rhs) {
    sales_item ret(lhs);
    ret += rhs;
    return ret;
}

istream& operator>>(istream& in, sales_item& s) {
    double price;
    in >> s.book_no >> s.units_sold >> price;
    if(in) s.revenue = s.units_sold * price;
    else s = sales_item();
    
    return in;
}

ostream& operator<<(ostream& out, const sales_item& s) {
    out << s.isbn() << " " << s.units_sold << " " 
        << s.revenue << " " << s.avg_price() << endl;
    
    return out;
}

double sales_item::avg_price() const {
    if(units_sold) return revenue / units_sold;
    else return 0;
}
#endif