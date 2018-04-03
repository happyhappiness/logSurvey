	disk_stats.total_pages_allocated++;
    }
    disk_stats.n_pages_in_use++;
    if (page == NULL) {
	debug(19, 0, "Null page pointer?");
	fatal_dump(NULL);
    }
    return (page);
}

void put_free_8k_page(page)
     char *page;
{
    static stack_overflow_warning_toggle;

#if USE_MEMALIGN
    if ((int) page % DISK_PAGE_SIZE) {
	debug(19, 0, "Someone tossed a string into the 8k page pool\n");
	fatal_dump(NULL);
    }
#endif

    if (full_stack(&disk_stats.free_page_stack)) {
