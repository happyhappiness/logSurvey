	BIT_SET(e->flag, RELEASE_REQUEST);
	return -1;
    }
    debug(20, 5, "storeRelease: Releasing: %s\n", e->url);

    if (table == (HashID) 0)
	fatal_dump("storeRelease: Hash table 'table' is zero!\n");

    if (e->key == NULL) {
	debug(20, 0, "storeRelease: NULL key for %s\n", e->url);
	debug(20, 0, "Dump of Entry 'e':\n %s\n", storeToString(e));
	fatal_dump(NULL);
    }
    if ((hptr = hash_lookup(table, e->key)) == NULL) {
	debug(20, 0, "storeRelease: Not Found: %s\n", e->url);
	debug(20, 0, "Dump of Entry 'e':\n %s\n", storeToString(e));
	fatal_dump(NULL);
    }
    result = (StoreEntry *) hptr;

    if (result != e) {
	debug(20, 0, "storeRelease: Duplicated entry? <URL:%s>\n",
	    result->url ? result->url : "NULL");
	debug(20, 0, "Dump of Entry 'e':\n%s", storeToString(e));
	debug(20, 0, "Dump of Entry 'result':\n%s", storeToString(result));
	fatal_dump(NULL);
    }
    if (e->type_id == REQUEST_OP_GET) {
	/* check if coresponding HEAD object exists. */
	hash_link *head_table_entry = NULL;
	head_table_entry = hash_lookup(table, storeGenerateKey(e->url, REQUEST_OP_HEAD));
	if (head_table_entry) {
	    head_result = (StoreEntry *) head_table_entry;
	    if (head_result) {
