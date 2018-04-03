
    storeAppendPrintf(sentry, "FQDN Cache Contents:\n\n");

    storeAppendPrintf(sentry, "%-15.15s %3s %3s %3s %s\n",
                      "Address", "Flg", "TTL", "Cnt", "Hostnames");

    hash_first(fqdn_table);

    while ((f = (fqdncache_entry *) hash_next(fqdn_table))) {
        ttl = (f->flags.fromhosts ? -1 : (f->expires - squid_curtime));
        storeAppendPrintf(sentry, "%-15.15s  %c%c %3.3d % 3d",
                          hashKeyStr(&f->hash),
                          f->flags.negcached ? 'N' : ' ',
                          f->flags.fromhosts ? 'H' : ' ',
