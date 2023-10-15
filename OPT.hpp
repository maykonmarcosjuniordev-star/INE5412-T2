#include <vector>
#include <algorithm>
#include <iostream>

class OPT
{
public:
    OPT(const std::vector<int> &references,
        int num_frames);

    int run();

private:
    int find_next_use(int current_pos);

    std::vector<int> references_;
    int num_frames_;
    int num_page_faults_;
};
