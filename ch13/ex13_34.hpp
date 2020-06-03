/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-06-01 17:00:13
 * LastEditors: loeije
 * LastEditTime: 2020-06-01 17:25:50
*/
#include <string>
#include <set>

class Folder;

class Message {
    friend class Folder;
public:
    explicit Message(const std::string &s = "") : contents(s) { }
    Message(const Message&);
    Message& operator=(const Message& rhs) {
        remove_from_folder();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_folder(rhs);
        return *this;
    }
    ~Message();

public:
    void save(Folder& f) { folders.insert(&f); f.addMsg(this); }
    void remove(Folder& f) { folders.erase(f); f.remMst(this); }
    void swap(Message &lhs, Message &rhs) {
        for(auto f : lhs.folders) f->remMsg(&lhs);
        for(auto f : rhs.folders) f->remMsg(&rhs);
        swap(lhs.folders, rhs.folders);
        swap(lhs.contents, rhs.contents);
        for(auto f : lhs.folders) f->addMsg(&lhs);
        for(auto f : rhs.folders) f->addMsg(&rhs);
    }
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_folder(const Message &);
    void remove_from_folder();
};

void Message::add_to_folder(const Message &m) {
    for(auto f : m.folders) f->addMsg(this);
}

void Message::remove_from_folder() {
    for(auto f : folders) {
        f->remMsg(this);
    }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_folder(m);
}
Message::~Message() {
    remove_from_folder();
}


class Folder {
    friend void swap(Folder &, Folder &);
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder &);
    Folder& operator=(const Folder &);
    ~Folder();

    void print_debug();

private:
    std::set<Message*> msgs;

    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

void swap(Folder &, Folder &);