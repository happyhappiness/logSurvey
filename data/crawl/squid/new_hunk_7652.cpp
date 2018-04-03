    debug(20, 5, "storeSwapInHandle: e->e_current_len = %d\n", mem->e_current_len);
    debug(20, 5, "storeSwapInHandle: e->object_len    = %d\n", e->object_len);

    if (len < 0)		/* XXX remove later */
	fatal_dump(NULL);

    /* always call these, even if len == 0 */
    mem->swap_offset += len;
    storeAppend(e, buf, len);
