
    host[0] = '\0';

    memcpy(&sa, &any_addr, sizeof(sa));

    if (Config.Sockaddr.http && sa.s_addr == any_addr.s_addr)
        memcpy(&sa, &Config.Sockaddr.http->s.sin_addr, sizeof(sa));

#if USE_SSL

    if (Config.Sockaddr.https && sa.s_addr == any_addr.s_addr)
        memcpy(&sa, &Config.Sockaddr.https->http.s.sin_addr, sizeof(sa));

#endif
    /*
     * If the first http_port address has a specific address, try a
     * reverse DNS lookup on it.
     */
    if (sa.s_addr != any_addr.s_addr) {
        h = gethostbyaddr((char *) &sa,
                          sizeof(sa), AF_INET);

        if (h != NULL) {
            /* DNS lookup successful */
            /* use the official name from DNS lookup */
            xstrncpy(host, h->h_name, SQUIDHOSTNAMELEN);
            debugs(50, 4, "getMyHostname: resolved " << inet_ntoa(sa) << " to '" << host << "'");

            present = 1;

            if (strchr(host, '.'))
                return host;

        }

        debugs(50, 1, "WARNING: failed to resolve " << inet_ntoa(sa) << " to a fully qualified hostname");
    }

    /*
     * Get the host name and store it in host to return
     */
    if (gethostname(host, SQUIDHOSTNAMELEN) < 0) {
        debugs(50, 1, "WARNING: gethostname failed: " << xstrerror());
    } else if ((h = gethostbyname(host)) == NULL) {
        debugs(50, 1, "WARNING: gethostbyname failed for " << host);
    } else {
        debugs(50, 6, "getMyHostname: '" << host << "' resolved into '" << h->h_name << "'");
        /* DNS lookup successful */
        /* use the official name from DNS lookup */
        xstrncpy(host, h->h_name, SQUIDHOSTNAMELEN);
        present = 1;

        if (strchr(host, '.'))
            return host;
    }

    if (opt_send_signal == -1)
        fatal("Could not determine fully qualified hostname.  Please set 'visible_hostname'\n");
    else
