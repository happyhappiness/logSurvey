        }

        sa.FreeAddrInfo(AI);
        debugs(50, 2, "WARNING: failed to resolve " << sa << " to a fully qualified hostname");
    }

    // still no host. fallback to gethostname()
    if (gethostname(host, SQUIDHOSTNAMELEN) < 0) {
        debugs(50, DBG_IMPORTANT, "WARNING: gethostname failed: " << xstrerror());
    } else {
        /* Verify that the hostname given resolves properly */
        struct addrinfo hints;
        memset(&hints, 0, sizeof(addrinfo));
        hints.ai_flags = AI_CANONNAME;

        if (getaddrinfo(host, NULL, NULL, &AI) == 0) {
            /* DNS lookup successful */
            /* use the official name from DNS lookup */
            debugs(50, 6, "getMyHostname: '" << host << "' has DNS resolution.");
            present = 1;

            /* AYJ: do we want to flag AI_ALL and cache the result anywhere. ie as our local host IPs? */
            if (AI) {
                freeaddrinfo(AI);
                AI = NULL;
            }

            return host;
        }

        if (AI) freeaddrinfo(AI);
        debugs(50, DBG_IMPORTANT, "WARNING: '" << host << "' rDNS test failed: " << xstrerror());
    }

    /* throw a configuration error when the Host/IP given has bad DNS/rDNS. */
    debugs(50, DBG_CRITICAL, "WARNING: Could not determine this machines public hostname. " <<
           "Please configure one or set 'visible_hostname'.");

    return ("localhost");
}

const char *