    fqdncacheUnlockEntry(f);
}


static fqdncache_entry *
fqdncacheParse(const char *inbuf, dnsserver_t * dnsData)
{
    LOCAL_ARRAY(char, buf, DNS_INBUF_SZ);
    char *token;
    static fqdncache_entry f;
    int ttl;
    xstrncpy(buf, inbuf, DNS_INBUF_SZ);
    debug(14, 5) ("fqdncacheParse: parsing:\n%s", buf);
    memset(&f, '\0', sizeof(f));
    f.expires = squid_curtime;
    f.status = FQDN_NEGATIVE_CACHED;
    token = strtok(buf, w_space);
    if (NULL == token) {
	debug(14, 1) ("fqdncacheParse: Got <NULL>, expecting '$name'\n");
	return &f;
    }
    if (0 == strcmp(token, "$fail")) {
	f.expires = squid_curtime + Config.negativeDnsTtl;
	token = strtok(NULL, "\n");
	assert(NULL != token);
	f.error_message = xstrdup(token);
	return &f;
    }
    if (0 != strcmp(token, "$name")) {
	debug(14, 1) ("fqdncacheParse: Got '%s', expecting '$name'\n", token);
	return &f;
    }
    token = strtok(NULL, w_space);
    if (NULL == token) {
	debug(14, 1) ("fqdncacheParse: Got <NULL>, expecting TTL\n");
	return &f;
    }
    f.status = FQDN_CACHED;
    ttl = atoi(token);
    if (ttl > 0)
	f.expires = squid_curtime + ttl;
    else
	f.expires = squid_curtime + Config.positiveDnsTtl;
    token = strtok(NULL, w_space);
    if (NULL != token) {
	f.names[0] = xstrdup(token);
	f.name_count = 1;
    }
    return &f;
}

