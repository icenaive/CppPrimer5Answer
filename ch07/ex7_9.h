#ifndef EX7_5_H
#define EX7_5_H

#include <string>
#include <vector>
#include <iostream>
std::istream &read(std::istream &in, Person &person);
std::ostream &print(std::ostream &out, const Person &person);

class Person {
public:
    std::string read_name() const { return this->name; }
    std::string read_address() const { return this->address; }

public:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &in, Person &person) {
    return in >> person.name >> person.address;
}

std::ostream &print(std::ostream &out, const Person &person) {
    return out << person.name << " " << person.address;
}

#endif // EX7_5_H