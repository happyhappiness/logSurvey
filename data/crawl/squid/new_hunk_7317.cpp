    }
    if (i != (ipcache_entry *) table_entry)
	fatal_dump("ipcache_release: i != table_entry!");
    if (i->locks) {
	i->expires = squid_curtime;
	IpcacheStats.release_locked++;
	return;
    }
    if (hash_remove_link(ip_table, table_entry)) {
