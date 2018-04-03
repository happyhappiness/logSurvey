 {
     int k;
     storeAppendPrintf(sentry, " %-32.32s  %c %6d %6d %2d(%2d)",
-	i->name,
+	hashKeyStr(&i->hash),
 	i->flags.negcached ? 'N' : ' ',
 	(int) (squid_curtime - i->lastref),
 	(int) (i->expires - squid_curtime),
