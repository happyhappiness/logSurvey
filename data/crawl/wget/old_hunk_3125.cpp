      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", *hs->local_file, strerror (errno));
	  CLOSE_INVALIDATE (sock); /* would be CLOSE_FINISH, but there
				      might be more bytes in the body. */
	  return FOPENERR;
	}
    }
  else				/* opt.dfp */
    {
      extern int global_download_count;
      fp = opt.dfp;
      /* To ensure that repeated "from scratch" downloads work for -O
	 files, we rewind the file pointer, unless restval is
	 non-zero.  (This works only when -O is used on regular files,
	 but it's still a valuable feature.)

	 However, this loses when more than one URL is specified on
	 the command line the second rewinds eradicates the contents
	 of the first download.  Thus we disable the above trick for
	 all the downloads except the very first one.

         #### A possible solution to this would be to remember the
	 file position in the output document and to seek to that
	 position, instead of rewinding.

         We don't truncate stdout, since that breaks
	 "wget -O - [...] >> foo".
      */
      if (!hs->restval && global_download_count == 0 && opt.dfp != stdout)
	{
	  /* This will silently fail for streams that don't correspond
	     to regular files, but that's OK.  */
	  rewind (fp);
	  /* ftruncate is needed because opt.dfp is opened in append
	     mode if opt.always_rest is set.  */
	  ftruncate (fileno (fp), 0);
	  clearerr (fp);
	}
    }

  /* #### This confuses the code that checks for file size.  There
     should be some overhead information.  */
  if (opt.save_headers)
    fwrite (head, 1, strlen (head), fp);

  /* Download the request body.  */
  hs->res = fd_read_body (sock, fp, contlen != -1 ? contlen : 0, keep_alive,
			  hs->restval, &hs->len, &hs->dltime);
  hs->len += contrange;

  if (hs->res >= 0)
    CLOSE_FINISH (sock);
