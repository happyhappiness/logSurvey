    return 0;
}

static int
storeCopy(const StoreEntry * e, int stateoffset, int maxSize, char *buf, int *size)
{
    int available;
    MemObject *mem = e->mem_obj;
    int s;
    if (stateoffset < mem->e_lowest_offset) {
	debug_trap("storeCopy: requested offset < e_lowest_offset");
	return *size = 0;
    }
    s = available = mem->e_current_len - stateoffset;
    if (s < 0)
	fatal_dump("storeCopy: offset > e_current_len");
    if (s > maxSize)
	s = maxSize;
    debug(20, 6, "storeCopy: copying %d bytes at offset %d\n", s, stateoffset);
    if (s > 0)
	(void) mem->data->mem_copy(mem->data, stateoffset, buf, s);
    return *size = s;
}

/* check if there is any client waiting for this object at all */
