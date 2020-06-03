/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-06-01 10:33:15
 * LastEditors: loeije
 * LastEditTime: 2020-06-01 10:49:17
*/
class BinStrTree {
public:
    BinStrTree() : root(new BinStrTree()) { }
    BinStrTree(const BinStrTree &bst) : root(new BinStrTree(*bst.root)) { }
    BinStrTree& operator=(const BinStrTree &bst) {
        BinStrTree *new_r = new BinStrTree(*bst.root);
        delete root;
        root = new_r;
        return *this;
    }
    ~BinStrTree() { delete root; }
private:
    BinStrTree *root;
};