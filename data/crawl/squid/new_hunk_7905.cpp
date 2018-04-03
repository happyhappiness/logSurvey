	debug(25, 0, "storeUnChangeKey: NULL key for %s\n", e->url);
	return;
    }

    if ((table_entry = hash_lookup(table, e->key)))
	E1 = (StoreEntry *) table_entry;
