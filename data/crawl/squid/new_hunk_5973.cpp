
/* removes the given ipcache entry */
static void
ipcacheRelease(ipcache_entry * i)
{
    hash_remove_link(ip_table, (hash_link *) i);
    dlinkDelete(&i->lru, &lru_list);
    ipcacheFreeEntry(i);
}

static ipcache_entry *
ipcache_get(const char *name)
{
    if (ip_table != NULL)
	return (ipcache_entry *) hash_lookup(ip_table, name);
    else
	return NULL;
}

static int
ipcacheExpiredEntry(ipcache_entry * i)
{
    if (i->locks != 0)
	return 0;
    if (i->addrs.count == 0)
	if (0 == i->flags.negcached)
	    return 1;
    if (i->expires > squid_curtime)
	return 0;
