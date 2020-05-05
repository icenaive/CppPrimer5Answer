#include "ex12_27.hpp"

void runQueries(ifstream&);

int main() {
    ifstream file("./ex12_20.txt");
    runQueries(file);
    return 0;
}

void runQueries(ifstream& f) {
    TextQuery tq(f);
    string s;
    for(;;) {
        cout << "input word, q exit\n";
        if(!(cin >> s) || s == "q") return ;
        print(cout, tq.query(s)) << endl;
    }
}