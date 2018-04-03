    MemObject *mem = NULL;

    /* sanity check! */
    if ((e->swap_status != SWAP_OK) || (e->swap_file_number < 0)) {
	debug(20, 0, "storeSwapInStart: <No filename:%d> ? <URL:%s>\n",
	    e->swap_file_number, e->url);
	if (e->mem_obj)
	    e->mem_obj->swapin_fd = -1;
	return -1;
    }
    /* create additional structure for object in memory */
    e->mem_obj = mem = new_MemObject();

    path = storeSwapFullPath(e->swap_file_number, NULL);
