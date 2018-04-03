    if (t == NULL)
	fatal_dump("storeUnChangeKey: Can't find a second slash.\n");
    strcpy(key, t + 1);
    if (!(result->flag & KEY_URL))
	safe_free(result->key);
    result->key = xstrdup(key);
    storeHashInsert(e);
    BIT_RESET(result->flag, KEY_CHANGE);
    BIT_SET(result->flag, KEY_URL);
    debug(0, 0, "storeUnChangeKey: Changed back to '%s'\n", key);
}

/* return if the current key is the original one. */
