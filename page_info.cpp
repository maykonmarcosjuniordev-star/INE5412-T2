#include "page_info.hpp"

PageInfo::PageInfo()
{
    page_faults = 0;
    page_hits = 0;
}

void PageInfo::set_hit()
{
    page_hits++;
}

void PageInfo::set_fault()
{
    page_faults++;
}

int PageInfo::get_hit()
{
    return page_hits;
}

int PageInfo::get_fault()
{
    return page_faults;
}
