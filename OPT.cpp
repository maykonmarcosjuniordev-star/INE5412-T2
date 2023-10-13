#include <vector>
#include <algorithm>
#include <iostream>

class OptimalSubstitutionAlgorithm {
public:
    OptimalSubstitutionAlgorithm(const std::vector<int>& references, int num_frames)
        : references_(references), num_frames_(num_frames), num_page_faults_(0)
    {}

    int run() {
        std::vector<int> frames(num_frames_, -1);
        std::vector<int> next_use(references_.size(), -1);

        for (int i = 0; i < references_.size(); ++i) {
            bool page_fault = true;
            int page = references_[i];

            for (int j = 0; j < num_frames_; ++j) {
                if (frames[j] == page) {
                    page_fault = false;
                    break;
                }
            }

            if (page_fault) {
                ++num_page_faults_;

                bool empty_frame = false;
                int frame_to_replace = -1;

                for (int j = 0; j < num_frames_; ++j) {
                    if (frames[j] == -1) {
                        empty_frame = true;
                        frame_to_replace = j;
                        break;
                    }

                    if (next_use[j] == -1) {
                        frame_to_replace = j;
                        break;
                    }

                    if (next_use[j] > next_use[frame_to_replace]) {
                        frame_to_replace = j;
                    }
                }

                if (empty_frame) {
                    frames[frame_to_replace] = page;
                    next_use[frame_to_replace] = find_next_use(i);
                } else {
                    frames[frame_to_replace] = page;
                    next_use[frame_to_replace] = find_next_use(i);
                }
            }
        }

        return num_page_faults_;
    }

private:
    int find_next_use(int current_pos) {
        for (int i = current_pos + 1; i < references_.size(); ++i) {
            if (references_[i] == references_[current_pos]) {
                return i;
            }
        }

        return references_.size();
    }

    std::vector<int> references_;
    int num_frames_;
    int num_page_faults_;
};
