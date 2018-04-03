	    break;
	prev = m->prev;
	i = m->data;
	if (i->locks != 0)
	    continue;
	ipcacheRelease(i);
	removed++;
    }
    debug(14, 9) ("ipcache_purgelru: removed %d entries\n", removed);
}

/* create blank ipcache_entry */
static ipcache_entry *
ipcacheCreateEntry(const char *name)
{
    static ipcache_entry *i;
    i = memAllocate(MEM_IPCACHE_ENTRY);
    i->name = xstrdup(name);
    i->expires = squid_curtime + Config.negativeDnsTtl;
    return i;
}

static void
ipcacheAddEntry(ipcache_entry * i)
{
    hash_link *e = hash_lookup(ip_table, i->name);
    if (NULL != e) {
	/* avoid colission */
	ipcache_entry *q = (ipcache_entry *) e;
	ipcacheRelease(q);
    }
    hash_join(ip_table, (hash_link *) i);
    dlinkAdd(i, &i->lru, &lru_list);
    i->lastref = squid_curtime;
}

/* walks down the pending list, calling handlers */
static void
ipcacheCallback(ipcache_entry * i)
{
    IPH *handler = i->handler;
    void *handlerData = i->handlerData;
    i->lastref = squid_curtime;
    ipcacheLockEntry(i);
    if (NULL == handler)
	return;
    i->handler = NULL;
    i->handlerData = NULL;
    if (cbdataValid(handlerData)) {
	dns_error_message = i->error_message;
	handler(i->flags.negcached ? &i->addrs : NULL, handlerData);
    }
    cbdataUnlock(i->handlerData);
    ipcacheUnlockEntry(i);
}

