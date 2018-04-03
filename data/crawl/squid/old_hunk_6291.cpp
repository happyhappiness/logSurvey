    storeAppend(e, buf, strlen(buf));
}

int
storeCheckCachable(StoreEntry * e)
{
#if CACHE_ALL_METHODS
    if (e->mem_obj->method != METHOD_GET) {
	debug(20, 2) ("storeCheckCachable: NO: non-GET method\n");
    } else
#endif
    if (!EBIT_TEST(e->flag, ENTRY_CACHABLE)) {
	debug(20, 2) ("storeCheckCachable: NO: not cachable\n");
    } else if (EBIT_TEST(e->flag, RELEASE_REQUEST)) {
	debug(20, 2) ("storeCheckCachable: NO: release requested\n");
    } else if (e->store_status == STORE_OK && EBIT_TEST(e->flag, ENTRY_BAD_LENGTH)) {
	debug(20, 2) ("storeCheckCachable: NO: wrong content-length\n");
    } else if (EBIT_TEST(e->flag, ENTRY_NEGCACHED)) {
	debug(20, 3) ("storeCheckCachable: NO: negative cached\n");
	return 0;		/* avoid release call below */
    } else if (e->mem_obj->inmem_hi > Config.Store.maxObjectSize) {
	debug(20, 2) ("storeCheckCachable: NO: too big\n");
    } else if (EBIT_TEST(e->flag, KEY_PRIVATE)) {
	debug(20, 3) ("storeCheckCachable: NO: private key\n");
    } else if (storeExpiredReferenceAge() < 300) {
	debug(20, 2) ("storeCheckCachable: NO: LRU Age = %d\n",
	    storeExpiredReferenceAge());
    } else {
	return 1;
    }
    storeReleaseRequest(e);
    EBIT_CLR(e->flag, ENTRY_CACHABLE);
    return 0;
}

/* Complete transfer into the local cache.  */
void
storeComplete(StoreEntry * e)
