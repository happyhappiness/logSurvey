    storeClientCopy2(sc->entry, sc);
}

/* copy bytes requested by the client */
void
storeClientCopy(store_client * sc,
    StoreEntry * e,
    off_t seen_offset,
    off_t copy_offset,
    size_t size,
    char *buf,
    STCB * callback,
    void *data)
{
    assert(!EBIT_TEST(e->flags, ENTRY_ABORTED));
    debug(20, 3) ("storeClientCopy: %s, seen %d, want %d, size %d, cb %p, cbdata %p\n",
	storeKeyText(e->hash.key),
	(int) seen_offset,
	(int) copy_offset,
	(int) size,
	callback,
