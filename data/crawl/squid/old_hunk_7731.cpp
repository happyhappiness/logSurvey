     char *name;
     int fd;
{
    ipcache_entry *e;
    IpPending *p, *q;

    e = ipcache_get(name);
    if (!e) {
	/* not found any where */
	return 0;
    }
    /* look for matched fd */
    for (q = p = e->pending_head; p; q = p, p = p->next) {
	if (p->fd == fd) {
	    break;
	}
    }

    if (p == NULL) {
	/* Can not find this ipcache_entry, weird */
	debug(14, 1, "ipcache_unregister: Failed to unregister FD %d from name: %s, can't find this FD.\n",
	    fd, name);
	return 0;
    }
    /* found */
    if (p == e->pending_head) {
	/* it's at the head of the queue */
	if (p->next) {
	    /* there is something along the line */
	    e->pending_head = p->next;
	    safe_free(p->data);
	    safe_free(p);
	} else {
	    /* it is the only entry */
	    e->pending_head = e->pending_tail = NULL;
	    safe_free(p->data);
	    safe_free(p);
	}
    } else if (p == e->pending_tail) {
	/* it's at the tail */
	e->pending_tail = q;
	q->next = NULL;
	safe_free(p->data);
	safe_free(p);
    } else {
	/* it's in the middle */
	/* skip it in the list */
	q->next = p->next;
	safe_free(p->data);
	safe_free(p);
    }
    return 1;
}


struct hostent *ipcache_gethostbyname(name)
     char *name;
{
    ipcache_entry *result;
    unsigned int a1, a2, a3, a4;
    struct hostent *s_result = NULL;

    if (!name) {
	debug(14, 5, "ipcache_gethostbyname: Invalid argument?\n");
	return (NULL);
    }
    if (!(result = ipcache_get(name))) {
	/* cache miss */
	if (name) {
	    debug(14, 5, "ipcache_gethostbyname: IPcache miss for '%s'.\n", name);
	}
	/* check if it's already a IP address in text form. */
	if (sscanf(name, "%u.%u.%u.%u", &a1, &a2, &a3, &a4) == 4) {
	    *((unsigned long *) (void *) static_result->h_addr_list[0]) = inet_addr(name);
	    strncpy(static_result->h_name, name, MAX_HOST_NAME);
	    return static_result;
	} else {
	    s_result = gethostbyname(name);
	}

	if (s_result && s_result->h_name && (s_result->h_name[0] != '\0')) {
	    /* good address, cached */
	    debug(14, 10, "ipcache_gethostbyname: DNS success: cache for '%s'.\n", name);
	    ipcache_add(name, ipcache_create(), s_result, 1);
	    result = ipcache_get(name);
	    return &(result->entry);
	} else {
	    /* bad address, negative cached */
	    debug(14, 3, "ipcache_gethostbyname: DNS failure: negative cache for '%s'.\n", name);
	    ipcache_add(name, ipcache_create(), s_result, 0);
	    return NULL;
	}

    }
    /* cache hit */
    debug(14, 5, "ipcache_gethostbyname: Hit for '%s'.\n", name ? name : "NULL");
    result->lastref = squid_curtime;
    return (result->status == CACHED) ? &(result->entry) : NULL;
}



/* process objects list */
void stat_ipcache_get(sentry, obj)
     StoreEntry *sentry;
     cacheinfo *obj;
{
    char buffer[MAX_LINELEN];
    ipcache_entry *e = NULL;
    int i;
    int ttl;
    char status;

    sprintf(buffer, "{IP Cache Contents:\n\n");
    storeAppend(sentry, buffer, strlen(buffer));

    for (e = ipcache_GetFirst(); (e); e = ipcache_GetNext()) {
	if (e) {
	    ttl = (e->ttl - squid_curtime + e->lastref);
	    status = ipcache_status_char(e);
	    if (status == 'P')
		ttl = 0;

	    sprintf(buffer, " {%s %c %d %d",
		e->name, status, ttl, e->addr_count);
	    storeAppend(sentry, buffer, strlen(buffer));

	    for (i = 0; i < (int) e->addr_count; i++) {
		struct in_addr addr;
		memcpy((char *) &addr, e->entry.h_addr_list[i], e->entry.h_length);

		sprintf(buffer, " %s", inet_ntoa(addr));
		storeAppend(sentry, buffer, strlen(buffer));
	    }
	    for (i = 0; i < (int) e->alias_count; i++) {
		sprintf(buffer, " %s", e->entry.h_aliases[i]);
		storeAppend(sentry, buffer, strlen(buffer));
	    }
	    if (e->entry.h_name && strncmp(e->name, e->entry.h_name, MAX_LINELEN)) {
		sprintf(buffer, " %s", e->entry.h_name);
		storeAppend(sentry, buffer, strlen(buffer));
	    }
	    sprintf(buffer, "}\n");
	    storeAppend(sentry, buffer, strlen(buffer));
	}
    }
    sprintf(buffer, "}\n");
    storeAppend(sentry, buffer, strlen(buffer));

}

char ipcache_status_char(e)
     ipcache_entry *e;
{
    switch (e->status) {
    case CACHED:
	return ('C');
    case PENDING:
	return ('P');
    case NEGATIVE_CACHED:
	return ('N');
    default:
	debug(14, 1, "ipcache_status_char: unexpected IP cache status.\n");
    }
    return ('X');
}

int ipcache_hash_entry_count()
{
    ipcache_entry *e;
    int local_ip_count = 0;

    e = NULL;

    for (e = ipcache_GetFirst(); e; e = ipcache_GetNext()) {
	local_ip_count++;
    }

    return local_ip_count;
}

void ipcacheShutdownServers()
{
    dnsserver_entry *dns = NULL;
    int i;
    static char *shutdown = "$shutdown\n";

    debug(14, 3, "ipcacheShutdownServers:\n");

    for (i = 0; i < getDnsChildren(); i++) {
	dns = *(dns_child_table + i);
	debug(14, 3, "ipcacheShutdownServers: sending '$shutdown' to dnsserver #%d\n", i);
	debug(14, 3, "ipcacheShutdownServers: --> FD %d\n", dns->outpipe);
	file_write(dns->outpipe,
	    xstrdup(shutdown),
	    strlen(shutdown),
	    0,			/* Lock */
	    0,			/* Handler */
	    0);			/* Handler-data */
    }
}
