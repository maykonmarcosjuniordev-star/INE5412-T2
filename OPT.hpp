#include <vector>
#include <algorithm>
#include <iostream>

class OPT
{
public:
    OPT(const std::vector<int> &refs,
        int num_frames);

    // simulate the OPT algorithm
    int run();

private:
    int find_next_use(int current_pos);

    // page references
    std::vector<int> references;
    // number of frames
    int Nframes;
};
