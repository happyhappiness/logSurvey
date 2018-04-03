/* Do whatever is necessary to begin storage of new object */
mem_ptr memInit()
{
    mem_ptr new = xcalloc(1, sizeof(Mem_Hdr));
    new->tail = new->head = NULL;
    new->mem_free = memFree;
    new->mem_free_data = memFreeData;
    new->mem_free_data_upto = memFreeDataUpto;
    new->mem_append = memAppend;
    new->mem_copy = memCopy;
    new->mem_grep = memGrep;
    return new;
}

void *get_free_request_t()
{
    void *req = NULL;
    if (!empty_stack(&request_pool.free_page_stack)) {
	req = pop(&request_pool.free_page_stack);
    } else {
	req = xmalloc(sizeof(request_t));
	request_pool.total_pages_allocated++;
    }
    request_pool.n_pages_in_use++;
    if (req == NULL)
	fatal_dump("get_free_request_t: Null pointer?");
    memset(req, '\0', sizeof(request_t));
    return (req);
}

void put_free_request_t(req)
     void *req;
{
    if (full_stack(&request_pool.free_page_stack))
	request_pool.total_pages_allocated--;
    request_pool.n_pages_in_use--;
    push(&request_pool.free_page_stack, req);
}

void *get_free_mem_obj()
{
    void *mem = NULL;
    if (!empty_stack(&mem_obj_pool.free_page_stack)) {
	mem = pop(&mem_obj_pool.free_page_stack);
    } else {
	mem = xmalloc(sizeof(MemObject));
	mem_obj_pool.total_pages_allocated++;
    }
    mem_obj_pool.n_pages_in_use++;
    if (mem == NULL)
	fatal_dump("get_free_mem_obj: Null pointer?");
    memset(mem, '\0', sizeof(MemObject));
    return (mem);
}

void put_free_mem_obj(mem)
     void *mem;
{
    if (full_stack(&mem_obj_pool.free_page_stack))
	mem_obj_pool.total_pages_allocated--;
    mem_obj_pool.n_pages_in_use--;
    push(&mem_obj_pool.free_page_stack, mem);
}


/* PBD 12/95: Memory allocator routines for saving and reallocating fixed 
 * size blocks rather than mallocing and freeing them */
char *get_free_4k_page()
{
    char *page = NULL;
    if (!empty_stack(&sm_stats.free_page_stack)) {
	page = pop(&sm_stats.free_page_stack);
    } else {
#if USE_MEMALIGN
	page = memalign(SM_PAGE_SIZE, SM_PAGE_SIZE);
	if (!page)
	    fatal_dump(NULL);
#else
	page = xmalloc(SM_PAGE_SIZE);
#endif
	sm_stats.total_pages_allocated++;
    }
