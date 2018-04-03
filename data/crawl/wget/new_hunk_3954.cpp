    int count = 0;
    urlpos *dry = l;
    for (dry = l; dry; dry = dry->next)
      if (dry->convert != CO_NOCONVERT)
	++count;
    if (!count)
      {
	logputs (LOG_VERBOSE, _("nothing to do.\n"));
	return;
      }
  }

  fm = read_file (file);
  if (!fm)
    {
