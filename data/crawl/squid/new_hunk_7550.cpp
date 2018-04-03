    return p;
}

void *
get_free_request_t()
{
    return get_free_thing(&request_pool);
}

void *
get_free_mem_obj()
{
    return get_free_thing(&mem_obj_pool);
}

char *
get_free_4k_page()
{
    return (char *) get_free_thing(&sm_stats);
}

char *
get_free_8k_page()
{
    return (char *) get_free_thing(&disk_stats);
}

static void
put_free_thing(stmem_stats * thing, void *p)
{
    if (p == NULL)
	fatal_dump("Somebody is putting a NULL pointer!");
