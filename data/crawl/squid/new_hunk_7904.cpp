	debug(25, 0, "storeChangeKey: NULL key for %s\n", e->url);
	return;
    }

    if ((table_entry = hash_lookup(table, e->key)))
	result = (StoreEntry *) table_entry;
