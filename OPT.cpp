#include <vector>
#include <algorithm>
#include <iostream>
#include "OPT.hpp"

OPT::OPT(const std::vector<int> &refs,
         int num_frames)
{
    references = refs;
    Nframes = num_frames;
}

// returns the position of the next use of the page
int OPT::find_next_use(int current_pos)
{
    for (std::size_t i = current_pos + 1; i < references.size(); ++i)
    {
        if (references[i] == references[current_pos])
        {
            return i;
        }
    }

    return references.size();
}

int OPT::run()
{
    int PF = 0;
    std::vector<int> frames(Nframes, -1);
    std::vector<int> next_use(references.size(), -1);

    for (std::size_t i = 0; i < references.size(); ++i)
    {
        bool page_fault = true;
        int page = references[i];

        for (int j = 0; j < Nframes; ++j)
        {
            if (frames[j] == page)
            {
                page_fault = false;
                break;
            }
        }

        if (page_fault)
        {
            PF++;

            bool empty_frame = false;
            int frame_to_replace = -1;

            for (int j = 0; j < Nframes; ++j)
            {
                if (frames[j] == -1)
                {
                    empty_frame = true;
                    frame_to_replace = j;
                    break;
                }

                if (next_use[j] == -1)
                {
                    frame_to_replace = j;
                    break;
                }

                if (next_use[j] > next_use[frame_to_replace])
                {
                    frame_to_replace = j;
                }
            }

            if (empty_frame)
            {
                frames[frame_to_replace] = page;
                next_use[frame_to_replace] = find_next_use(i);
            }
            else
            {
                frames[frame_to_replace] = page;
                next_use[frame_to_replace] = find_next_use(i);
            }
        }
    }

    return PF;
}
