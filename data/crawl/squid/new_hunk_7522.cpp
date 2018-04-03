	if ((hptr = hash_lookup(store_table, e->key)) == NULL) {
	    debug(20, 0, "storeRelease: Not Found: '%s'\n", e->key);
	    debug(20, 0, "Dump of Entry 'e':\n %s\n", storeToString(e));
	    debug_trap("storeRelease: Invalid Entry");
	}
	result = (StoreEntry *) hptr;
	if (result != e) {
	    debug(20, 0, "storeRelease: Duplicated entry? <URL:%s>\n",
		result->url ? result->url : "NULL");
	    debug(20, 0, "Dump of Entry 'e':\n%s", storeToString(e));
	    debug(20, 0, "Dump of Entry 'result':\n%s", storeToString(result));
	    debug_trap("storeRelease: Duplicate Entry");
	}
    }
    if (e->method == METHOD_GET) {
