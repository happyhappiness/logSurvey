    return key_counter;
}

static void
storeSetPrivateKey(StoreEntry * e)
{
    const cache_key *newkey;
    MemObject *mem = e->mem_obj;
    if (e->key && BIT_TEST(e->flag, KEY_PRIVATE))
	return;			/* is already private */
    if (e->key)
	storeHashDelete(e);
    if (mem != NULL) {
	mem->reqnum = getKeyCounter();
	newkey = storeKeyPrivate(mem->url, e->method, mem->reqnum);
    } else {
	newkey = storeKeyPrivate("JUNK", METHOD_NONE, getKeyCounter());
    }
    assert(hash_lookup(store_table, newkey) == NULL);
    storeHashInsert(e, newkey);
    BIT_SET(e->flag, KEY_PRIVATE);
}

void
storeSetPublicKey(StoreEntry * e)
{
    StoreEntry *e2 = NULL;
    const cache_key *newkey;
    MemObject *mem = e->mem_obj;
    if (e->key && !BIT_TEST(e->flag, KEY_PRIVATE))
	return;			/* is already public */
    assert(mem);
    newkey = storeKeyPublic(mem->url, e->method);
    if ((e2 = (StoreEntry *) hash_lookup(store_table, newkey))) {
	debug(20, 3) ("storeSetPublicKey: Making old '%s' private.\n", mem->url);
	storeSetPrivateKey(e2);
	storeRelease(e2);
	newkey = storeKeyPublic(mem->url, e->method);
    }
    if (e->key)
	storeHashDelete(e);
    storeHashInsert(e, newkey);
    BIT_CLR(e->flag, KEY_PRIVATE);
}

StoreEntry *
