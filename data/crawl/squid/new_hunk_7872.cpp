	sm_stats.total_pages_allocated++;
    }
    sm_stats.n_pages_in_use++;
    debug(19, 5, "get_free_4k_page: Giving out %p, count=%d  %s:%d\n",
	page, sm_stats.n_pages_in_use, file, line);
    if (page == NULL)
	fatal_dump("get_free_4k_page: Null page pointer?");
    return (page);
}

void put_free_4k_page(page, file, line)
     char *page;
     char *file;
     int line;
{
    static stack_overflow_warning_toggle;

#if USE_MEMALIGN
    if ((int) page % SM_PAGE_SIZE)
	fatal_dump("Someone tossed a string into the 4k page pool");
#endif
    if (full_stack(&sm_stats.free_page_stack)) {
	sm_stats.total_pages_allocated--;
