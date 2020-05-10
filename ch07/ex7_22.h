#ifndef EX7_22_H
#define EX7_22_H

#include <string>
#include <vector>
#include <iostream>

class Person;
// std::istream &read(std::istream &in, Person &person);
// std::ostream &print(std::ostream &out, const Person &person);

class Person {
friend std::istream &read(std::istream &in, Person &person);
friend std::ostream &print(std::ostream &out, const Person &person);
public:
    Person() = default;
    Person(std::istream &in) { read(in, *this); } 
public:
    std::string read_name() const { return this->name; }
    std::string read_address() const { return this->address; }

private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &in, Person &person) {
    return in >> person.name >> person.address;
}

std::ostream &print(std::ostream &out, const Person &person) {
    return out << person.name << " " << person.address;
}

#endif // EX7_22_H