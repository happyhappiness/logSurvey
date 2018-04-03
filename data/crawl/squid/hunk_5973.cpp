 
 /* removes the given ipcache entry */
 static void
-ipcache_release(ipcache_entry * i)
+ipcacheRelease(ipcache_entry * i)
 {
-    hash_link *table_entry = NULL;
-    if ((table_entry = hash_lookup(ip_table, i->name)) == NULL) {
-	snprintf(tmp_error_buf, ERROR_BUF_SZ, "ipcache_release: key '%s' not found\n", i->name);
-	fatal_dump(tmp_error_buf);
-    }
-    assert(i == (ipcache_entry *) table_entry);
-    if (i->locks) {
-	i->expires = squid_curtime;
-	ipcacheChangeKey(i);
-	IpcacheStats.release_locked++;
-	return;
-    }
-    hash_remove_link(ip_table, table_entry);
+    hash_remove_link(ip_table, (hash_link *) i);
     dlinkDelete(&i->lru, &lru_list);
-    if (i->status == IP_CACHED) {
-	safe_free(i->addrs.in_addrs);
-	safe_free(i->addrs.bad_mask);
-	debug(14, 5) ("ipcache_release: Released IP cached record for '%s'.\n",
-	    i->name);
-    }
-    safe_free(i->name);
-    safe_free(i->error_message);
-    memFree(i, MEM_IPCACHE_ENTRY);
-    return;
+    ipcacheFreeEntry(i);
 }
 
 static ipcache_entry *
 ipcache_get(const char *name)
 {
-    assert(ip_table != NULL);
-    return (ipcache_entry *) hash_lookup(ip_table, name);
+    if (ip_table != NULL)
+	return (ipcache_entry *) hash_lookup(ip_table, name);
+    else
+	return NULL;
 }
 
 static int
 ipcacheExpiredEntry(ipcache_entry * i)
 {
-    if (i->status == IP_PENDING)
-	return 0;
-    if (i->status == IP_DISPATCHED)
-	return 0;
     if (i->locks != 0)
 	return 0;
     if (i->addrs.count == 0)
-	if (i->status != IP_NEGATIVE_CACHED)
+	if (0 == i->flags.negcached)
 	    return 1;
     if (i->expires > squid_curtime)
 	return 0;
