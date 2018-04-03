      }
    al = address_list_from_addrinfo (res);
    freeaddrinfo (res);
    if (!al)
      {
	logprintf (LOG_VERBOSE, _("failed: No IPv4/IPv6 addresses.\n"));
	return NULL;
      }
  }
#else
  {
