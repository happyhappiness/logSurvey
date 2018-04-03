    return hptr ? (netdbEntry *) hptr->item : NULL;
}

static netdbEntry *
netdbGetFirst(HashID table)
{
    return (netdbEntry *) hash_first(table);
}

static netdbEntry *
netdbGetNext(HashID table)
{
    return (netdbEntry *) hash_next(table);
}

static void
netdbRelease(netdbEntry * n)
{
    struct _net_db_name *x;
    struct _net_db_name *next;
    for (x = n->hosts; x; x = next) {
	next = x->next;
	netdbHashUnlink(x->name);
	safe_free(x->name);
	safe_free(x);
    }
    n->hosts = NULL;
    if (n->link_count == 0) {
	netdbHashDelete(n->network);
	xfree(n);
    }
}

static int
netdbLRU(netdbEntry ** n1, netdbEntry ** n2)
{
    if ((*n1)->last_use_time > (*n2)->last_use_time)
	return (1);
    if ((*n1)->last_use_time < (*n2)->last_use_time)
	return (-1);
    return (0);
}


static void
netdbPurgeLRU(void)
{
    netdbEntry *n;
    netdbEntry **list;
    int k = 0;
    int list_count = 0;
    int removed = 0;
    list = xcalloc(meta_data.netdb, sizeof(netdbEntry *));
    for (n = netdbGetFirst(addr_table); n; n = netdbGetNext(addr_table)) {
	*(list + list_count) = n;
	list_count++;
	if (list_count > meta_data.netdb)
	    fatal_dump("netdbPurgeLRU: list_count overflow");
    }
    qsort((char *) list,
	list_count,
	sizeof(netdbEntry *),
	(QS) netdbLRU);
    for (k = 0; k < list_count; k++) {
	if (meta_data.netdb < NETDB_LOW_MARK)
	    break;
	netdbRelease(*(list + k));
	removed++;
    }
    xfree(list);
}

static netdbEntry *
netdbLookupAddr(struct in_addr addr)
{
