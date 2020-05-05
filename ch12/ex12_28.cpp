#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <memory>
#include <sstream>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ifstream file("./ex12_20.txt");
    vector<string> input;
    map<string, set<size_t>> dict;
    decltype(input.size()) line_no{0};

    for(string line; getline(file, line); ++line_no) {
        input.push_back(line);
        istringstream   line_stream(line);
        for(string text, word; line_stream >> text; word.clear()) {
            remove_copy_if(text.begin(), text.end(), back_inserter(word), [](unsigned char ch) { return ispunct(ch); });
            dict[word].insert(line_no);
        }
    }

    for(;;) {
        cout << "enter word, q  exit\n";
        string s;
        if(!(cin >> s) || s == "q") break ;

        auto found = dict.find(s);
        if(found == dict.end()) cout << s << " 0 times\n";
        else {
            cout << s << " occurs " << found->second.size() << (found->second.size() > 1 ? " times" : " time") << std::endl;
            for(auto i : found->second) {
                cout << "\t(line " << i+1 << ") " << input.at(i) << std::endl;
            }
        }
    }

    return 0;
}