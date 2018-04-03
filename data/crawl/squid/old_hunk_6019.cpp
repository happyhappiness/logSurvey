    const struct hostent *h = NULL;
    if (Config.visibleHostname != NULL)
	return Config.visibleHostname;
    if (present) {
	(void) 0;
    } else if (Config.Sockaddr.http->s.sin_addr.s_addr != any_addr.s_addr) {
	/*
	 * If the first http_port address has a specific address, try a
	 * reverse DNS lookup on it.
	 */
	host[0] = '\0';
	h = gethostbyaddr((char *) &Config.Sockaddr.http->s.sin_addr,
	    sizeof(Config.Sockaddr.http->s.sin_addr), AF_INET);
	if (h != NULL) {
	    /* DNS lookup successful */
	    /* use the official name from DNS lookup */
	    strcpy(host, h->h_name);
	    debug(50, 4) ("getMyHostname: resolved tcp_incoming_addr to '%s'\n",
		host);
	    present = 1;
	} else {
	    debug(50, 6) ("getMyHostname: failed to resolve tcp_incoming_addr\n");
	}
    } else {
	/*
	 * Get the host name and store it in host to return
	 */
	host[0] = '\0';
	if (gethostname(host, SQUIDHOSTNAMELEN) == -1) {
	    debug(50, 1) ("getMyHostname: gethostname failed: %s\n",
		xstrerror());
	} else {
	    if ((h = gethostbyname(host)) != NULL) {
		debug(50, 6) ("getMyHostname: '%s' resolved into '%s'\n",
		    host, h->h_name);
		/* DNS lookup successful */
		/* use the official name from DNS lookup */
		strcpy(host, h->h_name);
	    }
	}
	present = 1;
    }
    return present ? host : NULL;
}

const char *
