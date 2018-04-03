
    while ((c = (ClientInfo *) hash_next(client_table))) {
        storeAppendPrintf(sentry, "Address: %s\n", hashKeyStr(&c->hash));
        storeAppendPrintf(sentry, "Name:    %s\n", fqdnFromAddr(c->addr));
        storeAppendPrintf(sentry, "Currently established connections: %d\n",
                          c->n_established);
        storeAppendPrintf(sentry, "    ICP  Requests %d\n",
