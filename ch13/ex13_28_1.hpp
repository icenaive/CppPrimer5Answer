/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-06-01 10:00:27
 * LastEditors: loeije
 * LastEditTime: 2020-06-01 10:31:14
*/
#include <string>
using namespace std;

class TreeNode {
public:
    TreeNode() : value(string()), count(int(0)), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
    TreeNode& operator=(const TreeNode &rhs) {
        ++*rhs.count;
        if(--*count == 0) {
            delete count;
            delete left;
            delete right;
        }

        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        return *this;
    }

    ~TreeNode() {
        if(--*count == 0) {
            delete count;
            delete left;
            delete right;
        }
    }
private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};