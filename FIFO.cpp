#include "FIFO.hpp" // already inlcudes <vector>
#include <queue>
#include <unordered_set>

FIFO::FIFO(const std::vector<int> &access_order,
           int num_frames) : references(access_order),
                             Nframes(num_frames) {}

int FIFO::run()
{
    std::queue<int> frame_queue;
    // to allow search in the queue
    std::unordered_set<int> frame_set;
    int page_faults = 0;

    for (int page : references)
    {
        // if page is not in frame_set
        if (frame_set.find(page) == frame_set.end())
        {
            // if frame_queue is full
            if (frame_queue.size() == static_cast<std::size_t>(Nframes))
            {
                // remove the first element
                // from frame_queue
                int victim = frame_queue.front();
                frame_queue.pop();
                frame_set.erase(victim);
            }
            frame_queue.push(page);
            frame_set.insert(page);
            page_faults++;
        }
    }

    return page_faults;
}
