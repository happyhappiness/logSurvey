
#if USE_MEMALIGN
    if ((int) page % SM_PAGE_SIZE) {
	debug(0, "Someone tossed a string into the 4k page pool\n");
	fatal_dump(NULL);
    }
#endif
    if (full_stack(&sm_stats.free_page_stack)) {
	sm_stats.total_pages_allocated--;
	if (!stack_overflow_warning_toggle) {
	    debug(0, "Stack of free stmem pages overflowed.  Resize it?");
	    stack_overflow_warning_toggle++;
	}
    }
