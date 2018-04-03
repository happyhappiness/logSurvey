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
