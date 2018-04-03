    STCB * callback,
    void *data)
{
    int ci;
    size_t sz;
    MemObject *mem = e->mem_obj;
    struct _store_client *sc;
    static int recurse_detect = 0;
    assert(seen_offset <= mem->e_current_len);
    assert(copy_offset >= mem->e_lowest_offset);
    assert(recurse_detect < 3);	/* could == 1 for IMS not modified's */
    debug(20, 3) ("storeClientCopy: %s, seen %d want %d, size %d, cb %p, cbdata %p\n",
	e->key,
	(int) seen_offset,
	(int) copy_offset,
	(int) size,
	callback,
	data);
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
    if (BIT_TEST(e->flag, DELETE_BEHIND))
	storeDeleteBehind(e);
    sz = memCopy(mem->data, copy_offset, buf, size);
    recurse_detect++;
    callback(data, buf, sz);
    recurse_detect--;
}

static int
storeEntryValidLength(const StoreEntry * e)
{
