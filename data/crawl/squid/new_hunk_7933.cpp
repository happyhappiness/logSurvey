    if (t == NULL)
	fatal_dump("storeUnChangeKey: Can't find a second slash.\n");
    strcpy(key, t + 1);
    if ((table_entry = hash_lookup(table, key))) {
	debug(25, 0, "storeUnChangeKey: '%s' already exists!  Releasing/Moving.\n",
	    key);
	E2 = (StoreEntry *) table_entry;
	/* get rid of the old entry */
	if (storeEntryLocked(E2)) {
	    /* change original hash key to get out of the new object's way */
	    storeChangeKey(E2);
	    BIT_SET(E2->flag, RELEASE_REQUEST);
	} else {
	    storeRelease(E2);
	}
    }
    if (!(E1->flag & KEY_URL))
	safe_free(E1->key);
    E1->key = xstrdup(key);
    storeHashInsert(e);
    BIT_RESET(E1->flag, KEY_CHANGE);
    BIT_SET(E1->flag, KEY_URL);
    debug(25, 0, "storeUnChangeKey: Changed back to '%s'\n", key);
}

/* return if the current key is the original one. */
