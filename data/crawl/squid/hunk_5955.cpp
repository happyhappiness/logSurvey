     while ((f = (fqdncache_entry *) hash_next(fqdn_table))) {
 	ttl = (f->expires - squid_curtime);
 	storeAppendPrintf(sentry, " %-32.32s %c %6d %d",
-	    f->name,
+	    hashKeyStr(&f->hash),
 	    f->flags.negcached ? 'N' : ' ',
 	    ttl,
 	    (int) f->name_count);
