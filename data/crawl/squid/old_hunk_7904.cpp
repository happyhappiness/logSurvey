	debug(25, 0, "storeChangeKey: NULL key for %s\n", e->url);
	return;
    }
    if (table == (HashID) 0)
	fatal_dump("storeChangeKey: Hash table 'table' is zero!\n");

    if ((table_entry = hash_lookup(table, e->key)))
	result = (StoreEntry *) table_entry;
