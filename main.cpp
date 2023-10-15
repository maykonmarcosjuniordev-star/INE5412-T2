#include "Simulator.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Use: " << argv[0] << " <number of frames>" << std::endl;
        return 1;
    }

    int Nframes = std::stoi(argv[1]);

    Simulator sim(Nframes);
    sim.parameters();
    sim.simulate("FIFO");
    sim.simulate("LRU");
    sim.simulate("OPT");
    return 0;
}
