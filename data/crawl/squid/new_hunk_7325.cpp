{
    struct in_addr b;
    b.s_addr = ntohl(a.s_addr);
#if USE_CLASSFUL
    if (IN_CLASSC(b.s_addr))
	b.s_addr &= IN_CLASSC_NET;
    else if (IN_CLASSB(b.s_addr))
	b.s_addr &= IN_CLASSB_NET;
    else if (IN_CLASSA(b.s_addr))
	b.s_addr &= IN_CLASSA_NET;
#else
    /* use /24 for everything */
    b.s_addr &= IN_CLASSC_NET;
#endif
    b.s_addr = htonl(b.s_addr);
    return b;
}

static int
sortByRtt(netdbEntry ** n1, netdbEntry ** n2)
{
    if ((*n1)->rtt > (*n2)->rtt)
	return 1;
    else if ((*n1)->rtt < (*n2)->rtt)
	return -1;
    else
	return 0;
}

static net_db_peer *
netdbPeerByName(const netdbEntry * n, const char *peername)
{
    int i;
    net_db_peer *p = n->peers;
    for (i = 0; i < n->n_peers; i++, p++) {
	if (!strcmp(p->peername, peername))
	    return p;
    }
    return NULL;
}

static net_db_peer *
netdbPeerAdd(netdbEntry * n, peer * e)
{
    net_db_peer *p;
    net_db_peer *o;
    int osize;
    int i;
    if (n->n_peers == n->n_peers_alloc) {
	o = n->peers;
	osize = n->n_peers_alloc;
	if (n->n_peers_alloc == 0)
	    n->n_peers_alloc = 2;
	else
	    n->n_peers_alloc <<= 1;
	debug(37, 3, "netdbPeerAdd: Growing peer list for '%s' to %d\n",
	    n->network, n->n_peers_alloc);
	n->peers = xcalloc(n->n_peers_alloc, sizeof(net_db_peer));
	meta_data.netdb_peers += n->n_peers_alloc;
	for (i = 0; i < osize; i++)
	    *(n->peers + i) = *(o + i);
	if (osize) {
	    safe_free(o);
	    meta_data.netdb_peers -= osize;
	}
    }
    p = n->peers + n->n_peers;
    p->peername = netdbPeerName(e->host);
    n->n_peers++;
    return p;
}

static int
sortPeerByRtt(net_db_peer * p1, net_db_peer * p2)
{
    if (p1->rtt > p2->rtt)
	return 1;
    else if (p1->rtt < p2->rtt)
	return -1;
    else
	return 0;
}

static void
netdbSaveState(void *foo)
{
    LOCAL_ARRAY(char, path, SQUID_MAXPATHLEN);
    FILE *fp;
    netdbEntry *n;
    netdbEntry *next;
    net_db_name *x;
    struct timeval start = current_time;
    int count = 0;
    sprintf(path, "%s/netdb_state", swappath(0));
    fp = fopen(path, "w");
    if (fp == NULL) {
	debug(50, 1, "netdbSaveState: %s: %s\n", path, xstrerror());
	return;
    }
    next = (netdbEntry *) hash_first(addr_table);
    while ((n = next)) {
	next = (netdbEntry *) hash_next(addr_table);
	if (n->pings_recv == 0)
	    continue;
	fprintf(fp, "%s %d %d %10.5f %10.5f %d %d",
	    n->network,
	    n->pings_sent,
	    n->pings_recv,
	    n->hops,
	    n->rtt,
	    (int) n->next_ping_time,
	    (int) n->last_use_time);
	for (x = n->hosts; x; x = x->next)
	    fprintf(fp, " %s", x->name);
	fprintf(fp, "\n");
	count++;
    }
    fclose(fp);
    getCurrentTime();
    debug(37, 0, "NETDB state saved; %d entries, %d msec\n",
	count, tvSubMsec(start, current_time));
    eventAdd("netdbSaveState", netdbSaveState, NULL, 3617);
}

static void
netdbReloadState(void)
{
    LOCAL_ARRAY(char, path, SQUID_MAXPATHLEN);
    char *buf = get_free_4k_page();
    char *t;
    FILE *fp;
    netdbEntry *n;
    netdbEntry N;
    struct in_addr addr;
    int count = 0;
    struct timeval start = current_time;
    sprintf(path, "%s/netdb_state", swappath(0));
    fp = fopen(path, "r");
    if (fp == NULL)
	return;
    while (fgets(buf, 4095, fp)) {
	memset(&N, '\0', sizeof(netdbEntry));
	if ((t = strtok(buf, w_space)) == NULL)
	    continue;
	if (!safe_inet_addr(t, &addr))
	    continue;
	if ((t = strtok(NULL, w_space)) == NULL)
	    continue;
	N.pings_sent = atoi(t);
	if ((t = strtok(NULL, w_space)) == NULL)
	    continue;
	N.pings_recv = atoi(t);
	if (N.pings_recv == 0)
	    continue;
	/* give this measurement low weight */
	N.pings_sent = 1;
	N.pings_recv = 1;
	if ((t = strtok(NULL, w_space)) == NULL)
	    continue;
	N.hops = atof(t);
	if ((t = strtok(NULL, w_space)) == NULL)
	    continue;
	N.rtt = atof(t);
	if ((t = strtok(NULL, w_space)) == NULL)
	    continue;
	N.next_ping_time = (time_t) atoi(t);
	if ((t = strtok(NULL, w_space)) == NULL)
	    continue;
	N.last_use_time = (time_t) atoi(t);
	n = xcalloc(1, sizeof(netdbEntry));
	memcpy(n, &N, sizeof(netdbEntry));
	netdbHashInsert(n, addr);
	while ((t = strtok(NULL, w_space)) != NULL)
	    netdbHashLink(n, t);
	count++;
    }
    put_free_4k_page(buf);
    fclose(fp);
    getCurrentTime();
    debug(37, 0, "NETDB state reloaded; %d entries, %d msec\n",
	count, tvSubMsec(start, current_time));
}

static char *
netdbPeerName(const char *name)
{
    wordlist *w;
    for (w = peer_names; w; w = w->next) {
	if (!strcmp(w->key, name))
	    return w->key;
    }
    w = xcalloc(1, sizeof(wordlist));
    w->key = xstrdup(name);
    *peer_names_tail = w;
    peer_names_tail = &w->next;
    return w->key;
}



#endif /* USE_ICMP */

/* PUBLIC FUNCTIONS */
