     become apparent later.  */
  if (*respline != '2')
    {
      xfree (respline);
      if (res != -1)
	logprintf (LOG_NOTQUIET, "%s (%s) - ", tms, tmrate);
      logputs (LOG_NOTQUIET, _("Data transfer aborted.\n"));
      return FTPRETRINT;
    }
  xfree (respline);

  if (res == -1)
    {
