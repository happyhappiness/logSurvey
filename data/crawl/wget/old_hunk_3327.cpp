	}
    }

  if (!silent)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);

  /* Host name lookup goes on below. */

#ifdef HAVE_GETADDRINFO
  {
    struct addrinfo hints, *ai;
    int err;

    memset (&hints, 0, sizeof (hints));
    if (ip_default_family == AF_INET)
      hints.ai_family   = AF_INET;
    else
      hints.ai_family   = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    err = getaddrinfo_with_timeout (host, NULL, &hints, &ai, opt.dns_timeout);

    if (err != 0 || ai == NULL)
      {
        if (!silent)
	  logprintf (LOG_VERBOSE, _("failed: %s.\n"),
		     err != EAI_SYSTEM ? gai_strerror (err) : strerror (errno));
        return NULL;
      }
    al = address_list_from_addrinfo (ai);
    freeaddrinfo (ai);
  }
#else
  {
    struct hostent *hptr;
    hptr = gethostbyname_with_timeout (host, opt.dns_timeout);
    if (!hptr)
      {
	if (!silent)
	  {
	    if (errno != ETIMEDOUT)
	      logprintf (LOG_VERBOSE, _("failed: %s.\n"), herrmsg (h_errno));
