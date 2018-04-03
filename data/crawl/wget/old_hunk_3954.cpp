    int count = 0;
    urlpos *dry = l;
    for (dry = l; dry; dry = dry->next)
      if (dry->flags & (UABS2REL | UREL2ABS))
	++count;
    if (!count)
      {
	logprintf (LOG_VERBOSE, _("Nothing to do while converting %s.\n"),
		   file);
	return;
      }
  }

  logprintf (LOG_VERBOSE, _("Converting %s... "), file);

  fm = read_file (file);
  if (!fm)
    {
