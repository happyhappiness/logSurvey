	}
    }
    IpcacheStats.misses++;
    /* check if it's already a IP address in text form. */
    if ((ip = inet_addr(name)) != INADDR_NONE) {
	*((u_num32 *) (void *) (*static_result->h_addr_list + 0)) = ip;
	strncpy(static_result->h_name, name, MAX_HOST_NAME);
	return static_result;
    }
    if (flags & IP_BLOCKING_LOOKUP) {
	IpcacheStats.ghbn_calls++;
	hp = gethostbyname(name);
	if (hp && hp->h_name && (hp->h_name[0] != '\0') && ip_table) {
	    /* good address, cached */
	    ipcache_add(name, ipcache_create(), hp, 1);
	    i = ipcache_get(name);
	    return &i->entry;
	}
	/* bad address, negative cached */
	if (ip_table)
	    ipcache_add(name, ipcache_create(), hp, 0);
	return NULL;
    }
    if (flags & IP_LOOKUP_IF_MISS)
	ipcache_nbgethostbyname(name, -1, dummy_handler, NULL);
    return NULL;
}


/* process objects list */
void stat_ipcache_get(sentry)
     StoreEntry *sentry;
{
    ipcache_entry *i = NULL;
    int k;
    int ttl;

    if (!ip_table)
	return;

    storeAppendPrintf(sentry, "{IP Cache Statistics:\n");
    storeAppendPrintf(sentry, "{IPcache Entries: %d}\n",
	meta_data.ipcache_count);
