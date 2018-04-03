
    host[0] = '\0';

    if (Config.Sockaddr.http && sa.IsAnyAddr())
        sa = Config.Sockaddr.http->s;

#if USE_SSL

    if (Config.Sockaddr.https && sa.IsAnyAddr())
        sa = Config.Sockaddr.https->http.s;

#endif

    /*
     * If the first http_port address has a specific address, try a
     * reverse DNS lookup on it.
     */
    if( !sa.IsAnyAddr() ) {

        sa.GetAddrInfo(AI);
        /* we are looking for a name. */
        if(xgetnameinfo(AI->ai_addr, AI->ai_addrlen, host, SQUIDHOSTNAMELEN, NULL, 0, NI_NAMEREQD ) == 0) {
            /* DNS lookup successful */
            /* use the official name from DNS lookup */
            debugs(50, 4, "getMyHostname: resolved " << sa << " to '" << host << "'");

            present = 1;

            sa.FreeAddrInfo(AI);

            if (strchr(host, '.'))
                return host;
        }

        sa.FreeAddrInfo(AI);
        debugs(50, 1, "WARNING: failed to resolve " << sa << " to a fully qualified hostname");
    }
    else {
        if (gethostname(host, SQUIDHOSTNAMELEN) < 0) {
            debugs(50, 1, "WARNING: gethostname failed: " << xstrerror());
        }
        else {
            /* Verify that the hostname given resolves properly */
            struct addrinfo hints;
            memset(&hints, 0, sizeof(addrinfo));
            hints.ai_flags = AI_CANONNAME;

            if(xgetaddrinfo(host, NULL, NULL, &AI) == 0) {
                /* DNS lookup successful */
                /* use the official name from DNS lookup */
                debugs(50, 6, "getMyHostname: '" << host << "' resolved into '" << AI->ai_canonname << "'");
                xstrncpy(host, AI->ai_canonname, SQUIDHOSTNAMELEN);
                present = 1;

                /* AYJ: do we want to flag AI_ALL and cache the result anywhere. ie as our local host IPs? */
                if(AI) {
                    xfreeaddrinfo(AI);
                    AI = NULL;
                }

                return host;
            }

            if(AI) xfreeaddrinfo(AI);
            debugs(50, 1, "WARNING: getaddrinfo('" << host << "') failed: " << xstrerror());
        }
    }

    /* throw a fatal configuration error when the Host/IP given has bad DNS/rDNS. */
    if (opt_send_signal == -1)
        fatal("Could not determine fully qualified hostname.  Please set 'visible_hostname'\n");
    else
