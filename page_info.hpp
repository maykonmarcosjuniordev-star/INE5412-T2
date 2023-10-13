class PageInfo
{
private:
    int page_faults;
    int page_hits;

public:
    PageInfo();
    void set_hit();
    void set_fault();
    int get_hit();
    int get_fault();
};
