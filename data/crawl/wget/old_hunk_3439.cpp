  }
#else
  {
    struct hostent *hptr = gethostbyname (host);
    if (!hptr)
      {
	if (!silent)
	  logprintf (LOG_VERBOSE, _("failed: %s.\n"), herrmsg (h_errno));
	return NULL;
      }
    /* Do all systems have h_addr_list, or is it a newer thing?  If
