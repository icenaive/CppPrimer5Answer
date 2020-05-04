//
//  Exercise 12.15
//
//  Created by loeije on 20/5/4.
//
//  编写自己版本的shared_ptr管理的connection函数
// 使用lambda表达式
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

struct connection {
    string ip;
    int port;
    connection(string ip_, int port_) : ip(ip_), port(port_) {} 
};

struct destination {
    string ip;
    int port;
    destination(string ip_, int port_) : ip(ip_), port(port_) {} 
};

connection conn (destination *des_ptr) {
    shared_ptr<connection> ptr_conn(new connection(des_ptr->ip, des_ptr->port));
    cout << "creation connection " << ptr_conn.use_count() << endl; 
    return *ptr_conn;
}

void disconn (connection ptr_conn) {
    cout << "connection close(" << ptr_conn.ip << ":" << ptr_conn.port << ")" << endl;
}

// void end_connection (connection *ptr_conn) {
//     disconn(*ptr_conn);
// }

void f(destination &d) {
    connection c = conn(&d);
    shared_ptr<connection> p(&c, [](connection *p) { disconn(*p); });
    cout << "connecting now(" << p.use_count() << ")" << endl;
}

