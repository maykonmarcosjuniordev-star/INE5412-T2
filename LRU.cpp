#include "LRU.hpp" // already includes <vector>
#include <unordered_map>
#include <list>

LRU::LRU(const std::vector<int> &refs, int num_frames)
    : SubstitutionAlgorithm(refs, num_frames) {}

int LRU::run()
{
    // Page Faults
    int PF = 0;
    std::unordered_map<int, std::list<int>::iterator> page_table;
    std::list<int> page_list;

    for (int page : references)
    {
        // if page is not already mapped
        if (page_table.find(page) == page_table.end())
        {
            // there is page fault
            PF++;

            // if page_table is full
            if (static_cast<int>(page_table.size()) == Nframes)
            {
                // take the last page on the list
                int lru_page = page_list.back();
                // erase from both page_table and page_list
                page_list.pop_back();
                page_table.erase(lru_page);
            }

            // add to the mapped pages
            page_list.push_front(page);
            page_table[page] = page_list.begin();
        }
        else // page is already mapped
        {
            // move the page to the front of the list
            page_list.erase(page_table[page]);
            page_list.push_front(page);
            // update the iterator
            // (it's index in the list)
            page_table[page] = page_list.begin();
        }
    }

    return PF;
}
