 	    break;
 	prev = m->prev;
 	i = m->data;
-	if (i->status == IP_PENDING)
-	    continue;
-	if (i->status == IP_DISPATCHED)
-	    continue;
 	if (i->locks != 0)
 	    continue;
-	ipcache_release(i);
+	ipcacheRelease(i);
 	removed++;
     }
     debug(14, 9) ("ipcache_purgelru: removed %d entries\n", removed);
 }
 
 /* create blank ipcache_entry */
 static ipcache_entry *
-ipcache_create(const char *name)
+ipcacheCreateEntry(const char *name)
 {
     static ipcache_entry *i;
     i = memAllocate(MEM_IPCACHE_ENTRY);
     i->name = xstrdup(name);
     i->expires = squid_curtime + Config.negativeDnsTtl;
-    hash_join(ip_table, (hash_link *) i);
-    dlinkAdd(i, &i->lru, &lru_list);
     return i;
 }
 
 static void
-ipcacheAddHostent(ipcache_entry * i, const struct hostent *hp)
-{
-    int addr_count = 0;
-    int k;
-    safe_free(i->addrs.in_addrs);
-    safe_free(i->addrs.bad_mask);
-    while ((addr_count < 255) && *(hp->h_addr_list + addr_count))
-	++addr_count;
-    i->addrs.count = (unsigned char) addr_count;
-    i->addrs.in_addrs = xcalloc(addr_count, sizeof(struct in_addr));
-    i->addrs.bad_mask = xcalloc(addr_count, sizeof(unsigned char));
-    i->addrs.badcount = 0;
-    for (k = 0; k < addr_count; k++)
-	xmemcpy(&i->addrs.in_addrs[k].s_addr,
-	    *(hp->h_addr_list + k),
-	    hp->h_length);
-}
-
-static ipcache_entry *
-ipcacheAddNew(const char *name, const struct hostent *hp, ipcache_status_t status)
+ipcacheAddEntry(ipcache_entry * i)
 {
-    ipcache_entry *i;
-    if (ipcache_get(name))
-	fatal_dump("ipcacheAddNew: somebody adding a duplicate!");
-    debug(14, 10) ("ipcacheAddNew: Adding '%s', status=%c\n",
-	name,
-	ipcache_status_char[status]);
-    i = ipcache_create(name);
-    if (hp)
-	ipcacheAddHostent(i, hp);
-    i->status = status;
+    hash_link *e = hash_lookup(ip_table, i->name);
+    if (NULL != e) {
+	/* avoid colission */
+	ipcache_entry *q = (ipcache_entry *) e;
+	ipcacheRelease(q);
+    }
+    hash_join(ip_table, (hash_link *) i);
+    dlinkAdd(i, &i->lru, &lru_list);
     i->lastref = squid_curtime;
-    return i;
 }
 
 /* walks down the pending list, calling handlers */
 static void
-ipcache_call_pending(ipcache_entry * i)
+ipcacheCallback(ipcache_entry * i)
 {
-    ip_pending *p = NULL;
-    int nhandler = 0;
+    IPH *handler = i->handler;
+    void *handlerData = i->handlerData;
     i->lastref = squid_curtime;
     ipcacheLockEntry(i);
-    while (i->pending_head != NULL) {
-	p = i->pending_head;
-	i->pending_head = p->next;
-	if (p->handler) {
-	    nhandler++;
-	    dns_error_message = i->error_message;
-	    if (cbdataValid(p->handlerData)) {
-		p->handler(i->status == IP_CACHED ? &i->addrs : NULL,
-		    p->handlerData);
-	    }
-	    cbdataUnlock(p->handlerData);
-	}
-	memFree(p, MEM_IPCACHE_PENDING);
+    if (NULL == handler)
+	return;
+    i->handler = NULL;
+    i->handlerData = NULL;
+    if (cbdataValid(handlerData)) {
+	dns_error_message = i->error_message;
+	handler(i->flags.negcached ? &i->addrs : NULL, handlerData);
     }
-    i->pending_head = NULL;	/* nuke list */
-    debug(14, 10) ("ipcache_call_pending: Called %d handlers.\n", nhandler);
+    cbdataUnlock(i->handlerData);
     ipcacheUnlockEntry(i);
 }
 
