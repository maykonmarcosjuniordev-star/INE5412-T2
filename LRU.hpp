#ifndef LRU_HPP
#define LRU_HPP

// already inlcudes <vector>
#include "SubstitutionAlgorithm.hpp"

class LRU : public SubstitutionAlgorithm
{
public:
    LRU(const std::vector<page_t> &refs, int num_frames);
    // simulate LRU algorithm
    // Return the total number
    // of page faults.
    int run() override;
};

#endif // LRU_HPP
