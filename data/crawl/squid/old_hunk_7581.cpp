	debug(20, 0, "storeSetPrivateKey: Entry already exists with key '%s'\n",
	    newkey);
	debug(20, 0, "storeSetPrivateKey: Entry Dump:\n%s\n", storeToString(e2));
	fatal_dump("Private key already exists.");
    }
    if (e->key)
	storeHashDelete(e);
