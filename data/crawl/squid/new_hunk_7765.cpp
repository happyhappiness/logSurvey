void put_free_8k_page(page)
     char *page;
{
#if USE_MEMALIGN
    if ((int) page % DISK_PAGE_SIZE)
	fatal_dump("Someone tossed a string into the 8k page pool");
#endif
    if (full_stack(&disk_stats.free_page_stack))
	disk_stats.total_pages_allocated--;
    disk_stats.n_pages_in_use--;
    push(&disk_stats.free_page_stack, page);
}

