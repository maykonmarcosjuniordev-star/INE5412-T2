#include <iostream>
#include "read_file.hpp"


int main() {
    ReadFile file("vsim-belady.txt");
    file.read();
    std::vector<int> line = file.access_order;
    for (auto& line : file.access_order) {
        std::cout << line << std::endl;
    }
    return 0;
}