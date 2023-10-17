#ifndef OPT_HPP
#define OPT_HPP

// already inlcudes <vector>
#include "SubstitutionAlgorithm.hpp"

class OPT : public SubstitutionAlgorithm
{
private:
    // returns the position of the next use of the page
    int find_next_use(int page, int current_pos);

public:
    OPT(const std::vector<int> &refs, int num_frames);
    // simulate the OPT algorithm
    // Return the total number
    // of page faults.
    int run() override;
};

#endif // OPT_HPP
