// SubstitutionAlgorithm.hpp
#ifndef SUBSTITUTIONALGORITHM_HPP
#define SUBSTITUTIONALGORITHM_HPP

#include <vector>

class SubstitutionAlgorithm
{
protected:
    std::vector<int> references;
    int Nframes;

public:
    SubstitutionAlgorithm(const std::vector<int> &refs, int frames)
        : references(refs), Nframes(frames) {}

    virtual ~SubstitutionAlgorithm() = default;

    // This will be a pure virtual function,
    // ensuring that every derived class implements it.
    // simulate the algorithm and
    // return the number of page faults
    virtual int run() = 0;
};

#endif // SUBSTITUTIONALGORITHM_HPP
