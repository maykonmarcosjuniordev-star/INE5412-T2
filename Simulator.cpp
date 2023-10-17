#include "Simulator.hpp" // already includes <vector>
#include <iostream>
#include "SubstitutionAlgorithm.hpp"
#include "OPT.hpp"
#include "LRU.hpp"
#include "FIFO.hpp"
// string and vector includes
// are already on Simulator.hpp

Simulator::Simulator(int num_frames)
{
    Nframes = num_frames;

    int page;
    while (!feof(stdin))
    {
        std::cin >> page;
        if (!std::cin.fail())
        { // making sure it suceded
            access_order.push_back(page);
        }
    }
}

int Simulator::run(std::string algorithm)
{
    SubstitutionAlgorithm *algo = nullptr;

    if (algorithm == "OPT")
    {
        algo = new OPT(access_order, Nframes);
    }
    else if (algorithm == "LRU")
    {
        algo = new LRU(access_order, Nframes);
    }
    else if (algorithm == "FIFO")
    {
        algo = new FIFO(access_order, Nframes);
    }
    else
    {
        std::cerr << "Unknown Algorithm: " << algorithm << std::endl;
        return -1;
    }

    int result = algo->run();
    delete algo; // Clean up the dynamically allocated memory.
    return result;
}
void Simulator::simulate(std::string algorithm)
{
    int PF = run(algorithm);
    if (PF == -1)
    {
        return;
    }
    std::cout << algorithm
              << ": " << PF
              << " PFs\n";
}

void Simulator::parameters()
{
    std::cout << Nframes << " quadros\n";
    std::cout << access_order.size() << " refs\n";
}
