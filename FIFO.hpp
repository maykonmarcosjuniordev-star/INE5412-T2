#include <vector>

class FIFO
{
private:
    std::vector<int> references;
    int Nframes;

public:
    FIFO(const std::vector<int> &access_order, int num_frames);

    // simulate the FIFO algorithm
    int run();
};
