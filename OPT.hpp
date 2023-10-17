#ifndef OPT_HPP
#define OPT_HPP

// already inlcudes <vector>
#include "SubstitutionAlgorithm.hpp"

class OPT : public SubstitutionAlgorithm
{
private:
    // returns the position of the next use of the page
    int find_next_use(page_t page, int current_pos);

public:
    OPT(const std::vector<page_t> &refs, int num_frames);
    // simulate the OPT algorithm
    // Return the total number
    // of page faults.
    int run() override;
};

#endif // OPT_HPP
