#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <set>
#include <map>
#include <cctype>
using namespace std;

class QueryResult;

class TextQuery {
public:
    // using line_no = vector<string>::size_type;
    typedef vector<string>::size_type size_type; 
    TextQuery(ifstream& );
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> input;
    map<string, shared_ptr<set<size_type>>> result;
};

class QueryResult {
public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::size_type>> set, shared_ptr<vector<string>> v) : word(s), nos(set), input(v) {}
public:
    friend ostream& print(ostream&, const QueryResult&);
private:
    string word;
    shared_ptr<set<TextQuery::size_type>> nos;
    shared_ptr<vector<string>> input;
};

ostream& print(ostream& out, const QueryResult& qr) {
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    
    for(auto i : *qr.nos) {
        out << "\t(line )" << i + 1 << ")" << qr.input->at(i) << endl;
    } 
    
    return out;
}

TextQuery::TextQuery(ifstream& f) : input(new vector<string>) {
    size_type lineno{0};
    for(string line; getline(f, line); ++lineno) {
        input->push_back(line);
        istringstream line_stream(line);
        for(string text, word; line_stream >> text; word.clear()) {
            // avoid read a word followed by punctuation(such as: word, )
            // ispunct 包含多个版本，将其包含在lambda中 编译器可以选取合适的版本
            remove_copy_if(text.begin(), text.end(), back_inserter(word), [](unsigned char ch){ return ispunct(ch); });
            // 使用引用避免智能指针计数增加
            auto& nos = result[word];
            if(!nos) nos.reset(new set<size_type>);
            nos->insert(lineno);
        }
    }
}

QueryResult TextQuery::query(const string& str) const {
    static shared_ptr<set<size_type>> nodata(new set<size_type>);
    auto found = result.find(str);
    if(found == result.end()) return QueryResult(str, nodata, input);
    else return QueryResult(str, found->second, input);
}

