	debug_trap("storeSwapInStart: mem_obj already present");
	return -1;
    }
    e->mem_obj = mem = new_MemObject();

    path = storeSwapFullPath(e->swap_file_number, NULL);
    if ((fd = file_open(path, NULL, O_RDONLY)) < 0) {
	debug(20, 0, "storeSwapInStart: Failed for '%s'\n", e->url);
	storeSetMemStatus(e, NOT_IN_MEMORY);
	/* Invoke a store abort that should free the memory object */
	return -1;
    }
    mem->swapin_fd = (short) fd;
    debug(20, 5, "storeSwapInStart: initialized swap file '%s' for '%s'\n",
	path, e->url);
    storeSetMemStatus(e, SWAPPING_IN);
    mem->data = new_MemObjectData();
    mem->swap_offset = 0;
    mem->e_swap_buf = get_free_8k_page();

    /* start swapping daemon */
    file_read(fd,
	mem->e_swap_buf,
	SWAP_BUF,
	mem->swap_offset,
	(FILE_READ_HD) storeSwapInHandle,
	(void *) e);
    mem->swapin_complete_handler = swapin_complete_handler;
    mem->swapin_complete_data = swapin_complete_data;
    return 0;
}

static void
