

static ipcache_entry *
ipcacheParse(const char *inbuf, dnsserver_t * dnsData)
{
    LOCAL_ARRAY(char, buf, DNS_INBUF_SZ);
    char *token;
    static ipcache_entry i;
    int j;
    int k;
    int ipcount = 0;
    int ttl;
    char A[32][16];
    xstrncpy(buf, inbuf, DNS_INBUF_SZ);
    debug(14, 5) ("ipcacheParse: parsing:\n%s", buf);
    memset(&i, '\0', sizeof(i));
    i.expires = squid_curtime;
    i.status = IP_NEGATIVE_CACHED;
    token = strtok(buf, w_space);
    if (NULL == token) {
	debug(14, 1) ("ipcacheParse: Got <NULL>, expecting '$addr'\n");
	return &i;
    }
    if (0 == strcmp(token, "$fail")) {
	i.expires = squid_curtime + Config.negativeDnsTtl;
	token = strtok(NULL, "\n");
	assert(NULL != token);
	i.error_message = xstrdup(token);
	return &i;
    }
    if (0 != strcmp(token, "$addr")) {
	debug(14, 1) ("ipcacheParse: Got '%s', expecting '$addr'\n", token);
	return &i;
    }
    token = strtok(NULL, w_space);
    if (NULL == token) {
	debug(14, 1) ("ipcacheParse: Got <NULL>, expecting TTL\n");
	return &i;
    }
    i.status = IP_CACHED;
    ttl = atoi(token);
    if (ttl > 0)
	i.expires = squid_curtime + ttl;
    else
	i.expires = squid_curtime + Config.positiveDnsTtl;
    while (NULL != (token = strtok(NULL, w_space))) {
	xstrncpy(A[ipcount], token, 16);
	if (++ipcount == 32)
	    break;
    }
    if (0 == ipcount) {
	i.addrs.in_addrs = NULL;
	i.addrs.bad_mask = NULL;
    } else {
	i.addrs.in_addrs = xcalloc(ipcount, sizeof(struct in_addr));
	i.addrs.bad_mask = xcalloc(ipcount, sizeof(unsigned char));
    }
    for (j = 0, k = 0; k < ipcount; k++) {
	if (safe_inet_addr(A[k], &i.addrs.in_addrs[j]))
	    j++;
	else
	    debug(14, 1) ("ipcacheParse: Invalid IP address '%s'\n", A[k]);
    }
    i.addrs.count = (unsigned char) j;
    return &i;
}

