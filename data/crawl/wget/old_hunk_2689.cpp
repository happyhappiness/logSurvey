   retried, and retried, and retried, and...  */
uerr_t
http_loop (struct url *u, char **newloc, char **local_file, const char *referer,
	   int *dt, struct url *proxy)
{
  int count;
  bool use_ts, got_head = false;/* time-stamping info */
  char *filename_plus_orig_suffix;
  char *local_filename = NULL;
  char *tms, *locf;
  const char *tmrate;
  uerr_t err;
  time_t tml = -1, tmr = -1;	/* local and remote time-stamps */
  wgint local_size = 0;		/* the size of the local file */
  size_t filename_len;
  struct http_stat hstat;	/* HTTP status */
  struct_stat st;
  char *dummy = NULL;

  /* This used to be done in main(), but it's a better idea to do it
     here so that we don't go through the hoops if we're just using
     FTP or whatever. */
  if (opt.cookies)
    {
      if (!wget_cookie_jar)
	wget_cookie_jar = cookie_jar_new ();
      if (opt.cookies_input && !cookies_loaded_p)
	{
	  cookie_jar_load (wget_cookie_jar, opt.cookies_input);
	  cookies_loaded_p = true;
	}
    }

  *newloc = NULL;

  /* Warn on (likely bogus) wildcard usage in HTTP.  */
  if (opt.ftp_glob && has_wildcards_p (u->path))
    logputs (LOG_VERBOSE, _("Warning: wildcards not supported in HTTP.\n"));

  xzero (hstat);

  /* Determine the local filename.  */
  if (local_file && *local_file)
    hstat.local_file = local_file;
  else if (local_file && !opt.output_document)
    {
      *local_file = url_file_name (u);
      hstat.local_file = local_file;
    }
  else
    {
      dummy = url_file_name (u);
      hstat.local_file = &dummy;
      /* be honest about where we will save the file */
      if (local_file && opt.output_document)
        *local_file = HYPHENP (opt.output_document) ? NULL : xstrdup (opt.output_document);
    }

  if (!opt.output_document)
    locf = *hstat.local_file;
  else
    locf = opt.output_document;

  hstat.referer = referer;

  filename_len = strlen (*hstat.local_file);
  filename_plus_orig_suffix = alloca (filename_len + sizeof (".orig"));

  if (opt.noclobber && file_exists_p (*hstat.local_file))
    {
      /* If opt.noclobber is turned on and file already exists, do not
	 retrieve the file */
      logprintf (LOG_VERBOSE, _("\
File `%s' already there; not retrieving.\n\n"), *hstat.local_file);
      /* If the file is there, we suppose it's retrieved OK.  */
      *dt |= RETROKF;

      /* #### Bogusness alert.  */
      /* If its suffix is "html" or "htm" or similar, assume text/html.  */
      if (has_html_suffix_p (*hstat.local_file))
	*dt |= TEXTHTML;

      xfree_null (dummy);
      return RETROK;
    }

  use_ts = false;
  if (opt.timestamping)
    {
      bool local_dot_orig_file_exists = false;

      if (opt.backup_converted)
	/* If -K is specified, we'll act on the assumption that it was specified
	   last time these files were downloaded as well, and instead of just
	   comparing local file X against server file X, we'll compare local
	   file X.orig (if extant, else X) against server file X.  If -K
	   _wasn't_ specified last time, or the server contains files called
	   *.orig, -N will be back to not operating correctly with -k. */
	{
	  /* Would a single s[n]printf() call be faster?  --dan

	     Definitely not.  sprintf() is horribly slow.  It's a
	     different question whether the difference between the two
	     affects a program.  Usually I'd say "no", but at one
	     point I profiled Wget, and found that a measurable and
	     non-negligible amount of time was lost calling sprintf()
	     in url.c.  Replacing sprintf with inline calls to
	     strcpy() and number_to_string() made a difference.
	     --hniksic */
	  memcpy (filename_plus_orig_suffix, *hstat.local_file, filename_len);
	  memcpy (filename_plus_orig_suffix + filename_len,
		  ".orig", sizeof (".orig"));

	  /* Try to stat() the .orig file. */
	  if (stat (filename_plus_orig_suffix, &st) == 0)
	    {
	      local_dot_orig_file_exists = 1;
	      local_filename = filename_plus_orig_suffix;
	    }
	}      

      if (!local_dot_orig_file_exists)
	/* Couldn't stat() <file>.orig, so try to stat() <file>. */
	if (stat (*hstat.local_file, &st) == 0)
	  local_filename = *hstat.local_file;

      if (local_filename != NULL)
	/* There was a local file, so we'll check later to see if the version
	   the server has is the same version we already have, allowing us to
	   skip a download. */
	{
	  use_ts = true;
	  tml = st.st_mtime;
#ifdef WINDOWS
	  /* Modification time granularity is 2 seconds for Windows, so
	     increase local time by 1 second for later comparison. */
	  tml++;
#endif
	  local_size = st.st_size;
	  got_head = false;
	}
    }
  /* Reset the counter.  */
  count = 0;
  *dt = 0;
  /* THE loop */
  do
    {
      /* Increment the pass counter.  */
      ++count;
      sleep_between_retrievals (count);
      /* Get the current time string.  */
      tms = time_str (NULL);
      /* Print fetch message, if opt.verbose.  */
      if (opt.verbose)
	{
	  char *hurl = url_string (u, true);
	  char tmp[256];
	  strcpy (tmp, "        ");
	  if (count > 1)
	    sprintf (tmp, _("(try:%2d)"), count);
	  logprintf (LOG_VERBOSE, "--%s--  %s\n  %s => `%s'\n",
		     tms, hurl, tmp, locf);
#ifdef WINDOWS
	  ws_changetitle (hurl);
#endif
	  xfree (hurl);
	}

      /* Default document type is empty.  However, if spider mode is
	 on or time-stamping is employed, HEAD_ONLY commands is
	 encoded within *dt.  */
      if (opt.spider || (use_ts && !got_head))
	*dt |= HEAD_ONLY;
      else
	*dt &= ~HEAD_ONLY;

      /* Decide whether or not to restart.  */
      if (opt.always_rest
	  && stat (locf, &st) == 0
	  && S_ISREG (st.st_mode))
	/* When -c is used, continue from on-disk size.  (Can't use
	   hstat.len even if count>1 because we don't want a failed
	   first attempt to clobber existing data.)  */
	hstat.restval = st.st_size;
      else if (count > 1)
	/* otherwise, continue where the previous try left off */
	hstat.restval = hstat.len;
      else
	hstat.restval = 0;

      /* Decide whether to send the no-cache directive.  We send it in
	 two cases:
	   a) we're using a proxy, and we're past our first retrieval.
	      Some proxies are notorious for caching incomplete data, so
	      we require a fresh get.
	   b) caching is explicitly inhibited. */
      if ((proxy && count > 1)	/* a */
	  || !opt.allow_cache	/* b */
	  )
	*dt |= SEND_NOCACHE;
      else
	*dt &= ~SEND_NOCACHE;

      /* Try fetching the document, or at least its head.  */
      err = gethttp (u, &hstat, dt, proxy);

      /* It's unfortunate that wget determines the local filename before finding
	 out the Content-Type of the file.  Barring a major restructuring of the
	 code, we need to re-set locf here, since gethttp() may have xrealloc()d
	 *hstat.local_file to tack on ".html". */
      if (!opt.output_document)
	locf = *hstat.local_file;

      /* Time?  */
      tms = time_str (NULL);
      /* Get the new location (with or without the redirection).  */
      if (hstat.newloc)
	*newloc = xstrdup (hstat.newloc);
      switch (err)
	{
	case HERR: case HEOF: case CONSOCKERR: case CONCLOSED:
	case CONERROR: case READERR: case WRITEFAILED:
	case RANGEERR: case FOPEN_EXCL_ERR:
	  /* Non-fatal errors continue executing the loop, which will
	     bring them to "while" statement at the end, to judge
	     whether the number of tries was exceeded.  */
	  free_hstat (&hstat);
	  printwhat (count, opt.ntry);
	  if (err == FOPEN_EXCL_ERR)
	    {
	      /* Re-determine the file name. */
	      if (local_file && *local_file)
		{
		  xfree (*local_file);
		  *local_file = url_file_name (u);
		  hstat.local_file = local_file;
		}
	      else
		{
		  xfree (dummy);
		  dummy = url_file_name (u);
		  hstat.local_file = &dummy;
		}
	      /* be honest about where we will save the file */
	      if (local_file && opt.output_document)
		*local_file = HYPHENP (opt.output_document) ? NULL : xstrdup (opt.output_document);
	      if (!opt.output_document)
		locf = *hstat.local_file;
	      else
		locf = opt.output_document;
	    }
	  continue;
	case HOSTERR: case CONIMPOSSIBLE: case PROXERR: case AUTHFAILED: 
	case SSLINITFAILED: case CONTNOTSUPPORTED:
	  /* Fatal errors just return from the function.  */
	  free_hstat (&hstat);
	  xfree_null (dummy);
	  return err;
	case FWRITEERR: case FOPENERR:
	  /* Another fatal error.  */
	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET, _("Cannot write to `%s' (%s).\n"),
		     *hstat.local_file, strerror (errno));
	  free_hstat (&hstat);
	  xfree_null (dummy);
	  return err;
	case CONSSLERR:
	  /* Another fatal error.  */
	  logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
	  free_hstat (&hstat);
	  xfree_null (dummy);
	  return err;
	case NEWLOCATION:
	  /* Return the new location to the caller.  */
	  if (!hstat.newloc)
	    {
	      logprintf (LOG_NOTQUIET,
			 _("ERROR: Redirection (%d) without location.\n"),
			 hstat.statcode);
	      free_hstat (&hstat);
	      xfree_null (dummy);
	      return WRONGCODE;
	    }
	  free_hstat (&hstat);
	  xfree_null (dummy);
	  return NEWLOCATION;
	case RETRUNNEEDED:
	  /* The file was already fully retrieved. */
	  free_hstat (&hstat);
	  xfree_null (dummy);
	  return RETROK;
	case RETRFINISHED:
	  /* Deal with you later.  */
	  break;
	default:
	  /* All possibilities should have been exhausted.  */
	  abort ();
	}
      if (!(*dt & RETROKF))
	{
	  if (!opt.verbose)
	    {
	      /* #### Ugly ugly ugly! */
	      char *hurl = url_string (u, true);
	      logprintf (LOG_NONVERBOSE, "%s:\n", hurl);
	      xfree (hurl);
	    }
	  logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
		     tms, hstat.statcode, escnonprint (hstat.error));
	  logputs (LOG_VERBOSE, "\n");
	  free_hstat (&hstat);
	  xfree_null (dummy);
	  return WRONGCODE;
	}

      /* Did we get the time-stamp?  */
      if (!got_head)
	{
	  if (opt.timestamping && !hstat.remote_time)
	    {
	      logputs (LOG_NOTQUIET, _("\
Last-modified header missing -- time-stamps turned off.\n"));
	    }
	  else if (hstat.remote_time)
	    {
	      /* Convert the date-string into struct tm.  */
	      tmr = http_atotm (hstat.remote_time);
	      if (tmr == (time_t) (-1))
		logputs (LOG_VERBOSE, _("\
Last-modified header invalid -- time-stamp ignored.\n"));
	    }
	}

      /* The time-stamping section.  */
      if (use_ts)
	{
	  got_head = true;
	  *dt &= ~HEAD_ONLY;
	  use_ts = false;		/* no more time-stamping */
	  count = 0;		/* the retrieve count for HEAD is
				   reset */
	  if (hstat.remote_time && tmr != (time_t) (-1))
	    {
	      /* Now time-stamping can be used validly.  Time-stamping
		 means that if the sizes of the local and remote file
		 match, and local file is newer than the remote file,
		 it will not be retrieved.  Otherwise, the normal
		 download procedure is resumed.  */
	      if (tml >= tmr &&
		  (hstat.contlen == -1 || local_size == hstat.contlen))
		{
		  logprintf (LOG_VERBOSE, _("\
Server file no newer than local file `%s' -- not retrieving.\n\n"),
			     local_filename);
		  free_hstat (&hstat);
		  xfree_null (dummy);
		  return RETROK;
		}
	      else if (tml >= tmr)
		logprintf (LOG_VERBOSE, _("\
The sizes do not match (local %s) -- retrieving.\n"),
			   number_to_static_string (local_size));
	      else
		logputs (LOG_VERBOSE,
			 _("Remote file is newer, retrieving.\n"));
	    }
	  free_hstat (&hstat);
	  continue;
	}
      if ((tmr != (time_t) (-1))
	  && !opt.spider
	  && ((hstat.len == hstat.contlen) ||
	      ((hstat.res == 0) && (hstat.contlen == -1))))
	{
	  /* #### This code repeats in http.c and ftp.c.  Move it to a
             function!  */
	  const char *fl = NULL;
	  if (opt.output_document)
	    {
	      if (output_stream_regular)
		fl = opt.output_document;
	    }
	  else
	    fl = *hstat.local_file;
	  if (fl)
	    touch (fl, tmr);
	}
      /* End of time-stamping section.  */

      if (opt.spider)
	{
	  logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode,
		     escnonprint (hstat.error));
	  xfree_null (dummy);
	  return RETROK;
	}

      tmrate = retr_rate (hstat.rd_size, hstat.dltime);
      total_download_time += hstat.dltime;

      if (hstat.len == hstat.contlen)
	{
	  if (*dt & RETROKF)
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - `%s' saved [%s/%s]\n\n"),
			 tms, tmrate, locf,
			 number_to_static_string (hstat.len),
			 number_to_static_string (hstat.contlen));
	      logprintf (LOG_NONVERBOSE,
			 "%s URL:%s [%s/%s] -> \"%s\" [%d]\n",
			 tms, u->url,
			 number_to_static_string (hstat.len),
			 number_to_static_string (hstat.contlen),
			 locf, count);
	    }
	  ++opt.numurls;
	  total_downloaded_bytes += hstat.len;

	  /* Remember that we downloaded the file for later ".orig" code. */
	  if (*dt & ADDED_HTML_EXTENSION)
	    downloaded_file(FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED, locf);
	  else
	    downloaded_file(FILE_DOWNLOADED_NORMALLY, locf);

	  free_hstat (&hstat);
	  xfree_null (dummy);
	  return RETROK;
	}
      else if (hstat.res == 0) /* No read error */
	{
	  if (hstat.contlen == -1)  /* We don't know how much we were supposed
				       to get, so assume we succeeded. */ 
	    {
	      if (*dt & RETROKF)
		{
		  logprintf (LOG_VERBOSE,
			     _("%s (%s) - `%s' saved [%s]\n\n"),
			     tms, tmrate, locf,
			     number_to_static_string (hstat.len));
		  logprintf (LOG_NONVERBOSE,
			     "%s URL:%s [%s] -> \"%s\" [%d]\n",
			     tms, u->url, number_to_static_string (hstat.len),
			     locf, count);
		}
	      ++opt.numurls;
	      total_downloaded_bytes += hstat.len;

	      /* Remember that we downloaded the file for later ".orig" code. */
	      if (*dt & ADDED_HTML_EXTENSION)
		downloaded_file(FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED, locf);
	      else
		downloaded_file(FILE_DOWNLOADED_NORMALLY, locf);
	      
	      free_hstat (&hstat);
	      xfree_null (dummy);
	      return RETROK;
	    }
	  else if (hstat.len < hstat.contlen) /* meaning we lost the
						 connection too soon */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Connection closed at byte %s. "),
			 tms, tmrate, number_to_static_string (hstat.len));
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
	      continue;
	    }
	  else
	    /* Getting here would mean reading more data than
	       requested with content-length, which we never do.  */
	    abort ();
	}
      else			/* now hstat.res can only be -1 */
	{
	  if (hstat.contlen == -1)
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Read error at byte %s (%s)."),
			 tms, tmrate, number_to_static_string (hstat.len),
			 hstat.rderrmsg);
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
	      continue;
	    }
	  else			/* hstat.res == -1 and contlen is given */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Read error at byte %s/%s (%s). "),
			 tms, tmrate,
			 number_to_static_string (hstat.len),
			 number_to_static_string (hstat.contlen),
			 hstat.rderrmsg);
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
	      continue;
	    }
	}
      /* not reached */
    }
  while (!opt.ntry || (count < opt.ntry));
  return TRYLIMEXC;
}

