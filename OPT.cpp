#include "OPT.hpp"
#include <unordered_set>

OPT::OPT(const std::vector<int> &refs, int num_frames)
    : SubstitutionAlgorithm(refs, num_frames) {}

int OPT::find_next_use(int page, int current_pos)
{
    // Starting from the next position, search for the page.
    for (std::size_t i = current_pos + 1; i < references.size(); ++i)
    {
        if (references[i] == page)
        {
            return i;
        }
    }
    // If the page is not found
    // in the future references,
    // return the size of the references.
    return references.size();
}

int OPT::run()
{
    int PF = 0;
    // Store the pages currently in frames.
    std::vector<int> frames;
    // Set to quickly check if a page is in frames.
    std::unordered_set<int> pages_in_frames;

    // Go through each page in the references.
    for (std::size_t i = 0; i < references.size(); ++i)
    {
        int page = references[i];

        // If page is not already mapped
        if (pages_in_frames.find(page) == pages_in_frames.end())
        {
            PF++;

            // If there's space in frames
            if (frames.size() < static_cast<std::size_t>(Nframes))
            {
                frames.push_back(page);
                pages_in_frames.insert(page);
            }
            else
            {
                // If frames are full,
                // decide which frame to replace.
                int farthest = i, replace_idx = -1;
                // Go through each page in the frames
                // to see which is used farthest in the future.
                for (int j = 0; j < Nframes; ++j)
                {
                    int next_use = find_next_use(frames[j], i);
                    // Update the farthest use
                    // if this page is used later
                    // than current farthest.
                    if (next_use > farthest)
                    {
                        farthest = next_use;
                        // Save the index of this frame.
                        replace_idx = j;
                    }
                }

                // Replace the page in the frame
                // with the farthest next use.
                pages_in_frames.erase(frames[replace_idx]);
                frames[replace_idx] = page;
                pages_in_frames.insert(page);
            }
        }
    }

    return PF;
}
