      char *name;
      int fd;
 {
-    ipcache_entry *e;
-    IpPending *p, *q;
-
-    e = ipcache_get(name);
-    if (!e) {
-	/* not found any where */
-	return 0;
-    }
-    /* look for matched fd */
-    for (q = p = e->pending_head; p; q = p, p = p->next) {
-	if (p->fd == fd) {
-	    break;
-	}
-    }
+    ipcache_entry *i = NULL;
+    struct _ip_pending *p = NULL;
+    int n = 0;
 
-    if (p == NULL) {
-	/* Can not find this ipcache_entry, weird */
-	debug(14, 1, "ipcache_unregister: Failed to unregister FD %d from name: %s, can't find this FD.\n",
-	    fd, name);
+    debug(14, 3, "ipcache_unregister: FD %d, name '%s'\n", fd, name);
+    if ((i = ipcache_get(name)) == NULL)
 	return 0;
-    }
-    /* found */
-    if (p == e->pending_head) {
-	/* it's at the head of the queue */
-	if (p->next) {
-	    /* there is something along the line */
-	    e->pending_head = p->next;
-	    safe_free(p->data);
-	    safe_free(p);
-	} else {
-	    /* it is the only entry */
-	    e->pending_head = e->pending_tail = NULL;
-	    safe_free(p->data);
-	    safe_free(p);
+    if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
+	for (p = i->pending_head; p; p = p->next) {
+	    if (p->fd == fd && p->handler != NULL) {
+		p->handler = NULL;
+		p->fd = -1;
+		n++;
+	    }
 	}
-    } else if (p == e->pending_tail) {
-	/* it's at the tail */
-	e->pending_tail = q;
-	q->next = NULL;
-	safe_free(p->data);
-	safe_free(p);
-    } else {
-	/* it's in the middle */
-	/* skip it in the list */
-	q->next = p->next;
-	safe_free(p->data);
-	safe_free(p);
     }
-    return 1;
+    debug(14, 3, "ipcache_unregister: unregistered %d handlers\n", n);
+    return n;
 }
 
-
-struct hostent *ipcache_gethostbyname(name)
+struct hostent *ipcache_gethostbyname(name, flags)
      char *name;
+     int flags;
 {
-    ipcache_entry *result;
-    unsigned int a1, a2, a3, a4;
-    struct hostent *s_result = NULL;
-
-    if (!name) {
-	debug(14, 5, "ipcache_gethostbyname: Invalid argument?\n");
-	return (NULL);
-    }
-    if (!(result = ipcache_get(name))) {
-	/* cache miss */
-	if (name) {
-	    debug(14, 5, "ipcache_gethostbyname: IPcache miss for '%s'.\n", name);
-	}
-	/* check if it's already a IP address in text form. */
-	if (sscanf(name, "%u.%u.%u.%u", &a1, &a2, &a3, &a4) == 4) {
-	    *((unsigned long *) (void *) static_result->h_addr_list[0]) = inet_addr(name);
-	    strncpy(static_result->h_name, name, MAX_HOST_NAME);
-	    return static_result;
+    ipcache_entry *i = NULL;
+    struct hostent *hp = NULL;
+    unsigned int ip;
+
+    if (!name)
+	fatal_dump("ipcache_gethostbyname: NULL name");
+    IpcacheStats.requests++;
+    if ((i = ipcache_get(name))) {
+	if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
+	    IpcacheStats.pending_hits++;
+	    return NULL;
+	} else if (i->status == IP_NEGATIVE_CACHED) {
+	    IpcacheStats.negative_hits++;
+	    dns_error_message = i->error_message;
+	    return NULL;
 	} else {
-	    s_result = gethostbyname(name);
+	    IpcacheStats.hits++;
+	    i->lastref = squid_curtime;
+	    return &i->entry;
 	}
-
-	if (s_result && s_result->h_name && (s_result->h_name[0] != '\0')) {
+    }
+    IpcacheStats.misses++;
+    /* check if it's already a IP address in text form. */
+    if ((ip = inet_addr(name)) != INADDR_NONE) {
+	*((u_num32 *) (void *) static_result->h_addr_list[0]) = ip;
+	strncpy(static_result->h_name, name, MAX_HOST_NAME);
+	return static_result;
+    }
+    if (flags & IP_BLOCKING_LOOKUP) {
+	IpcacheStats.ghbn_calls++;
+	hp = gethostbyname(name);
+	if (hp && hp->h_name && (hp->h_name[0] != '\0') && ip_table) {
 	    /* good address, cached */
-	    debug(14, 10, "ipcache_gethostbyname: DNS success: cache for '%s'.\n", name);
-	    ipcache_add(name, ipcache_create(), s_result, 1);
-	    result = ipcache_get(name);
-	    return &(result->entry);
-	} else {
-	    /* bad address, negative cached */
-	    debug(14, 3, "ipcache_gethostbyname: DNS failure: negative cache for '%s'.\n", name);
-	    ipcache_add(name, ipcache_create(), s_result, 0);
-	    return NULL;
+	    ipcache_add(name, ipcache_create(), hp, 1);
+	    i = ipcache_get(name);
+	    return &i->entry;
 	}
-
+	/* bad address, negative cached */
+	if (ip_table)
+	    ipcache_add(name, ipcache_create(), hp, 0);
+	return NULL;
     }
-    /* cache hit */
-    debug(14, 5, "ipcache_gethostbyname: Hit for '%s'.\n", name ? name : "NULL");
-    result->lastref = squid_curtime;
-    return (result->status == CACHED) ? &(result->entry) : NULL;
+    if (flags & IP_LOOKUP_IF_MISS)
+	ipcache_nbgethostbyname(name, -1, dummy_handler, NULL);
+    return NULL;
 }
 
 
-
 /* process objects list */
-void stat_ipcache_get(sentry, obj)
+void stat_ipcache_get(sentry)
      StoreEntry *sentry;
-     cacheinfo *obj;
 {
-    char buffer[MAX_LINELEN];
-    ipcache_entry *e = NULL;
-    int i;
+    ipcache_entry *i = NULL;
+    int k;
     int ttl;
-    char status;
-
-    sprintf(buffer, "{IP Cache Contents:\n\n");
-    storeAppend(sentry, buffer, strlen(buffer));
-
-    for (e = ipcache_GetFirst(); (e); e = ipcache_GetNext()) {
-	if (e) {
-	    ttl = (e->ttl - squid_curtime + e->lastref);
-	    status = ipcache_status_char(e);
-	    if (status == 'P')
-		ttl = 0;
-
-	    sprintf(buffer, " {%s %c %d %d",
-		e->name, status, ttl, e->addr_count);
-	    storeAppend(sentry, buffer, strlen(buffer));
-
-	    for (i = 0; i < (int) e->addr_count; i++) {
-		struct in_addr addr;
-		memcpy((char *) &addr, e->entry.h_addr_list[i], e->entry.h_length);
 
-		sprintf(buffer, " %s", inet_ntoa(addr));
-		storeAppend(sentry, buffer, strlen(buffer));
-	    }
-	    for (i = 0; i < (int) e->alias_count; i++) {
-		sprintf(buffer, " %s", e->entry.h_aliases[i]);
-		storeAppend(sentry, buffer, strlen(buffer));
-	    }
-	    if (e->entry.h_name && strncmp(e->name, e->entry.h_name, MAX_LINELEN)) {
-		sprintf(buffer, " %s", e->entry.h_name);
-		storeAppend(sentry, buffer, strlen(buffer));
-	    }
-	    sprintf(buffer, "}\n");
-	    storeAppend(sentry, buffer, strlen(buffer));
-	}
-    }
-    sprintf(buffer, "}\n");
-    storeAppend(sentry, buffer, strlen(buffer));
-
-}
+    if (!ip_table)
+	return;
 
-char ipcache_status_char(e)
-     ipcache_entry *e;
-{
-    switch (e->status) {
-    case CACHED:
-	return ('C');
-    case PENDING:
-	return ('P');
-    case NEGATIVE_CACHED:
-	return ('N');
-    default:
-	debug(14, 1, "ipcache_status_char: unexpected IP cache status.\n");
+    storeAppendPrintf(sentry, "{IP Cache Statistics:\n");
+    storeAppendPrintf(sentry, "{IPcache Entries: %d}\n",
+	meta_data.ipcache_count);
+    storeAppendPrintf(sentry, "{IPcache Requests: %d}\n",
+	IpcacheStats.requests);
+    storeAppendPrintf(sentry, "{IPcache Hits: %d}\n",
+	IpcacheStats.hits);
+    storeAppendPrintf(sentry, "{IPcache Pending Hits: %d}\n",
+	IpcacheStats.pending_hits);
+    storeAppendPrintf(sentry, "{IPcache Negative Hits: %d}\n",
+	IpcacheStats.negative_hits);
+    storeAppendPrintf(sentry, "{IPcache Misses: %d}\n",
+	IpcacheStats.misses);
+    storeAppendPrintf(sentry, "{Blocking calls to gethostbyname(): %d}\n",
+	IpcacheStats.ghbn_calls);
+    storeAppendPrintf(sentry, "{dnsserver requests: %d}\n",
+	IpcacheStats.dnsserver_requests);
+    storeAppendPrintf(sentry, "{dnsserver replies: %d}\n",
+	IpcacheStats.dnsserver_replies);
+    storeAppendPrintf(sentry, "{dnsserver avg service time: %d msec}\n",
+	IpcacheStats.avg_svc_time);
+    storeAppendPrintf(sentry, "{number of dnsservers: %d}\n",
+	getDnsChildren());
+    storeAppendPrintf(sentry, "{dnsservers use histogram:}\n");
+    for (k = 0; k < getDnsChildren(); k++) {
+	storeAppendPrintf(sentry, "{    dnsserver #%d: %d}\n",
+	    k + 1,
+	    IpcacheStats.dnsserver_hist[k]);
     }
-    return ('X');
-}
-
-int ipcache_hash_entry_count()
-{
-    ipcache_entry *e;
-    int local_ip_count = 0;
-
-    e = NULL;
-
-    for (e = ipcache_GetFirst(); e; e = ipcache_GetNext()) {
-	local_ip_count++;
+    storeAppendPrintf(sentry, "}\n\n");
+    storeAppendPrintf(sentry, "{IP Cache Contents:\n\n");
+
+    for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
+	if (i->status == IP_PENDING || i->status == IP_DISPATCHED)
+	    ttl = 0;
+	else
+	    ttl = (i->ttl - squid_curtime + i->lastref);
+	storeAppendPrintf(sentry, " {%-32.32s %c%c %6d %d",
+	    i->name,
+	    ipcache_status_char[i->status],
+	    i->lock ? 'L' : ' ',
+	    ttl,
+	    i->addr_count);
+	for (k = 0; k < (int) i->addr_count; k++) {
+	    struct in_addr addr;
+	    xmemcpy(&addr, i->entry.h_addr_list[k], i->entry.h_length);
+	    storeAppendPrintf(sentry, " %15s", inet_ntoa(addr));
+	}
+	for (k = 0; k < (int) i->alias_count; k++) {
+	    storeAppendPrintf(sentry, " %s", i->entry.h_aliases[k]);
+	}
+	if (i->entry.h_name && strncmp(i->name, i->entry.h_name, MAX_LINELEN)) {
+	    storeAppendPrintf(sentry, " %s", i->entry.h_name);
+	}
+	storeAppendPrintf(sentry, close_bracket);
     }
-
-    return local_ip_count;
+    storeAppendPrintf(sentry, close_bracket);
 }
 
 void ipcacheShutdownServers()
 {
-    dnsserver_entry *dns = NULL;
-    int i;
+    dnsserver_t *dnsData = NULL;
+    int k;
     static char *shutdown = "$shutdown\n";
 
     debug(14, 3, "ipcacheShutdownServers:\n");
 
-    for (i = 0; i < getDnsChildren(); i++) {
-	dns = *(dns_child_table + i);
-	debug(14, 3, "ipcacheShutdownServers: sending '$shutdown' to dnsserver #%d\n", i);
-	debug(14, 3, "ipcacheShutdownServers: --> FD %d\n", dns->outpipe);
-	file_write(dns->outpipe,
+    for (k = 0; k < getDnsChildren(); k++) {
+	dnsData = *(dns_child_table + k);
+	if (!(dnsData->flags & DNS_FLAG_ALIVE))
+	    continue;
+	if (dnsData->flags & DNS_FLAG_BUSY)
+	    continue;
+	if (dnsData->flags & DNS_FLAG_CLOSING)
+	    continue;
+	debug(14, 3, "ipcacheShutdownServers: sending '$shutdown' to dnsserver #%d\n", dnsData->id);
+	debug(14, 3, "ipcacheShutdownServers: --> FD %d\n", dnsData->outpipe);
+	comm_write(dnsData->outpipe,
 	    xstrdup(shutdown),
 	    strlen(shutdown),
-	    0,			/* Lock */
-	    0,			/* Handler */
-	    0);			/* Handler-data */
+	    0,			/* timeout */
+	    NULL,		/* Handler */
+	    NULL);		/* Handler-data */
+	dnsData->flags |= DNS_FLAG_CLOSING;
     }
 }
+
+static int dummy_handler(u1, u2, u3)
+     int u1;
+     struct hostent *u2;
+     void *u3;
+{
+    return 0;
+}
+
+void ipcacheLockEntry(name)
+     char *name;
+{
+    ipcache_entry *i;
+    if ((i = ipcache_get(name)) == NULL)
+	return;
+    i->lock++;
+}
+
+static int ipcacheHasPending(i)
+     ipcache_entry *i;
+{
+    struct _ip_pending *p = NULL;
+    if (i->status != IP_PENDING)
+	return 0;
+    for (p = i->pending_head; p; p = p->next)
+	if (p->handler)
+	    return 1;
+    return 0;
+}
