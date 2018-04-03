      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", *hs->local_file, strerror (errno));
	  CLOSE_INVALIDATE (sock);
	  return FOPENERR;
	}
    }
  else
    fp = output_stream;

  /* #### This confuses the timestamping code that checks for file
     size.  Maybe we should save some additional information?  */
  if (opt.save_headers)
    fwrite (head, 1, strlen (head), fp);

  /* Download the request body.  */
  flags = 0;
  if (keep_alive)
    flags |= rb_read_exactly;
  if (hs->restval > 0 && contrange == 0)
    flags |= rb_skip_startpos;
  hs->res = fd_read_body (sock, fp, contlen != -1 ? contlen : 0,
			  hs->restval, &hs->len, &hs->dltime, flags);
  hs->len += hs->restval;

  if (hs->res >= 0)
    CLOSE_FINISH (sock);
