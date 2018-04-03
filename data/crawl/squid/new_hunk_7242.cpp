
/* same to storeCopy but also register client fd and last requested offset
 * for each client */
void
storeClientCopy(StoreEntry * e,
    off_t offset,
    size_t size,
    char *buf,
    STCB * callback,
    void *data)
{
    int ci;
    size_t sz;
    MemObject *mem = e->mem_obj;
    if (offset < mem->e_lowest_offset) {
	debug_trap("storeClientCopy: requested offset < lowest offset");
	debug(20, 0, " --> %d < %d\n",
	    offset, mem->e_lowest_offset);
	debug(20, 0, "--> '%s'\n", e->url);
	return;
    }
    if ((ci = storeClientListSearch(mem, data)) < 0)
	fatal_dump("storeClientCopy: Unregistered client");
    mem->clients[ci].offset = offset;
    if (offset >= mem->e_current_len) {
	mem->clients[ci].callback = callback;
	mem->clients[ci].copy_buf = buf;
	mem->clients[ci].copy_size = size;
	return;
    }
    sz = memCopy(mem->data, offset, buf, size);
debug(0,0,"storeClientCopy: size=%d\n", sz);
    callback(data, buf, sz);
    /* see if we can get rid of some data if we are in "delete behind" mode . */
    if (BIT_TEST(e->flag, DELETE_BEHIND))
	storeDeleteBehind(e);
}

static int