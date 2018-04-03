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
	{
	  const char *error;
	  /* Parse the first line of server response.  */
	  statcode = parse_http_status_line (hdr, &error);
	  hs->statcode = statcode;
	  /* Store the descriptive response.  */
	  if (statcode == -1) /* malformed response */
	    {
	      /* A common reason for "malformed response" error is the
                 case when no data was actually received.  Handle this
                 special case.  */
	      if (!*hdr)
		hs->error = xstrdup (_("No data received"));
	      else
		hs->error = xstrdup (_("Malformed status line"));
	      xfree (hdr);
	      break;
	    }
	  else if (!*error)
	    hs->error = xstrdup (_("(no description)"));
	  else
	    hs->error = xstrdup (error);

	  if ((statcode != -1)
#ifdef ENABLE_DEBUG
	      && !opt.debug
#endif
	      )
	    {
             if (opt.server_response)
	       logprintf (LOG_VERBOSE, "\n%2d %s", hcount, hdr);
             else
	       logprintf (LOG_VERBOSE, "%2d %s", statcode, error);
	    }

	  goto done_header;
	}

      /* Exit on empty header.  */
      if (!*hdr)
	{
	  xfree (hdr);
	  break;
	}

      /* Print the header if requested.  */
      if (opt.server_response && hcount != 1)
	logprintf (LOG_VERBOSE, "\n%2d %s", hcount, hdr);

      /* Try getting content-length.  */
      if (contlen == -1 && !opt.ignore_length)
	if (header_process (hdr, "Content-Length", header_extract_number,
			    &contlen))
	  goto done_header;
      /* Try getting content-type.  */
      if (!type)
	if (header_process (hdr, "Content-Type", http_process_type, &type))
	  goto done_header;
      /* Try getting location.  */
      if (!hs->newloc)
	if (header_process (hdr, "Location", header_strdup, &hs->newloc))
	  goto done_header;
      /* Try getting last-modified.  */
      if (!hs->remote_time)
	if (header_process (hdr, "Last-Modified", header_strdup,
			    &hs->remote_time))
	  goto done_header;
      /* Try getting cookies. */
      if (opt.cookies)
	if (header_process (hdr, "Set-Cookie", http_process_set_cookie, u))
	  goto done_header;
      /* Try getting www-authentication.  */
      if (!authenticate_h)
	if (header_process (hdr, "WWW-Authenticate", header_strdup,
			    &authenticate_h))
	  goto done_header;
      /* Check for accept-ranges header.  If it contains the word
	 `none', disable the ranges.  */
      if (*dt & ACCEPTRANGES)
	{
	  int nonep;
	  if (header_process (hdr, "Accept-Ranges", http_process_none, &nonep))
	    {
	      if (nonep)
		*dt &= ~ACCEPTRANGES;
	      goto done_header;
	    }
	}
      /* Try getting content-range.  */
      if (contrange == -1)
	{
	  struct http_process_range_closure closure;
	  if (header_process (hdr, "Content-Range", http_process_range, &closure))
	    {
	      contrange = closure.first_byte_pos;
	      goto done_header;
	    }
	}
      /* Check for keep-alive related responses. */
      if (!inhibit_keep_alive)
	{
	  /* Check for the `Keep-Alive' header. */
	  if (!http_keep_alive_1)
	    {
	      if (header_process (hdr, "Keep-Alive", header_exists,
				  &http_keep_alive_1))
		goto done_header;
	    }
	  /* Check for `Connection: Keep-Alive'. */
	  if (!http_keep_alive_2)
	    {
	      if (header_process (hdr, "Connection", http_process_connection,
				  &http_keep_alive_2))
		goto done_header;
	    }
	}
    done_header:
      xfree (hdr);
    }
  DEBUGP (("---response end---\n"));

  logputs (LOG_VERBOSE, "\n");

  if (contlen != -1
      && (http_keep_alive_1 || http_keep_alive_2))
    {
      assert (inhibit_keep_alive == 0);
      keep_alive = 1;
    }
  if (keep_alive)
    /* The server has promised that it will not close the connection
       when we're done.  This means that we can register it.  */
