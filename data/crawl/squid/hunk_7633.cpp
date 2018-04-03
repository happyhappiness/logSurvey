 	}
     }
     IpcacheStats.misses++;
-    /* check if it's already a IP address in text form. */
-    if ((ip = inet_addr(name)) != INADDR_NONE) {
-	*((u_num32 *) (void *) (*static_result->h_addr_list + 0)) = ip;
-	strncpy(static_result->h_name, name, MAX_HOST_NAME);
-	return static_result;
-    }
+    if ((hp = ipcacheCheckNumeric(name)))
+	return hp;
     if (flags & IP_BLOCKING_LOOKUP) {
 	IpcacheStats.ghbn_calls++;
 	hp = gethostbyname(name);
 	if (hp && hp->h_name && (hp->h_name[0] != '\0') && ip_table) {
 	    /* good address, cached */
 	    ipcache_add(name, ipcache_create(), hp, 1);
 	    i = ipcache_get(name);
+	    i->lastref = squid_curtime;
+	    i->expires = squid_curtime + Config.positiveDnsTtl;
 	    return &i->entry;
 	}
 	/* bad address, negative cached */
-	if (ip_table)
+	if (ip_table) {
 	    ipcache_add(name, ipcache_create(), hp, 0);
-	return NULL;
+	    i = ipcache_get(name);
+	    i->lastref = squid_curtime;
+	    i->expires = squid_curtime + Config.negativeDnsTtl;
+	    return NULL;
+	}
     }
     if (flags & IP_LOOKUP_IF_MISS)
 	ipcache_nbgethostbyname(name, -1, dummy_handler, NULL);
     return NULL;
 }
 
+static void ipcacheStatPrint(i, sentry)
+     ipcache_entry *i;
+     StoreEntry *sentry;
+{
+    int k;
+    storeAppendPrintf(sentry, " {%-32.32s  %c %6d %6d %d",
+	i->name,
+	ipcache_status_char[i->status],
+	(int) (squid_curtime - i->lastref),
+	(int) (i->expires - squid_curtime),
+	i->addr_count);
+    for (k = 0; k < (int) i->addr_count; k++) {
+	struct in_addr addr;
+	xmemcpy(&addr, i->entry.h_addr_list[k], i->entry.h_length);
+	storeAppendPrintf(sentry, " %15s", inet_ntoa(addr));
+    }
+    for (k = 0; k < (int) i->alias_count; k++) {
+	storeAppendPrintf(sentry, " %s", i->entry.h_aliases[k]);
+    }
+    if (i->entry.h_name && strncmp(i->name, i->entry.h_name, MAX_LINELEN)) {
+	storeAppendPrintf(sentry, " %s", i->entry.h_name);
+    }
+    storeAppendPrintf(sentry, close_bracket);
+}
 
 /* process objects list */
 void stat_ipcache_get(sentry)
      StoreEntry *sentry;
 {
-    ipcache_entry *i = NULL;
     int k;
-    int ttl;
-
+    int N;
+    ipcache_entry *i = NULL;
+    ipcache_entry **list = NULL;
     if (!ip_table)
 	return;
-
     storeAppendPrintf(sentry, "{IP Cache Statistics:\n");
     storeAppendPrintf(sentry, "{IPcache Entries: %d}\n",
 	meta_data.ipcache_count);
