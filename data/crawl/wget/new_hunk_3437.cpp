  if (!silent)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);

  /* Host name lookup goes on below. */

#ifdef INET6
  {
