     storeAppendPrintf(sentry, "Blocking calls to gethostbyaddr(): %d\n",
 	FqdncacheStats.ghba_calls);
     storeAppendPrintf(sentry, "FQDN Cache Contents:\n\n");
-
+    storeAppendPrintf(sentry, "%-15.15s %3s %3s %3s %s\n",
+	"Address", "Flg", "TTL", "Cnt", "Hostnames");
     hash_first(fqdn_table);
     while ((f = (fqdncache_entry *) hash_next(fqdn_table))) {
-	ttl = (f->expires - squid_curtime);
-	storeAppendPrintf(sentry, " %-32.32s %c %6d %d",
+	ttl = (f->flags.fromhosts ? -1 : (f->expires - squid_curtime));
+	storeAppendPrintf(sentry, "%-15.15s  %c%c %3.3d % 3d",
 	    hashKeyStr(&f->hash),
 	    f->flags.negcached ? 'N' : ' ',
+	    f->flags.fromhosts ? 'H' : ' ',
 	    ttl,
 	    (int) f->name_count);
 	for (k = 0; k < (int) f->name_count; k++)
