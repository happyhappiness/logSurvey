	debug(20, 0, "%s", storeToString(e));
	fatal_dump(NULL);
    }
    return ((e->lock_count) ||
	(e->store_status == STORE_PENDING) ||
	(e->swap_status == SWAPPING_OUT) ||
	(e->mem_status == SWAPPING_IN)
	);
}

/*  use this for internal call only */
