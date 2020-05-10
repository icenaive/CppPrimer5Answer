#ifndef EX7_24_H
#define EX7_24_H
#include <string>
#include <iostream>
#include <vector>

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
public:
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
public:
    // typedef std::string::size_type pos;
    using pos = std::string::size_type;
public:
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { } 
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
public:
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const  { return contents[r * width + c]; }
    Screen &move(const pos &r, const pos &c);
    Screen &set(char c);
    Screen &set(const pos &r, const pos &c, char ch);  
    const Screen& display(std::ostream &os) const { do_display(os); return *this; }
    Screen& display(std::ostream &os) { do_display(os); return *this; }
private:
    void do_display(std::ostream &os) const { os << contents; };
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline void Window_mgr::clear(ScreenIndex i) {
    if(i >= screens.size()) return ;
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Screen& Screen::move(const pos &r, const pos &c) {
    cursor = r * width + c;
    return *this;
}

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen& Screen::set(const pos &r, const pos &c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}



#endif // EX7_24_H