    xfree(list);
    hashFreeMemory(fqdn_table);
}

static void
fqdncacheChangeKey(fqdncache_entry * f)
{
    static int index = 0;
    LOCAL_ARRAY(char, new_key, 256);
    hash_link *table_entry = hash_lookup(fqdn_table, f->name);
    if (table_entry == NULL) {
	debug(14, 0, "fqdncacheChangeKey: Could not find key '%s'\n", f->name);
	return;
    }
    if (f != (fqdncache_entry *) table_entry) {
	debug_trap("fqdncacheChangeKey: f != table_entry!");
	return;
    }
    if (hash_remove_link(fqdn_table, table_entry)) {
	debug_trap("fqdncacheChangeKey: hash_remove_link() failed\n");
	return;
    }
    sprintf(new_key, "%d/", ++index);
    strncat(new_key, f->name, 128);
    debug(14, 1, "fqdncacheChangeKey: from '%s' to '%s'\n", f->name, new_key);
    safe_free(f->name);
    f->name = xstrdup(new_key);
    fqdncache_add_to_hash(f);
}

/* call during reconfigure phase to clear out all the
 * pending and dispatched reqeusts that got lost */
void
fqdncache_restart(void)
{
    fqdncache_entry *this;
    fqdncache_entry *next;
    if (fqdn_table == 0)
	fatal_dump("fqdncache_restart: fqdn_table == 0\n");
    while (fqdncacheDequeue());
    next = (fqdncache_entry *) hash_first(fqdn_table);
    while ((this = next)) {
	next = (fqdncache_entry *) hash_next(fqdn_table);
	if (this->status == FQDN_CACHED)
	    continue;
	if (this->status == FQDN_NEGATIVE_CACHED)
	    continue;
	/* else its PENDING or DISPATCHED; there are no dnsservers
	 * running, so abort it */
	this->status = FQDN_NEGATIVE_CACHED;
	fqdncache_release(this);
    }
}
