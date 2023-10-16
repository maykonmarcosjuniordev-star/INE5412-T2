#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class LRU
{
private:
    // page references
    std::vector<int> references;
    // number of frames
    int Nframes;

public:
    LRU(vector<int> refs, int frames);

    // simulate LRU algorithm
    // Return the total number
    // of page faults.
    int run();
};
