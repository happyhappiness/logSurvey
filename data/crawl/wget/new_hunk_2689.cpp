   retried, and retried, and retried, and...  */
uerr_t
http_loop (struct url *u, char **newloc, char **local_file, const char *referer,
           int *dt, struct url *proxy)
{
  int count;
  bool got_head = false;         /* used for time-stamping */
  char *tms;
  const char *tmrate;
  uerr_t err;
  time_t tmr = -1;               /* remote time-stamp */
  wgint local_size = 0;          /* the size of the local file */
  struct http_stat hstat;        /* HTTP status */
  struct_stat st;

  DEBUGP(("in http_loop\n"));

  /* Assert that no value for *LOCAL_FILE was passed. */
  assert (local_file == NULL || *local_file == NULL);
  
  /* Set LOCAL_FILE parameter. */
  if (local_file && opt.output_document)
    *local_file = HYPHENP (opt.output_document) ? NULL : xstrdup (opt.output_document);
  
  /* Reset NEWLOC parameter. */
  *newloc = NULL;

  /* This used to be done in main(), but it's a better idea to do it
     here so that we don't go through the hoops if we're just using
     FTP or whatever. */
  if (opt.cookies)
    load_cookies();

  /* Warn on (likely bogus) wildcard usage in HTTP. */
  if (opt.ftp_glob && has_wildcards_p (u->path))
    logputs (LOG_VERBOSE, _("Warning: wildcards not supported in HTTP.\n"));

  /* Setup hstat struct. */
  xzero (hstat);
  hstat.referer = referer;

  if (opt.output_document)
    hstat.local_file = xstrdup (opt.output_document);

  /* Reset the counter. */
  count = 0;
  
  /* Reset the document type. */
  *dt = 0;
  
  /* THE loop */
  do
    {
      DEBUGP(("in http_loop LOOP\n"));

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
          logprintf (LOG_VERBOSE, "--%s--  %s\n  %s\n",
                     tms, hurl, tmp);
#ifdef WINDOWS
          ws_changetitle (hurl);
#endif
          xfree (hurl);
        }

      /* Default document type is empty.  However, if spider mode is
         on or time-stamping is employed, HEAD_ONLY commands is
         encoded within *dt.  */
      if (opt.spider || (opt.timestamping && !got_head))
        *dt |= HEAD_ONLY;
      else
        *dt &= ~HEAD_ONLY;

      /* Decide whether or not to restart.  */
      if (opt.always_rest
          && stat (hstat.local_file, &st) == 0
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
      if ((proxy && count > 1)        /* a */
          || !opt.allow_cache         /* b */
          )
        *dt |= SEND_NOCACHE;
      else
        *dt &= ~SEND_NOCACHE;

      /* Try fetching the document, or at least its head.  */
      err = gethttp (u, &hstat, dt, proxy);

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
          //free_hstat (&hstat);
          printwhat (count, opt.ntry);
          continue;
        case HOSTERR: case CONIMPOSSIBLE: case PROXERR: case AUTHFAILED: 
        case SSLINITFAILED: case CONTNOTSUPPORTED:
          /* Fatal errors just return from the function.  */
          free_hstat (&hstat);
          return err;
        case FWRITEERR: case FOPENERR:
          /* Another fatal error.  */
          logputs (LOG_VERBOSE, "\n");
          logprintf (LOG_NOTQUIET, _("Cannot write to `%s' (%s).\n"),
                     hstat.local_file, strerror (errno));
          free_hstat (&hstat);
          return err;
        case CONSSLERR:
          /* Another fatal error.  */
          logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
          free_hstat (&hstat);
          return err;
        case NEWLOCATION:
          /* Return the new location to the caller.  */
          if (!*newloc)
            {
              logprintf (LOG_NOTQUIET,
                         _("ERROR: Redirection (%d) without location.\n"),
                         hstat.statcode);
              free_hstat (&hstat);
              return WRONGCODE;
            }
          free_hstat (&hstat);
          return NEWLOCATION;
        case RETRUNNEEDED:
          /* The file was already fully retrieved. */
          free_hstat (&hstat);
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
          return WRONGCODE;
        }

      /* Did we get the time-stamp? */
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
      if (opt.timestamping && !got_head)
        {
          got_head = true;    /* no more time-stamping */
          *dt &= ~HEAD_ONLY;
          count = 0;          /* the retrieve count for HEAD is reset */
          
          if (hstat.remote_time && tmr != (time_t) (-1))
            {
              /* Now time-stamping can be used validly.  Time-stamping
                 means that if the sizes of the local and remote file
                 match, and local file is newer than the remote file,
                 it will not be retrieved.  Otherwise, the normal
                 download procedure is resumed.  */
              if (hstat.orig_file_tstamp >= tmr)
                {
                  if (hstat.contlen == -1 || hstat.orig_file_size == hstat.contlen)
                    {
                      logprintf (LOG_VERBOSE, _("\
Server file no newer than local file `%s' -- not retrieving.\n\n"),
                                 hstat.orig_file_name);
                      free_hstat (&hstat);
                      return RETROK;
                    }
                  else
                    {
                      logprintf (LOG_VERBOSE, _("\
The sizes do not match (local %s) -- retrieving.\n"),
                                 number_to_static_string (local_size));
                    }
                }
              else
                logputs (LOG_VERBOSE,
                         _("Remote file is newer, retrieving.\n"));
            }
          
          //free_hstat (&hstat);
          hstat.timestamp_checked = true;
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
            fl = hstat.local_file;
          if (fl)
            touch (fl, tmr);
        }
      /* End of time-stamping section. */

      if (opt.spider)
        {
          logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode,
                     escnonprint (hstat.error));
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
                         tms, tmrate, hstat.local_file,
                         number_to_static_string (hstat.len),
                         number_to_static_string (hstat.contlen));
              logprintf (LOG_NONVERBOSE,
                         "%s URL:%s [%s/%s] -> \"%s\" [%d]\n",
                         tms, u->url,
                         number_to_static_string (hstat.len),
                         number_to_static_string (hstat.contlen),
                         hstat.local_file, count);
            }
          ++opt.numurls;
          total_downloaded_bytes += hstat.len;

          /* Remember that we downloaded the file for later ".orig" code. */
          if (*dt & ADDED_HTML_EXTENSION)
            downloaded_file(FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED, hstat.local_file);
          else
            downloaded_file(FILE_DOWNLOADED_NORMALLY, hstat.local_file);

          free_hstat (&hstat);
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
                             tms, tmrate, hstat.local_file,
                             number_to_static_string (hstat.len));
                  logprintf (LOG_NONVERBOSE,
                             "%s URL:%s [%s] -> \"%s\" [%d]\n",
                             tms, u->url, number_to_static_string (hstat.len),
                             hstat.local_file, count);
                }
              ++opt.numurls;
              total_downloaded_bytes += hstat.len;

              /* Remember that we downloaded the file for later ".orig" code. */
              if (*dt & ADDED_HTML_EXTENSION)
                downloaded_file(FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED, hstat.local_file);
              else
                downloaded_file(FILE_DOWNLOADED_NORMALLY, hstat.local_file);
              
              free_hstat (&hstat);
              return RETROK;
            }
          else if (hstat.len < hstat.contlen) /* meaning we lost the
                                                 connection too soon */
            {
              logprintf (LOG_VERBOSE,
                         _("%s (%s) - Connection closed at byte %s. "),
                         tms, tmrate, number_to_static_string (hstat.len));
              printwhat (count, opt.ntry);
              //free_hstat (&hstat);
              continue;
            }
          else
            /* Getting here would mean reading more data than
               requested with content-length, which we never do.  */
            abort ();
        }
      else /* from now on hstat.res can only be -1 */
        {
          if (hstat.contlen == -1)
            {
              logprintf (LOG_VERBOSE,
                         _("%s (%s) - Read error at byte %s (%s)."),
                         tms, tmrate, number_to_static_string (hstat.len),
                         hstat.rderrmsg);
              printwhat (count, opt.ntry);
              //free_hstat (&hstat);
              continue;
            }
          else /* hstat.res == -1 and contlen is given */
            {
              logprintf (LOG_VERBOSE,
                         _("%s (%s) - Read error at byte %s/%s (%s). "),
                         tms, tmrate,
                         number_to_static_string (hstat.len),
                         number_to_static_string (hstat.contlen),
                         hstat.rderrmsg);
              printwhat (count, opt.ntry);
              //free_hstat (&hstat);
              continue;
            }
        }
      /* not reached */
    }
  while (!opt.ntry || (count < opt.ntry));
  
  return TRYLIMEXC;
}

