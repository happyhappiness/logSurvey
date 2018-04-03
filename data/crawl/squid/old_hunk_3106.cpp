        }

        sa.FreeAddrInfo(AI);
        debugs(50, 1, "WARNING: failed to resolve " << sa << " to a fully qualified hostname");
    } else {
        if (gethostname(host, SQUIDHOSTNAMELEN) < 0) {
            debugs(50, 1, "WARNING: gethostname failed: " << xstrerror());
        } else {
            /* Verify that the hostname given resolves properly */
            struct addrinfo hints;
            memset(&hints, 0, sizeof(addrinfo));
            hints.ai_flags = AI_CANONNAME;

            if (getaddrinfo(host, NULL, NULL, &AI) == 0) {
                /* DNS lookup successful */
                /* use the official name from DNS lookup */
                debugs(50, 6, "getMyHostname: '" << host << "' has rDNS.");
                present = 1;

                /* AYJ: do we want to flag AI_ALL and cache the result anywhere. ie as our local host IPs? */
                if (AI) {
                    freeaddrinfo(AI);
                    AI = NULL;
                }

                return host;
            }

            if (AI) freeaddrinfo(AI);
            debugs(50, 1, "WARNING: '" << host << "' rDNS test failed: " << xstrerror());
        }
    }

    /* throw a fatal configuration error when the Host/IP given has bad DNS/rDNS. */
    if (opt_send_signal == -1)
        fatal("Could not determine fully qualified hostname.  Please set 'visible_hostname'\n");
    else
        return ("localhost");

    return NULL;		/* keep compiler happy */
}

const char *