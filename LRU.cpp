#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class LRU {
private:
    int pageFrames;
    vector<int> references;
    unordered_map<int, list<int>::iterator> pageTable;
    list<int> pageList;

public:
    LRU(vector<int> refs, int frames) {
        references = refs;
        pageFrames = frames;
    }

    void simulate() {
        int pageFaults = 0;

        for (int i = 0; i < references.size(); i++) {
            int page = references[i];

            if (pageTable.find(page) == pageTable.end()) {
                pageFaults++;

                if (pageTable.size() == pageFrames) {
                    int lruPage = pageList.back();
                    pageList.pop_back();
                    pageTable.erase(lruPage);
                }

                pageList.push_front(page);
                pageTable[page] = pageList.begin();
            } else {
                pageList.erase(pageTable[page]);
                pageList.push_front(page);
                pageTable[page] = pageList.begin();
            }
        }

        cout << "Page faults: " << pageFaults << endl;
    }
};

int main() {
    vector<int> refs = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frames = 3;

    LRU lru(refs, frames);
    lru.simulate();

    return 0;
}
