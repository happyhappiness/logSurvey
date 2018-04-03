
  logputs (LOG_VERBOSE, _("Loading robots.txt; please ignore errors.\n"));
  *file = NULL;
  err = retrieve_url (robots_url, file, NULL, NULL, NULL, false);
  xfree (robots_url);

  if (err != RETROK && *file != NULL)
