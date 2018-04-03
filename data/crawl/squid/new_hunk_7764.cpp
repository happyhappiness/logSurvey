void put_free_4k_page(page)
     char *page;
{
#if USE_MEMALIGN
    if ((int) page % SM_PAGE_SIZE)
	fatal_dump("Someone tossed a string into the 4k page pool");
#endif
    if (full_stack(&sm_stats.free_page_stack))
	sm_stats.total_pages_allocated--;
    sm_stats.n_pages_in_use--;
    push(&sm_stats.free_page_stack, page);
}

char *get_free_8k_page()
{
    char *page = NULL;
    if (!empty_stack(&disk_stats.free_page_stack)) {
	page = pop(&disk_stats.free_page_stack);
    } else {
#if USE_MEMALIGN
	page = memalign(DISK_PAGE_SIZE, DISK_PAGE_SIZE);
	if (!page)
	    fatal_dump(NULL);
#else
	page = xmalloc(DISK_PAGE_SIZE);
#endif
	disk_stats.total_pages_allocated++;
    }
