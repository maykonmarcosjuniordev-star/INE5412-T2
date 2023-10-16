#include "LRU.hpp"
#include <vector>
#include <unordered_map>
#include <list>

LRU::LRU(vector<int> refs, int frames)
{
    references = refs;
    Nframes = frames;
}

int LRU::run()
{
    // Page Faults
    int PF = 0;
    unordered_map<int, list<int>::iterator> page_table;
    list<int> pageList;

    for (int page : references)
    {
        // if page is not already mapped
        if (page_table.find(page) == page_table.end())
        {
            PF++;

            // if page_table is full
            if (static_cast<int>(page_table.size()) == Nframes)
            {
                // take the last page on the list
                int lru_page = pageList.back();
                pageList.pop_back();
                page_table.erase(lru_page);
            }

            // add to the mapped pages
            pageList.push_front(page);
            page_table[page] = pageList.begin();
        }
        else
        {
            pageList.erase(page_table[page]);
            pageList.push_front(page);
            page_table[page] = pageList.begin();
        }
    }

    return PF;
}
