#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ReadFile {
public:
    ReadFile(const std::string& name) : nomeArquivo(name) {}

    void read() {
        std::ifstream file(nomeArquivo);
        std::string line;
        while (std::getline(file, line)) {
            access_order.push_back(std::stoi(line));
        }
    }

    std::vector<int> access_order;
    std::string nomeArquivo;
};
