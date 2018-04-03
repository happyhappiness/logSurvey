  statcode = -1;
  *dt &= ~RETROKF;

  DEBUGP (("\n---response begin---\n"));

  head = fd_read_head (sock);
  if (!head)
    {
      logputs (LOG_VERBOSE, "\n");
      if (errno == 0)
	{
	  logputs (LOG_NOTQUIET, _("No data received.\n"));
	  CLOSE_INVALIDATE (sock);
	  return HEOF;
	}
      else
	{
	  logprintf (LOG_NOTQUIET, _("Read error (%s) in headers.\n"),
		     strerror (errno));
	  CLOSE_INVALIDATE (sock);
	  return HERR;
	}
    }

  /* Loop through the headers and process them. */

  hcount = 0;
  for (hdr_beg = head;
       (hdr_end = next_header (hdr_beg));
       hdr_beg = hdr_end)
    {
      char *hdr = strdupdelim (hdr_beg, hdr_end);
      {
	char *tmp = hdr + strlen (hdr);
	if (tmp > hdr && tmp[-1] == '\n')
	  *--tmp = '\0';
	if (tmp > hdr && tmp[-1] == '\r')
	  *--tmp = '\0';
      }
      ++hcount;

      /* Check for status line.  */
      if (hcount == 1)
