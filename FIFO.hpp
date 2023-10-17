#ifndef FIFO_HPP
#define FIFO_HPP

// already inlcudes <vector>
#include "SubstitutionAlgorithm.hpp"

class FIFO : public SubstitutionAlgorithm
{
public:
    FIFO(const std::vector<page_t> &refs, int num_frames);
    // simulate the FIFO algorithm
    // Return the total number
    // of page faults.
    int run() override;
};

#endif // FIFO_HPP
