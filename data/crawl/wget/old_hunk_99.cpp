    }

#ifdef ENABLE_IPV6
  {
    int err;
    struct addrinfo hints, *res;

    xzero (hints);
    hints.ai_socktype = SOCK_STREAM;
    if (opt.ipv4_only)
      hints.ai_family = AF_INET;
    else if (opt.ipv6_only)
      hints.ai_family = AF_INET6;
    else
      /* We tried using AI_ADDRCONFIG, but removed it because: it
         misinterprets IPv6 loopbacks, it is broken on AIX 5.1, and
         it's unneeded since we sort the addresses anyway.  */
        hints.ai_family = AF_UNSPEC;

    if (flags & LH_BIND)
      hints.ai_flags |= AI_PASSIVE;

#ifdef AI_NUMERICHOST
    if (numeric_address)
      {
        /* Where available, the AI_NUMERICHOST hint can prevent costly
           access to DNS servers.  */
        hints.ai_flags |= AI_NUMERICHOST;
        timeout = 0;            /* no timeout needed when "resolving"
                                   numeric hosts -- avoid setting up
                                   signal handlers and such. */
      }
#endif

    err = getaddrinfo_with_timeout (host, NULL, &hints, &res, timeout);
    if (err != 0 || res == NULL)
      {
        if (!silent)
          logprintf (LOG_VERBOSE, _("failed: %s.\n"),
                     err != EAI_SYSTEM ? gai_strerror (err) : strerror (errno));
        return NULL;
      }
    al = address_list_from_addrinfo (res);
    freeaddrinfo (res);
    if (!al)
      {
        logprintf (LOG_VERBOSE,
                   _("failed: No IPv4/IPv6 addresses for host.\n"));
        return NULL;
      }

    /* Reorder addresses so that IPv4 ones (or IPv6 ones, as per
       --prefer-family) come first.  Sorting is stable so the order of
       the addresses with the same family is undisturbed.  */
    if (al->count > 1 && opt.prefer_family != prefer_none)
      stable_sort (al->addresses, al->count, sizeof (ip_address),
                   opt.prefer_family == prefer_ipv4
                   ? cmp_prefer_ipv4 : cmp_prefer_ipv6);
  }
#else  /* not ENABLE_IPV6 */
  {
    struct hostent *hptr = gethostbyname_with_timeout (host, timeout);
    if (!hptr)
      {
        if (!silent)
          {
            if (errno != ETIMEDOUT)
              logprintf (LOG_VERBOSE, _("failed: %s.\n"),
                         host_errstr (h_errno));
            else
              logputs (LOG_VERBOSE, _("failed: timed out.\n"));
          }
        return NULL;
      }
    /* Do older systems have h_addr_list?  */
    al = address_list_from_ipv4_addresses (hptr->h_addr_list);
  }
#endif /* not ENABLE_IPV6 */

  /* Print the addresses determined by DNS lookup, but no more than
