#include "Simulator.hpp"
#include <iostream>
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
    if (algorithm == "OPT")
    {
        OPT opt(access_order, Nframes);
        return opt.run();
    }
    else if (algorithm == "LRU")
    {
        LRU lru(access_order, Nframes);
        return lru.run();
    }
    else if (algorithm == "FIFO")
    {
        FIFO fifo(access_order, Nframes);
        return fifo.run();
    }
    else
    {
        std::cerr << "Unknown Algorithm: " << algorithm << std::endl;
        return -1;
    }
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
