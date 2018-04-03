	debug(20, 0, "%s", storeToString(e));
	fatal_dump(NULL);
    }
    if (e->lock_count)
	return 1;
    if (e->swap_status == SWAPPING_OUT)
	return 1;
    if (e->mem_status == SWAPPING_IN)
	return 1;
    return 0;
}

/*  use this for internal call only */
