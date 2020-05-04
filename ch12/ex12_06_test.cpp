#include "ex12_06.hpp"

int main() {
    vector<int>* ptr_vec = vector_pointor_genator();
    vector_pointor_process(ptr_vec);
    vector_pointor_printer(ptr_vec);
    delete ptr_vec; ptr_vec = nullptr;
    return 0;
}