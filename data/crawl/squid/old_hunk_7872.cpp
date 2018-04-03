	sm_stats.total_pages_allocated++;
    }
    sm_stats.n_pages_in_use++;
    if (page == NULL) {
	debug(19, 0, "Null page pointer?");
	fatal_dump(NULL);
    }
    return (page);
}

void put_free_4k_page(page)
     char *page;
{
    static stack_overflow_warning_toggle;

#if USE_MEMALIGN
    if ((int) page % SM_PAGE_SIZE) {
	debug(19, 0, "Someone tossed a string into the 4k page pool\n");
	fatal_dump(NULL);
    }
#endif
    if (full_stack(&sm_stats.free_page_stack)) {
	sm_stats.total_pages_allocated--;
