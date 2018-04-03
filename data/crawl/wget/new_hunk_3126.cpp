  if (strchr (u->url, '*'))
    logputs (LOG_VERBOSE, _("Warning: wildcards not supported in HTTP.\n"));

  xzero (hstat);

  /* Determine the local filename.  */
  if (local_file && *local_file)
    hstat.local_file = local_file;
