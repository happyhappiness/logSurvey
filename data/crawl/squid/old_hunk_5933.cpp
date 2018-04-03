    storeAppendPrintf(sentry, "Blocking calls to gethostbyaddr(): %d\n",
	FqdncacheStats.ghba_calls);
    storeAppendPrintf(sentry, "FQDN Cache Contents:\n\n");

    hash_first(fqdn_table);
    while ((f = (fqdncache_entry *) hash_next(fqdn_table))) {
	ttl = (f->expires - squid_curtime);
	storeAppendPrintf(sentry, " %-32.32s %c %6d %d",
	    hashKeyStr(&f->hash),
	    f->flags.negcached ? 'N' : ' ',
	    ttl,
	    (int) f->name_count);
	for (k = 0; k < (int) f->name_count; k++)
