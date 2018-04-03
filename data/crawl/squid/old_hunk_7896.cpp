	    fatal_dump(NULL);
	}
    }
    if (e->type_id == REQUEST_OP_GET) {
	/* check if coresponding HEAD object exists. */
	head_table_entry = hash_lookup(table,
	    storeGenerateKey(e->url, REQUEST_OP_HEAD));
	if (head_table_entry) {
	    head_result = (StoreEntry *) head_table_entry;
	    if (head_result) {
