{
    StoreEntry *e2 = NULL;
    hash_link *table_entry = NULL;

    if (e->key && BIT_TEST(e->flag, KEY_PRIVATE))
	return;			/* is already private */

    if (e->key) {
	if ((table_entry = hash_lookup(table, e->key)))
	    e2 = (StoreEntry *) table_entry;
	if (e2 != e) {
	    debug(20, 0, "storeSetPrivateKey: non-unique key: '%s'\n", e->key);
	    return;
	}
	storeHashDelete(table_entry);
	if (!BIT_TEST(e->flag, KEY_URL))
	    safe_free(e->key);
    }
    e->key = xstrdup(storeGeneratePrivateKey(e->url, e->type_id, 0));
    storeHashInsert(e);
    BIT_RESET(e->flag, KEY_URL);
    BIT_SET(e->flag, KEY_CHANGE);
