    else
      hints.ai_family   = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    err = getaddrinfo (host, NULL, &hints, &ai);

    if (err != 0 || ai == NULL)
      {
        if (!silent)
	  logprintf (LOG_VERBOSE, _("failed: %s.\n"), gai_strerror (err));
        return NULL;
      }
    al = address_list_from_addrinfo (ai);
