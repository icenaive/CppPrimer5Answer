#include "ex12_07.hpp"

int main() {
    shared_ptr<vector<int>> ptr_vec = vector_pointor_genator();
    vector_pointor_process(ptr_vec);
    vector_pointor_printer(ptr_vec);
    return 0;
}