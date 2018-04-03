    handler(fd, NULL, data);
}

static fqdncache_entry *fqdncache_parsebuffer(inbuf, dnsData)
     char *inbuf;
     dnsserver_t *dnsData;
{
    char *buf = xstrdup(inbuf);
    char *token;
    static fqdncache_entry f;
    int k;
    int ipcount;
    int aliascount;
    debug(35, 5, "fqdncache_parsebuffer: parsing:\n%s", inbuf);
    memset(&f, '\0', sizeof(fqdncache_entry));
    f.expires = squid_curtime + Config.positiveDnsTtl;
    f.status = IP_DISPATCHED;
    for (token = strtok(buf, w_space); token; token = strtok(NULL, w_space)) {
	if (!strcmp(token, "$end")) {
	    break;
	} else if (!strcmp(token, "$alive")) {
	    dnsData->answer = squid_curtime;
	} else if (!strcmp(token, "$fail")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $fail");
	    f.expires = squid_curtime + Config.negativeDnsTtl;
	    f.status = IP_NEGATIVE_CACHED;
	} else if (!strcmp(token, "$message")) {
	    if ((token = strtok(NULL, "\n")) == NULL)
		fatal_dump("Invalid $message");
	    f.error_message = xstrdup(token);
	} else if (!strcmp(token, "$name")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $name");
	    f.status = IP_CACHED;
	} else if (!strcmp(token, "$h_name")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $h_name");
	    f.names[0] = xstrdup(token);
	    f.name_count = 1;
	} else if (!strcmp(token, "$h_len")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $h_len");
	} else if (!strcmp(token, "$ipcount")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $ipcount");
	    ipcount = atoi(token);
	    for (k = 0; k < ipcount; k++) {
		if ((token = strtok(NULL, w_space)) == NULL)
		    fatal_dump("Invalid IP address");
	    }
	} else if (!strcmp(token, "$aliascount")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $aliascount");
	    aliascount = atoi(token);
	    for (k = 0; k < aliascount; k++) {
		if ((token = strtok(NULL, w_space)) == NULL)
		    fatal_dump("Invalid alias");
	    }
	} else if (!strcmp(token, "$ttl")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $ttl");
	    f.expires = squid_curtime + atoi(token);
	} else {
	    fatal_dump("Invalid dnsserver output");
	}
    }
    xfree(buf);
    return &f;
}

static int fqdncache_dnsHandleRead(fd, dnsData)
     int fd;
     dnsserver_t *dnsData;
{
    int len;
    int svc_time;
    int n;
    fqdncache_entry *f = NULL;
    fqdncache_entry *x = NULL;

    len = read(fd,
	dnsData->ip_inbuf + dnsData->offset,
