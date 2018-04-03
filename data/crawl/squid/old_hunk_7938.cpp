	debug(0, 0, "storeChangeKey: NULL key for %s\n", e->url);
	return;
    }
    if (table != (HashID) 0) {
	hash_link *table_entry = hash_lookup(table, e->key);
	if (table_entry)
	    result = (StoreEntry *) table_entry;
	if (result == e) {
	    storeHashDelete(table_entry);

	    key[0] = '\0';
	    sprintf(key, "/x%d/%s", keychange_count++, e->key);
	    if (!(result->flag & KEY_URL))
		safe_free(result->key);
	    result->key = xstrdup(key);

	    storeHashInsert(e);
	    BIT_SET(result->flag, KEY_CHANGE);
	    BIT_RESET(result->flag, KEY_URL);
	} else {
	    debug(0, 1, "storeChangeKey: Key is not unique for key: %s\n", e->key);
	}
    }
}

/* return if the current key is the original one. */
