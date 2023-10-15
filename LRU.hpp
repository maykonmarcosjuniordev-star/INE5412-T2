#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class LRU
{
private:
    int Nframes;
    vector<int> references;
    unordered_map<int, list<int>::iterator> pageTable;
    list<int> pageList;

public:
    LRU(vector<int> refs, int frames);

    int run();
};
