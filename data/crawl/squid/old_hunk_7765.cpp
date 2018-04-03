void put_free_8k_page(page)
     char *page;
{
    static stack_overflow_warning_toggle;

#if USE_MEMALIGN
    if ((int) page % DISK_PAGE_SIZE)
	fatal_dump("Someone tossed a string into the 8k page pool");
#endif

    if (full_stack(&disk_stats.free_page_stack)) {
	disk_stats.total_pages_allocated--;
	if (!stack_overflow_warning_toggle) {
	    debug(19, 0, "Stack of free disk pages overflowed.  Resize it?");
	    stack_overflow_warning_toggle++;
	}
    }
    disk_stats.n_pages_in_use--;
    /* Call push regardless if it's full, cause it's just going to release the
     * page if stack is full */
    push(&disk_stats.free_page_stack, page);
}

