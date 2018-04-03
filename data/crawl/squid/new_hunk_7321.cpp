	debug_trap("ipcacheChangeKey: hash_remove_link() failed\n");
	return;
    }
    sprintf(new_key, "%d/", ++index);
    strncat(new_key, i->name, 128);
    debug(14, 1, "ipcacheChangeKey: from '%s' to '%s'\n", i->name, new_key);
    safe_free(i->name);
    i->name = xstrdup(new_key);
    ipcache_add_to_hash(i);
}

/* call during reconfigure phase to clear out all the 
 * pending and dispatched reqeusts that got lost */
void
ipcache_restart(void)
{
    ipcache_entry *this;
    ipcache_entry *next;
    if (ip_table == 0)
	fatal_dump("ipcache_restart: ip_table == 0\n");
    while (ipcacheDequeue());
    next = (ipcache_entry *) hash_first(ip_table);
    while ((this = next)) {
	next = (ipcache_entry *) hash_next(ip_table);
	if (this->status == IP_CACHED)
	    continue;
	if (this->status == IP_NEGATIVE_CACHED)
	    continue;
	/* else its PENDING or DISPATCHED; there are no dnsservers
	 * running, so abort it */
	this->status = IP_NEGATIVE_CACHED;
	ipcache_release(this);
    }
    /* recalculate these while we're at it */
    ipcache_high = (long) (((float) Config.ipcache.size *
	    (float) Config.ipcache.high) / (float) 100);
    ipcache_low = (long) (((float) Config.ipcache.size *
	    (float) Config.ipcache.low) / (float) 100);
}
