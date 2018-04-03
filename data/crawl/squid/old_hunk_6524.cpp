

static ipcache_entry *
ipcache_parsebuffer(const char *inbuf, dnsserver_t * dnsData)
{
    char *buf = xstrdup(inbuf);
    char *token;
    static ipcache_entry i;
    int k;
    int ipcount;
    int aliascount;
    debug(14, 5) ("ipcache_parsebuffer: parsing:\n%s", inbuf);
    memset(&i, '\0', sizeof(ipcache_entry));
    i.expires = squid_curtime + Config.positiveDnsTtl;
    for (token = strtok(buf, w_space); token; token = strtok(NULL, w_space)) {
	if (!strcmp(token, "$end")) {
	    break;
	} else if (!strcmp(token, "$alive")) {
	    dnsData->answer = squid_curtime;
	} else if (!strcmp(token, "$fail")) {
	    if ((token = strtok(NULL, "\n")) == NULL)
		fatal_dump("Invalid $fail");
	    i.expires = squid_curtime + Config.negativeDnsTtl;
	    i.status = IP_NEGATIVE_CACHED;
	} else if (!strcmp(token, "$message")) {
	    if ((token = strtok(NULL, "\n")) == NULL)
		fatal_dump("Invalid $message");
	    i.error_message = xstrdup(token);
	} else if (!strcmp(token, "$name")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $name");
	    i.status = IP_CACHED;
	} else if (!strcmp(token, "$h_name")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $h_name");
	    /* ignore $h_name */
	} else if (!strcmp(token, "$h_len")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $h_len");
	    /* ignore $h_length */
	} else if (!strcmp(token, "$ipcount")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $ipcount");
	    ipcount = atoi(token);
	    i.addrs.count = (unsigned char) ipcount;
	    if (ipcount == 0) {
		i.addrs.in_addrs = NULL;
		i.addrs.bad_mask = NULL;
	    } else {
		i.addrs.in_addrs = xcalloc(ipcount, sizeof(struct in_addr));
		i.addrs.bad_mask = xcalloc(ipcount, sizeof(unsigned char));
	    }
	    for (k = 0; k < ipcount; k++) {
		if ((token = strtok(NULL, w_space)) == NULL)
		    fatal_dump("Invalid IP address");
		if (!safe_inet_addr(token, &i.addrs.in_addrs[k]))
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
	    i.expires = squid_curtime + atoi(token);
	} else {
	    debug(14, 0) ("--> %s <--\n", inbuf);
	    debug_trap("Invalid dnsserver output");
	}
    }
    xfree(buf);
    return &i;
}

