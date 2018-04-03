    int ci;
    size_t sz;
    MemObject *mem = e->mem_obj;
    struct _store_client *sc;
    assert(seen_offset <= mem->e_current_len);
    assert(copy_offset < mem->e_lowest_offset);
    if ((ci = storeClientListSearch(mem, data)) < 0)
	fatal_dump("storeClientCopy: Unregistered client");
    sc = &mem->clients[ci];
    sc->copy_offset = copy_offset;
    sc->seen_offset = seen_offset;
    if (seen_offset == mem->e_current_len) {
	/* client has already seen this, wait for more */
	sc->callback = callback;
	sc->copy_buf = buf;
	sc->copy_size = size;
	sc->copy_offset = copy_offset;
	return;
    }
    sz = memCopy(mem->data, copy_offset, buf, size);
    callback(data, buf, sz);
    /* see if we can get rid of some data if we are in "delete behind" mode . */
    if (BIT_TEST(e->flag, DELETE_BEHIND))