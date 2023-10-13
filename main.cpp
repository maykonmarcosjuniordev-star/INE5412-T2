#include <iostream>
#include <cstdio>
#include <vector>
#include "OPT.hpp"
#include "LRU.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <numero de quadros>" << std::endl;
        return 1;
    }

    // Converting to integer
    int Nboards = std::stoi(argv[1]);

    int page;
    std::vector<int> access_order;
    while (!feof(stdin))
    {
        std::cin >> page;
        if (!std::cin.fail())
        { // making sure it was well-suceded
            access_order.push_back(page);
        }
    }

    return 0;
}
