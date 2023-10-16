#include <vector>

class OPT
{
public:
    OPT(const std::vector<int> &refs,
        int num_frames);

    // simulate the OPT algorithm
    // Return the total number
    // of page faults.
    int run();

private:
    // returns the position of the next use of the page
    int find_next_use(int page, int current_pos);

    // page references
    std::vector<int> references;
    // number of frames
    int Nframes;
};
