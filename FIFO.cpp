#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class FIFO {
public:
    FIFO(const std::vector<int>& references, int num_frames) : references_(references), num_frames_(num_frames) {}

    int run() {
        std::queue<int> frame_queue;
        std::unordered_set<int> frame_set;
        int page_faults = 0;

        for (int page : references_) {
            if (frame_set.find(page) == frame_set.end()) {
                if (frame_queue.size() == num_frames_) {
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

private:
    std::vector<int> references_;
    int num_frames_;
};
