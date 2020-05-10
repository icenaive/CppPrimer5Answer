#ifndef EX7_5_H
#define EX7_5_H

#include <string>
#include <vector>

class Person {
public:
    std::string read_name() const { return this->name; }
    std::string read_address() const { return this->address; }
public:
    std::string name;
    std::string address;
};
#endif // EX7_5_H