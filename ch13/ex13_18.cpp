/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-31 15:33:41
 * LastEditors: loeije
 * LastEditTime: 2020-05-31 15:39:05
*/
class Employee
{
public:
    Employee() { id = unique++; }
    Employee(const string &n) : name(n) { id = unique++; }
private:
    string name;
    int id;
    static int unique;
};

int Employee::unique = 10;

