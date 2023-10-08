class PageInfo {
public:
    PageInfo();
    int page_faults = 0;
    int page_hits = 0;

    void set_hit() {
        page_hits++;
    }
    void set_fault() {
        page_faults++;
    }
};