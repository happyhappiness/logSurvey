	e2 = (StoreEntry *) table_entry;
	storeSetPrivateKey(e2);
	storeReleaseRequest(e2);
	if (loop_detect++ == 10)
	    fatal_dump("storeSetPublicKey() is looping!!");
	newkey = storeGeneratePublicKey(e->url, e->method);
    }
    if (e->key)
	storeHashDelete(e);
