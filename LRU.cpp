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
    int pageFaults = 0;

    for (std::size_t i = 0; i < references.size(); i++)
    {
        int page = references[i];

        if (pageTable.find(page) == pageTable.end())
        {
            pageFaults++;

            if (pageTable.size() == static_cast<std::size_t>(Nframes))
            {
                int lruPage = pageList.back();
                pageList.pop_back();
                pageTable.erase(lruPage);
            }

            pageList.push_front(page);
            pageTable[page] = pageList.begin();
        }
        else
        {
            pageList.erase(pageTable[page]);
            pageList.push_front(page);
            pageTable[page] = pageList.begin();
        }
    }

    return pageFaults;
}
