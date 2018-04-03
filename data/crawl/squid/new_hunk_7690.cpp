    new->mem_free_data_upto = memFreeDataUpto;
    new->mem_append = memAppend;
    new->mem_copy = memCopy;
#ifdef UNUSED_CODE
    new->mem_grep = memGrep;
#endif
    return new;
}

static void *get_free_thing(thing)
	stmem_stats *thing;
{
    void *p = NULL;
    if (!empty_stack(&thing->free_page_stack)) {
        p = pop(&thing->free_page_stack);
        if (p == NULL)
	    fatal_dump("get_free_thing: NULL pointer?");
    } else {
        p = xmalloc(thing->page_size);
	thing->total_pages_allocated++;
    }
    thing->n_pages_in_use++;
    memset(p, '\0', thing->page_size);
    return p;
}

void *get_free_request_t()
{
    return get_free_thing(&request_pool);
}

void *get_free_mem_obj()
{
    return get_free_thing(&mem_obj_pool);
}

char *get_free_4k_page()
{
    return get_free_thing(&sm_stats);
}

char *get_free_8k_page()
{
    return get_free_thing(&disk_stats);
}

static void put_free_thing(thing, p)
	stmem_stats *thing;
	void *p;
{
    thing->n_pages_in_use--;
    if (thing->total_pages_allocated > thing->max_pages) {
	xfree(p);
	thing->total_pages_allocated--;
    } else if (full_stack(&thing->free_page_stack)) {
	xfree(p);
	thing->total_pages_allocated--;
    } else {
        push(&thing->free_page_stack, p);
    }
}

void put_free_request_t(req)
     void *req;
{
    put_free_thing(&request_pool, req);
}

void put_free_mem_obj(mem)
     void *mem;
{
    put_free_thing(&mem_obj_pool, mem);
}

void put_free_4k_page(page)
     char *page;
{
    put_free_thing(&sm_stats, page);
}

void put_free_8k_page(page)
     char *page;
{
    put_free_thing(&disk_stats, page);
}

void stmemInit()
