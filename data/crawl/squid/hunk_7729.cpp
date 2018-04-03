 }
 
 
-int ipcache_dnsHandleRead(fd, data)
+static int ipcache_dnsHandleRead(fd, dnsData)
      int fd;
-     dnsserver_entry *data;
+     dnsserver_t *dnsData;
 {
     int char_scanned;
-    int len = read(fd, data->ip_inbuf + data->offset, data->size - data->offset);
-
-    debug(14, 5, "ipcache_dnsHandleRead: Result from DNS ID %d.\n", data->id);
-
-    if (len == 0) {
-	debug(14, 1, "ipcache_dnsHandleRead: Connection from DNSSERVER is closed.\n");
-	debug(14, 1, "                       Disabling this server ID %d.\n", data->id);
-	data->alive = 0;
-	update_dns_child_alive();
-	ipcache_cleanup_pendinglist(data);
-	close(fd);
-	fdstat_close(fd);
+    int len;
+    int svc_time;
+    int n;
+    ipcache_entry *i = NULL;
+
+    len = read(fd,
+	dnsData->ip_inbuf + dnsData->offset,
+	dnsData->size - dnsData->offset);
+    debug(14, 5, "ipcache_dnsHandleRead: Result from DNS ID %d (%d bytes)\n",
+	dnsData->id, len);
+    if (len <= 0) {
+	debug(14, dnsData->flags & DNS_FLAG_CLOSING ? 5 : 1,
+	    "FD %d: Connection from DNSSERVER #%d is closed, disabling\n",
+	    fd, dnsData->id);
+	dnsData->flags = 0;
+	comm_set_select_handler(fd,
+	    COMM_SELECT_WRITE,
+	    NULL,
+	    NULL);
+	comm_close(fd);
 	return 0;
     }
-    data->offset += len;
-    data->ip_inbuf[data->offset] = '\0';
+    n = ++IpcacheStats.dnsserver_replies;
+    dnsData->offset += len;
+    dnsData->ip_inbuf[dnsData->offset] = '\0';
 
-    if (strstr(data->ip_inbuf, "$end\n")) {
+    if (strstr(dnsData->ip_inbuf, "$end\n")) {
 	/* end of record found */
-	char_scanned = ipcache_parsebuffer(data->ip_inbuf, data->offset, data);
+	svc_time = tvSubMsec(dnsData->dispatch_time, current_time);
+	if (n > IPCACHE_AV_FACTOR)
+	    n = IPCACHE_AV_FACTOR;
+	IpcacheStats.avg_svc_time
+	    = (IpcacheStats.avg_svc_time * (n - 1) + svc_time) / n;
+	char_scanned = ipcache_parsebuffer(dnsData->ip_inbuf,
+	    dnsData->offset,
+	    dnsData);
 	if (char_scanned > 0) {
 	    /* update buffer */
-	    memcpy(data->ip_inbuf, data->ip_inbuf + char_scanned, data->offset - char_scanned);
-	    data->offset -= char_scanned;
-	    data->ip_inbuf[data->offset] = '\0';
+	    xmemcpy(dnsData->ip_inbuf,
+		dnsData->ip_inbuf + char_scanned,
+		dnsData->offset - char_scanned);
+	    dnsData->offset -= char_scanned;
+	    dnsData->ip_inbuf[dnsData->offset] = '\0';
 	}
     }
+    if (dnsData->offset == 0) {
+	dnsData->ip_entry = NULL;
+	dnsData->flags &= ~DNS_FLAG_BUSY;
+    }
     /* reschedule */
-    comm_set_select_handler(data->inpipe, COMM_SELECT_READ,
-	(PF) ipcache_dnsHandleRead, (void *) data);
+    comm_set_select_handler(dnsData->inpipe,
+	COMM_SELECT_READ,
+	(PF) ipcache_dnsHandleRead,
+	dnsData);
+    while ((dnsData = dnsGetFirstAvailable()) && (i = dnsDequeue()))
+	dnsDispatch(dnsData, i);
     return 0;
 }
 
-int ipcache_nbgethostbyname(name, fd, handler, data)
+static void ipcacheAddPending(i, fd, handler, handlerData)
+     ipcache_entry *i;
+     int fd;
+     IPH handler;
+     void *handlerData;
+{
+    struct _ip_pending *pending = xcalloc(1, sizeof(struct _ip_pending));
+    struct _ip_pending **I = NULL;
+
+    pending->fd = fd;
+    pending->handler = handler;
+    pending->handlerData = handlerData;
+
+    for (I = &(i->pending_head); *I; I = &((*I)->next));
+    *I = pending;
+}
+
+int ipcache_nbgethostbyname(name, fd, handler, handlerData)
      char *name;
      int fd;
      IPH handler;
-     void *data;
+     void *handlerData;
 {
-    ipcache_entry *e;
-    IpPending *pending;
-    dnsserver_entry *dns;
+    ipcache_entry *i = NULL;
+    dnsserver_t *dnsData = NULL;
+
+    if (!handler)
+	fatal_dump("ipcache_nbgethostbyname: NULL handler");
 
     debug(14, 4, "ipcache_nbgethostbyname: FD %d: Name '%s'.\n", fd, name);
+    IpcacheStats.requests++;
 
     if (name == NULL || name[0] == '\0') {
 	debug(14, 4, "ipcache_nbgethostbyname: Invalid name!\n");
-	ipcache_call_pending_badname(fd, handler, data);
+	ipcache_call_pending_badname(fd, handler, handlerData);
 	return 0;
     }
-    if ((e = ipcache_get(name)) != NULL && (e->status != PENDING)) {
-	/* hit here */
-	debug(14, 4, "ipcache_nbgethostbyname: Hit for name '%s'.\n", name);
-	pending = (IpPending *) xcalloc(1, sizeof(IpPending));
-	pending->fd = fd;
-	pending->handler = handler;
-	pending->data = data;
-	pending->next = NULL;
-	if (e->pending_head == NULL) {	/* empty list */
-	    e->pending_head = e->pending_tail = pending;
-	} else {		/* add to tail of list */
-	    e->pending_tail->next = pending;
-	    e->pending_tail = e->pending_tail->next;
+    if ((i = ipcache_get(name))) {
+	if (ipcacheExpiredEntry(i)) {
+	    ipcache_release(i);
+	    i = NULL;
 	}
-	ipcache_call_pending(e);
-	return 0;
     }
-    debug(14, 4, "ipcache_nbgethostbyname: Name '%s': MISS or PENDING.\n", name);
-
-    pending = (IpPending *) xcalloc(1, sizeof(IpPending));
-    pending->fd = fd;
-    pending->handler = handler;
-    pending->data = data;
-    pending->next = NULL;
-    if (e == NULL) {
-	/* No entry, create the new one */
-	debug(14, 5, "ipcache_nbgethostbyname: Creating new entry for '%s'...\n",
-	    name);
-	e = ipcache_create();
-	e->name = xstrdup(name);
-	e->status = PENDING;
-	e->pending_tail = e->pending_head = pending;
-	ipcache_add_to_hash(e);
-    } else {
-	/* There is an entry. Add handler to list */
-	debug(14, 5, "ipcache_nbgethostbyname: Adding handler to pending list for '%s'.\n", name);
-	if (e->pending_head == NULL) {	/* empty list */
-	    e->pending_head = e->pending_tail = pending;
-	} else {		/* add to tail of list */
-	    e->pending_tail->next = pending;
-	    e->pending_tail = e->pending_tail->next;
-	}
+    if (i == NULL) {
+	/* MISS: No entry, create the new one */
+	debug(14, 5, "ipcache_nbgethostbyname: MISS for '%s'\n", name);
+	IpcacheStats.misses++;
+	i = ipcache_create();
+	i->name = xstrdup(name);
+	i->status = IP_PENDING;
+	ipcacheAddPending(i, fd, handler, handlerData);
+	ipcache_add_to_hash(i);
+    } else if (i->status == IP_CACHED || i->status == IP_NEGATIVE_CACHED) {
+	/* HIT */
+	debug(14, 4, "ipcache_nbgethostbyname: HIT for '%s'\n", name);
+	if (i->status == IP_NEGATIVE_CACHED)
+	    IpcacheStats.negative_hits++;
+	else
+	    IpcacheStats.hits++;
+	ipcacheAddPending(i, fd, handler, handlerData);
+	ipcache_call_pending(i);
 	return 0;
+    } else if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
+	debug(14, 4, "ipcache_nbgethostbyname: PENDING for '%s'\n", name);
+	IpcacheStats.pending_hits++;
+	ipcacheAddPending(i, fd, handler, handlerData);
+	return 0;
+    } else {
+	fatal_dump("ipcache_nbgethostbyname: BAD ipcache_entry status");
     }
 
-    if (dns_child_alive) {
-	int i, j, min_dns = 0, min_count = 255, alive = 0;
-
-	j = last_dns_dispatched;
-	/* select DNS server with the lowest number of pending */
-	for (i = 0; i < getDnsChildren(); ++i) {
-	    j += 1;
-	    j %= getDnsChildren();
-	    if ((dns_child_table[j]->alive) &&
-		(dns_child_table[j]->pending_count < min_count)) {
-		min_dns = j;
-		min_count = dns_child_table[j]->pending_count;
-	    }
-	    alive = dns_child_table[j]->alive | alive;
-	}
+    /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we continue */
 
-	if (alive == 0) {
-	    dns_child_alive = 0;	/* all dead */
-	    last_dns_dispatched = 0;	/* use entry 0 */
-	} else {
-	    last_dns_dispatched = min_dns;
+    if ((dnsData = dnsGetFirstAvailable()))
+	dnsDispatch(dnsData, i);
+    else
+	dnsEnqueue(i);
+    return 0;
+}
+
+static void dnsEnqueue(i)
+     ipcache_entry *i;
+{
+    struct dnsQueueData *new = xcalloc(1, sizeof(struct dnsQueueData));
+    new->ip_entry = i;
+    *dnsQueueTailP = new;
+    dnsQueueTailP = &new->next;
+}
+
+static ipcache_entry *dnsDequeue()
+{
+    struct dnsQueueData *old = NULL;
+    ipcache_entry *i = NULL;
+    if (dnsQueueHead) {
+	i = dnsQueueHead->ip_entry;
+	old = dnsQueueHead;
+	dnsQueueHead = dnsQueueHead->next;
+	if (dnsQueueHead == NULL)
+	    dnsQueueTailP = &dnsQueueHead;
+	safe_free(old);
+    }
+#ifdef SANITY_CHECK
+    if (i == NULL) {
+	for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
+	    if (i->status == IP_PENDING) {	/* This can't happen */
+		debug(14, 0, "IP Cache inconsistency: %s still pending\n",
+		    i->name);
+	    }
 	}
-    } else {
-	last_dns_dispatched = 0;
+	i = NULL;
     }
+#endif
+    return i;
+}
 
-    dns = dns_child_table[last_dns_dispatched];
-    debug(14, 5, "ipcache_nbgethostbyname: Dispatched DNS %d.\n",
-	last_dns_dispatched);
-
-    /* add to global pending list */
-    if (dns->global_pending == NULL) {	/* new list */
-	dns->global_pending = (ipcache_list *) xcalloc(1, sizeof(ipcache_list));
-	dns->global_pending->entry = e;
-	dns->global_pending->next = NULL;
-	dns->global_pending_tail = dns->global_pending;
-    } else {			/* add to end of list */
-	ipcache_list *p = (ipcache_list *) xcalloc(1, sizeof(ipcache_list));
-	p->entry = e;
-	p->next = NULL;
-	dns->global_pending_tail->next = p;
-	dns->global_pending_tail = dns->global_pending_tail->next;
+static dnsserver_t *dnsGetFirstAvailable()
+{
+    int k;
+    dnsserver_t *dns = NULL;
+    for (k = 0; k < NDnsServersAlloc; k++) {
+	dns = *(dns_child_table + k);
+	if (!(dns->flags & DNS_FLAG_BUSY))
+	    return dns;
     }
+    return NULL;
+}
 
-    if (dns_child_alive) {
-	char *buf = (char *) xcalloc(1, 256);
-	strncpy(buf, name, 254);
-	strcat(buf, "\n");
-	dns->pending_count++;
-	file_write(dns->outpipe,
-	    buf,
-	    strlen(buf),
-	    0,			/* Lock */
-	    0,			/* Handler */
-	    0);			/* Handler-data */
-
-	debug(14, 5, "ipcache_nbgethostbyname: Request sent DNS server ID %d.\n", last_dns_dispatched);
-    } else {
-	/* do a blocking mode */
-	debug(14, 4, "ipcache_nbgethostbyname: Fall back to blocking mode.  Server's dead...\n");
-	ipcache_cleanup_pendinglist(dns);
+static void dnsDispatch(dns, i)
+     dnsserver_t *dns;
+     ipcache_entry *i;
+{
+    char *buf = NULL;
+    if (!ipcacheHasPending(i)) {
+	debug(14, 0, "dnsDispatch: skipping '%s' because no handler.\n",
+	    i->name);
+	i->status = IP_NEGATIVE_CACHED;
+	ipcache_release(i);
+	return;
     }
-    return 0;
+    i->status = IP_DISPATCHED;
+    buf = xcalloc(1, 256);
+    sprintf(buf, "%1.254s\n", i->name);
+    dns->flags |= DNS_FLAG_BUSY;
+    dns->ip_entry = i;
+    comm_write(dns->outpipe,
+	buf,
+	strlen(buf),
+	0,			/* timeout */
+	NULL,			/* Handler */
+	NULL);			/* Handler-data */
+    debug(14, 5, "dnsDispatch: Request sent to DNS server #%d.\n",
+	dns->id);
+    dns->dispatch_time = current_time;
+    IpcacheStats.dnsserver_requests++;
+    IpcacheStats.dnsserver_hist[dns->id - 1]++;
 }
 
 
 void ipcacheOpenServers()
 {
     int N = getDnsChildren();
     char *prg = getDnsProgram();
-    int i;
+    int k;
     int dnssocket;
     static char fd_note_buf[FD_ASCII_NOTE_SZ];
-    static int NChildrenAlloc = 0;
 
     /* free old structures if present */
     if (dns_child_table) {
-	for (i = 0; i < NChildrenAlloc; i++)
-	    safe_free(dns_child_table[i]->ip_inbuf);
+	for (k = 0; k < NDnsServersAlloc; k++) {
+	    safe_free(dns_child_table[k]->ip_inbuf);
+	    safe_free(dns_child_table[k]);
+	}
 	safe_free(dns_child_table);
     }
-    dns_child_table = (dnsserver_entry **) xcalloc(N, sizeof(dnsserver_entry));
-    NChildrenAlloc = N;
-    dns_child_alive = 0;
+    dns_child_table = xcalloc(N, sizeof(dnsserver_t *));
+    NDnsServersAlloc = N;
     debug(14, 1, "ipcacheOpenServers: Starting %d 'dns_server' processes\n", N);
-    for (i = 0; i < N; i++) {
-	dns_child_table[i] = (dnsserver_entry *) xcalloc(1, sizeof(dnsserver_entry));
+    for (k = 0; k < N; k++) {
+	dns_child_table[k] = xcalloc(1, sizeof(dnsserver_t));
 	if ((dnssocket = ipcache_create_dnsserver(prg)) < 0) {
 	    debug(14, 1, "ipcacheOpenServers: WARNING: Cannot run 'dnsserver' process.\n");
 	    debug(14, 1, "              Fallling back to the blocking version.\n");
-	    dns_child_table[i]->alive = 0;
+	    dns_child_table[k]->flags &= ~DNS_FLAG_ALIVE;
 	} else {
-	    dns_child_alive = 1;
-	    dns_child_table[i]->id = i;
-	    dns_child_table[i]->inpipe = dnssocket;
-	    dns_child_table[i]->outpipe = dnssocket;
-	    dns_child_table[i]->lastcall = squid_curtime;
-	    dns_child_table[i]->pending_count = 0;
-	    dns_child_table[i]->size = IP_INBUF - 1;	/* spare one for \0 */
-	    dns_child_table[i]->offset = 0;
-	    dns_child_table[i]->alive = 1;
-	    dns_child_table[i]->ip_inbuf = (char *) xcalloc(1, IP_INBUF);
+	    debug(14, 4, "ipcacheOpenServers: FD %d connected to %s #%d.\n",
+		dnssocket, prg, k + 1);
+	    dns_child_table[k]->flags |= DNS_FLAG_ALIVE;
+	    dns_child_table[k]->id = k + 1;
+	    dns_child_table[k]->inpipe = dnssocket;
+	    dns_child_table[k]->outpipe = dnssocket;
+	    dns_child_table[k]->lastcall = squid_curtime;
+	    dns_child_table[k]->size = IP_INBUF_SZ - 1;		/* spare one for \0 */
+	    dns_child_table[k]->offset = 0;
+	    dns_child_table[k]->ip_inbuf = xcalloc(IP_INBUF_SZ, 1);
 
 	    /* update fd_stat */
 
-	    sprintf(fd_note_buf, "%s #%d",
-		prg,
-		dns_child_table[i]->id);
-	    file_update_open(dns_child_table[i]->inpipe, fd_note_buf);
-
-	    debug(14, 5, "Calling fd_note() with FD %d and buf '%s'\n",
-		dns_child_table[i]->inpipe, fd_note_buf);
-
-	    fd_note(dns_child_table[i]->inpipe, fd_note_buf);
-	    commSetNonBlocking(dns_child_table[i]->inpipe);
+	    sprintf(fd_note_buf, "%s #%d", prg, dns_child_table[k]->id);
+	    fd_note(dns_child_table[k]->inpipe, fd_note_buf);
+	    commSetNonBlocking(dns_child_table[k]->inpipe);
 
 	    /* clear unused handlers */
-	    comm_set_select_handler(dns_child_table[i]->inpipe,
+	    comm_set_select_handler(dns_child_table[k]->inpipe,
 		COMM_SELECT_WRITE,
 		0,
 		0);
-	    comm_set_select_handler(dns_child_table[i]->outpipe,
+	    comm_set_select_handler(dns_child_table[k]->outpipe,
 		COMM_SELECT_READ,
 		0,
 		0);
 
 	    /* set handler for incoming result */
-	    comm_set_select_handler(dns_child_table[i]->inpipe,
+	    comm_set_select_handler(dns_child_table[k]->inpipe,
 		COMM_SELECT_READ,
 		(PF) ipcache_dnsHandleRead,
-		(void *) dns_child_table[i]);
-	    debug(14, 3, "ipcacheOpenServers: 'dns_server' %d started\n", i);
+		(void *) dns_child_table[k]);
+	    debug(14, 3, "ipcacheOpenServers: 'dns_server' %d started\n", k);
 	}
     }
 }
