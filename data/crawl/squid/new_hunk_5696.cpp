    storeClientCopy2(sc->entry, sc);
}

void
storeClientCopyOld(store_client *sc, StoreEntry *e, off_t seen_offset,
   off_t copy_offset, size_t size, char *buf, STCB *callback, void *data)
{
    /* OLD API -- adrian */
    fatal("storeClientCopyOld() has been called!\n");
}


/* copy bytes requested by the client */
void
storeClientCopy(store_client * sc,
    StoreEntry * e,
    off_t copy_offset,
    size_t size,
    char *buf,
    STCB * callback,
    void *data)
{
    assert(!EBIT_TEST(e->flags, ENTRY_ABORTED));
    debug(20, 3) ("storeClientCopy: %s, want %d, size %d, cb %p, cbdata %p\n",
	storeKeyText(e->hash.key),
	(int) copy_offset,
	(int) size,
	callback,
