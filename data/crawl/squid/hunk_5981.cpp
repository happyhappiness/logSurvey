 
     hash_first(fqdn_table);
     while ((f = (fqdncache_entry *) hash_next(fqdn_table))) {
-	if (f->status == FQDN_PENDING || f->status == FQDN_DISPATCHED)
-	    ttl = 0;
-	else
-	    ttl = (f->expires - squid_curtime);
+	ttl = (f->expires - squid_curtime);
 	storeAppendPrintf(sentry, " %-32.32s %c %6d %d",
 	    f->name,
-	    fqdncache_status_char[f->status],
+	    f->flags.negcached ? 'N' : ' ',
 	    ttl,
 	    (int) f->name_count);
 	for (k = 0; k < (int) f->name_count; k++)
