	e2 = (StoreEntry *) table_entry;
	storeSetPrivateKey(e2);
	storeReleaseRequest(e2);
    }
    if (e->key)
	storeHashDelete(e);
