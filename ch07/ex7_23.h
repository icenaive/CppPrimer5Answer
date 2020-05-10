#ifndef EX7_23_H
#define EX7_23_H
#include <string>

class Screen {
public:
    // typedef std::string::size_type pos;
    using pos = std::string::size_type;
public:
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
public:
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const  { return contents[r * width + c]; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif // EX7_23_H