ipcache_release(ipcache_entry * i)
{
    hash_link *table_entry = NULL;

    if ((table_entry = hash_lookup(ip_table, i->name)) == NULL) {
	debug(14, 0) ("ipcache_release: Could not find key '%s'\n", i->name);
	return;
    }
    if (i != (ipcache_entry *) table_entry)
	fatal_dump("ipcache_release: i != table_entry!");
    if (i->locks) {
	i->expires = squid_curtime;
	ipcacheChangeKey(i);
