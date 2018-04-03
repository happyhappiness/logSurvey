	}
    }

  /* No luck with the cache; resolve the host name. */

  if (!silent)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);

#ifdef ENABLE_IPV6
  hints.ai_flags = 0;

  err = getaddrinfo_with_timeout (host, NULL, &hints, &res, opt.dns_timeout);
  if (err != 0 || res == NULL)
    {
      if (!silent)
	logprintf (LOG_VERBOSE, _("failed: %s.\n"),
		   err != EAI_SYSTEM ? gai_strerror (err) : strerror (errno));
      return NULL;
