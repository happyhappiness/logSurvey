  statcode = -1;
  *dt &= ~RETROKF;

  /* Before reading anything, initialize the rbuf.  */
  rbuf_initialize (&rbuf, sock);
  all_headers = NULL;
  all_length = 0;

  DEBUGP (("\n---response begin---\n"));

  /* Header-fetching loop.  */
  hcount = 0;
  while (1)
    {
      char *hdr;
      int status;

      ++hcount;
      /* Get the header.  */
      status = header_get (&rbuf, &hdr,
			   /* Disallow continuations for status line.  */
			   (hcount == 1 ? HG_NO_CONTINUATIONS : HG_NONE));

      /* Check for errors.  */
      if (status == HG_EOF && *hdr)
	{
	  /* This used to be an unconditional error, but that was
             somewhat controversial, because of a large number of
             broken CGI's that happily "forget" to send the second EOL
             before closing the connection of a HEAD request.

	     So, the deal is to check whether the header is empty
	     (*hdr is zero if it is); if yes, it means that the
	     previous header was fully retrieved, and that -- most
	     probably -- the request is complete.  "...be liberal in
	     what you accept."  Oh boy.  */
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("End of file while parsing headers.\n"));
	  xfree (hdr);
	  xfree_null (type);
	  xfree_null (all_headers);
	  CLOSE_INVALIDATE (sock);
	  return HEOF;
	}
      else if (status == HG_ERROR)
	{
	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET, _("Read error (%s) in headers.\n"),
		     strerror (errno));
	  xfree (hdr);
	  xfree_null (type);
	  xfree_null (all_headers);
	  CLOSE_INVALIDATE (sock);
	  return HERR;
	}

      /* If the headers are to be saved to a file later, save them to
	 memory now.  */
      if (opt.save_headers)
	{
	  int lh = strlen (hdr);
	  all_headers = (char *)xrealloc (all_headers, all_length + lh + 2);
	  memcpy (all_headers + all_length, hdr, lh);
	  all_length += lh;
	  all_headers[all_length++] = '\n';
	  all_headers[all_length] = '\0';
	}

      /* Check for status line.  */
      if (hcount == 1)
