    void *p = NULL;
    if (!empty_stack(&thing->free_page_stack)) {
	p = pop(&thing->free_page_stack);
	assert(p != NULL);
    } else {
	p = xmalloc(thing->page_size);
	thing->total_pages_allocated++;
