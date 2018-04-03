               false);
  blacklist_add (blacklist, start_url_parsed->url);

  FILE *rejectedlog = 0; /* Don't write a rejected log. */
  if (opt.rejected_log)
    {
      rejectedlog = fopen (opt.rejected_log, "w");
      write_reject_log_header (rejectedlog);
      if (!rejectedlog)
        logprintf (LOG_NOTQUIET, "%s: %s\n", opt.rejected_log, strerror (errno));
    }

  while (1)
    {
      bool descend = false;
