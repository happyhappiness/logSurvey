    storeAppendPrintf(sentry, "Cache Clients:\n");
    hash_first(client_table);
    while ((c = (ClientInfo *) hash_next(client_table))) {
	storeAppendPrintf(sentry, "Address: %s\n", c->key);
	storeAppendPrintf(sentry, "Name: %s\n", fqdnFromAddr(c->addr));
	storeAppendPrintf(sentry, "Currently established connections: %d\n",
	    c->n_established);
