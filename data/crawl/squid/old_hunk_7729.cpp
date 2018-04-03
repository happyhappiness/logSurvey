}


int ipcache_dnsHandleRead(fd, data)
     int fd;
     dnsserver_entry *data;
{
    int char_scanned;
    int len = read(fd, data->ip_inbuf + data->offset, data->size - data->offset);

    debug(14, 5, "ipcache_dnsHandleRead: Result from DNS ID %d.\n", data->id);

    if (len == 0) {
	debug(14, 1, "ipcache_dnsHandleRead: Connection from DNSSERVER is closed.\n");
	debug(14, 1, "                       Disabling this server ID %d.\n", data->id);
	data->alive = 0;
	update_dns_child_alive();
	ipcache_cleanup_pendinglist(data);
	close(fd);
	fdstat_close(fd);
	return 0;
    }
    data->offset += len;
    data->ip_inbuf[data->offset] = '\0';

    if (strstr(data->ip_inbuf, "$end\n")) {
	/* end of record found */
	char_scanned = ipcache_parsebuffer(data->ip_inbuf, data->offset, data);
	if (char_scanned > 0) {
	    /* update buffer */
	    memcpy(data->ip_inbuf, data->ip_inbuf + char_scanned, data->offset - char_scanned);
	    data->offset -= char_scanned;
	    data->ip_inbuf[data->offset] = '\0';
	}
    }
    /* reschedule */
    comm_set_select_handler(data->inpipe, COMM_SELECT_READ,
	(PF) ipcache_dnsHandleRead, (void *) data);
    return 0;
}

int ipcache_nbgethostbyname(name, fd, handler, data)
     char *name;
     int fd;
     IPH handler;
     void *data;
{
    ipcache_entry *e;
    IpPending *pending;
    dnsserver_entry *dns;

    debug(14, 4, "ipcache_nbgethostbyname: FD %d: Name '%s'.\n", fd, name);

    if (name == NULL || name[0] == '\0') {
	debug(14, 4, "ipcache_nbgethostbyname: Invalid name!\n");
	ipcache_call_pending_badname(fd, handler, data);
	return 0;
    }
    if ((e = ipcache_get(name)) != NULL && (e->status != PENDING)) {
	/* hit here */
	debug(14, 4, "ipcache_nbgethostbyname: Hit for name '%s'.\n", name);
	pending = (IpPending *) xcalloc(1, sizeof(IpPending));
	pending->fd = fd;
	pending->handler = handler;
	pending->data = data;
	pending->next = NULL;
	if (e->pending_head == NULL) {	/* empty list */
	    e->pending_head = e->pending_tail = pending;
	} else {		/* add to tail of list */
	    e->pending_tail->next = pending;
	    e->pending_tail = e->pending_tail->next;
	}
	ipcache_call_pending(e);
	return 0;
    }
    debug(14, 4, "ipcache_nbgethostbyname: Name '%s': MISS or PENDING.\n", name);

    pending = (IpPending *) xcalloc(1, sizeof(IpPending));
    pending->fd = fd;
    pending->handler = handler;
    pending->data = data;
    pending->next = NULL;
    if (e == NULL) {
	/* No entry, create the new one */
	debug(14, 5, "ipcache_nbgethostbyname: Creating new entry for '%s'...\n",
	    name);
	e = ipcache_create();
	e->name = xstrdup(name);
	e->status = PENDING;
	e->pending_tail = e->pending_head = pending;
	ipcache_add_to_hash(e);
    } else {
	/* There is an entry. Add handler to list */
	debug(14, 5, "ipcache_nbgethostbyname: Adding handler to pending list for '%s'.\n", name);
	if (e->pending_head == NULL) {	/* empty list */
	    e->pending_head = e->pending_tail = pending;
	} else {		/* add to tail of list */
	    e->pending_tail->next = pending;
	    e->pending_tail = e->pending_tail->next;
	}
	return 0;
    }

    if (dns_child_alive) {
	int i, j, min_dns = 0, min_count = 255, alive = 0;

	j = last_dns_dispatched;
	/* select DNS server with the lowest number of pending */
	for (i = 0; i < getDnsChildren(); ++i) {
	    j += 1;
	    j %= getDnsChildren();
	    if ((dns_child_table[j]->alive) &&
		(dns_child_table[j]->pending_count < min_count)) {
		min_dns = j;
		min_count = dns_child_table[j]->pending_count;
	    }
	    alive = dns_child_table[j]->alive | alive;
	}

	if (alive == 0) {
	    dns_child_alive = 0;	/* all dead */
	    last_dns_dispatched = 0;	/* use entry 0 */
	} else {
	    last_dns_dispatched = min_dns;
	}
    } else {
	last_dns_dispatched = 0;
    }

    dns = dns_child_table[last_dns_dispatched];
    debug(14, 5, "ipcache_nbgethostbyname: Dispatched DNS %d.\n",
	last_dns_dispatched);

    /* add to global pending list */
    if (dns->global_pending == NULL) {	/* new list */
	dns->global_pending = (ipcache_list *) xcalloc(1, sizeof(ipcache_list));
	dns->global_pending->entry = e;
	dns->global_pending->next = NULL;
	dns->global_pending_tail = dns->global_pending;
    } else {			/* add to end of list */
	ipcache_list *p = (ipcache_list *) xcalloc(1, sizeof(ipcache_list));
	p->entry = e;
	p->next = NULL;
	dns->global_pending_tail->next = p;
	dns->global_pending_tail = dns->global_pending_tail->next;
    }

    if (dns_child_alive) {
	char *buf = (char *) xcalloc(1, 256);
	strncpy(buf, name, 254);
	strcat(buf, "\n");
	dns->pending_count++;
	file_write(dns->outpipe,
	    buf,
	    strlen(buf),
	    0,			/* Lock */
	    0,			/* Handler */
	    0);			/* Handler-data */

	debug(14, 5, "ipcache_nbgethostbyname: Request sent DNS server ID %d.\n", last_dns_dispatched);
    } else {
	/* do a blocking mode */
	debug(14, 4, "ipcache_nbgethostbyname: Fall back to blocking mode.  Server's dead...\n");
	ipcache_cleanup_pendinglist(dns);
    }
    return 0;
}


void ipcacheOpenServers()
{
    int N = getDnsChildren();
    char *prg = getDnsProgram();
    int i;
    int dnssocket;
    static char fd_note_buf[FD_ASCII_NOTE_SZ];
    static int NChildrenAlloc = 0;

    /* free old structures if present */
    if (dns_child_table) {
	for (i = 0; i < NChildrenAlloc; i++)
	    safe_free(dns_child_table[i]->ip_inbuf);
	safe_free(dns_child_table);
    }
    dns_child_table = (dnsserver_entry **) xcalloc(N, sizeof(dnsserver_entry));
    NChildrenAlloc = N;
    dns_child_alive = 0;
    debug(14, 1, "ipcacheOpenServers: Starting %d 'dns_server' processes\n", N);
    for (i = 0; i < N; i++) {
	dns_child_table[i] = (dnsserver_entry *) xcalloc(1, sizeof(dnsserver_entry));
	if ((dnssocket = ipcache_create_dnsserver(prg)) < 0) {
	    debug(14, 1, "ipcacheOpenServers: WARNING: Cannot run 'dnsserver' process.\n");
	    debug(14, 1, "              Fallling back to the blocking version.\n");
	    dns_child_table[i]->alive = 0;
	} else {
	    dns_child_alive = 1;
	    dns_child_table[i]->id = i;
	    dns_child_table[i]->inpipe = dnssocket;
	    dns_child_table[i]->outpipe = dnssocket;
	    dns_child_table[i]->lastcall = squid_curtime;
	    dns_child_table[i]->pending_count = 0;
	    dns_child_table[i]->size = IP_INBUF - 1;	/* spare one for \0 */
	    dns_child_table[i]->offset = 0;
	    dns_child_table[i]->alive = 1;
	    dns_child_table[i]->ip_inbuf = (char *) xcalloc(1, IP_INBUF);

	    /* update fd_stat */

	    sprintf(fd_note_buf, "%s #%d",
		prg,
		dns_child_table[i]->id);
	    file_update_open(dns_child_table[i]->inpipe, fd_note_buf);

	    debug(14, 5, "Calling fd_note() with FD %d and buf '%s'\n",
		dns_child_table[i]->inpipe, fd_note_buf);

	    fd_note(dns_child_table[i]->inpipe, fd_note_buf);
	    commSetNonBlocking(dns_child_table[i]->inpipe);

	    /* clear unused handlers */
	    comm_set_select_handler(dns_child_table[i]->inpipe,
		COMM_SELECT_WRITE,
		0,
		0);
	    comm_set_select_handler(dns_child_table[i]->outpipe,
		COMM_SELECT_READ,
		0,
		0);

	    /* set handler for incoming result */
	    comm_set_select_handler(dns_child_table[i]->inpipe,
		COMM_SELECT_READ,
		(PF) ipcache_dnsHandleRead,
		(void *) dns_child_table[i]);
	    debug(14, 3, "ipcacheOpenServers: 'dns_server' %d started\n", i);
	}
    }
}
