	debug(20, 0, "storeSetPrivateKey: Entry already exists with key '%s'\n",
	    newkey);
	debug(20, 0, "storeSetPrivateKey: Entry Dump:\n%s\n", storeToString(e2));
	debug_trap("Private key already exists.");
	return;
    }
    if (e->key)
	storeHashDelete(e);
