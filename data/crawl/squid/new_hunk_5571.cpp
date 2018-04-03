    storeClientCopy2(sc->entry, sc);
}

/* copy bytes requested by the client */
void
storeClientCopy(store_client * sc,
    StoreEntry * e,
    StoreIOBuffer copyInto,
    STCB * callback,
    void *data)
{
    assert(!EBIT_TEST(e->flags, ENTRY_ABORTED));
    debug(20, 3) ("storeClientCopy: %s, from %lu, for length %d, cb %p, cbdata %p\n",
	storeKeyText(e->hash.key),
	copyInto.offset,
	copyInto.length,
	callback,
	data);
    assert(sc != NULL);
