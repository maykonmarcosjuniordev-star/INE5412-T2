#include <vector>

class FIFO
{
private:
    // page references
    std::vector<int> references;
    // number of frames
    int Nframes;

public:
    FIFO(const std::vector<int> &refs, int num_frames);

    // simulate the FIFO algorithm
    int run();
};
