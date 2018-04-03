	return;

    if (e->key == NULL) {
	debug(25, 0, "storeUnChangeKey: NULL key for %s\n", e->url);
	return;
    }
    if (table == (HashID) 0)
	fatal_dump("storeUnChangeKey: Hash table 'table' is zero!\n");

    if ((table_entry = hash_lookup(table, e->key)))
	E1 = (StoreEntry *) table_entry;
    if (E1 != e) {
	debug(25, 1, "storeUnChangeKey: Key is not unique for key: %s\n",
	    e->key);
	return;
    }
