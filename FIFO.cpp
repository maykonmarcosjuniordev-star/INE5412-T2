#include "FIFO.hpp" // already inlcudes <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

FIFO::FIFO(const std::vector<int> &refs,
           int num_frames)
{
    references = refs;
    Nframes = num_frames;
}

int FIFO::run()
{
    std::queue<int> frame_queue;
    // to allow search in the queue
    std::unordered_set<int> page_table;
    // Page Faults
    int PF = 0;

    for (int page : references)
    {
        // if page is not already mapped
        if (page_table.find(page) == page_table.end())
        {
            PF++;
            // if frame_queue is full
            if (static_cast<int>(page_table.size()) == Nframes)
            {
                // remove the first frame
                // from the queue
                int victim = frame_queue.front();
                frame_queue.pop();
                page_table.erase(victim);
            }
            frame_queue.push(page);
            page_table.insert(page);
        }
    }

    return PF;
}
