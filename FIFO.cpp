#include "FIFO.hpp" // already inlcudes <vector>
#include <unordered_set>
#include <queue>

FIFO::FIFO(const std::vector<page_t> &refs, int num_frames)
    : SubstitutionAlgorithm(refs, num_frames) {}

int FIFO::run()
{
    std::queue<page_t> frame_queue;
    // to allow search in the queue
    std::unordered_set<page_t> page_table;
    // Page Faults
    int PF = 0;

    for (page_t page : references)
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
                page_t victim = frame_queue.front();
                frame_queue.pop();
                page_table.erase(victim);
            }
            frame_queue.push(page);
            page_table.insert(page);
        }
    }

    return PF;
}
