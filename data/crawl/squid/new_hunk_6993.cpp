	fatal_dump("fqdncache_restart: fqdn_table == 0\n");
    while (fqdncacheDequeue());
    next = (fqdncache_entry *) hash_first(fqdn_table);
    while ((this = next) != NULL) {
	next = (fqdncache_entry *) hash_next(fqdn_table);
	if (this->status == FQDN_CACHED)
	    continue;
