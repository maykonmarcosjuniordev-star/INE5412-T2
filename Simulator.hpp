#include <string>
#include <vector>

class Simulator
{
private:
    // page references on the program
    std::vector<int> access_order;
    // fisic memory capacity
    int Nframes;

    // return the Page Faults number
    // for the given algorithm and
    // a access_order
    int run(std::string algorithm);

public:
    // read the page references from stdin
    Simulator(int num_frames);

    ~Simulator(){};

    // run the simulation for the given algorithm
    void simulate(std::string algorithm);

    // print number of frames and references
    void parameters();
};
