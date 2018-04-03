    {
      mkalldirs (con->target);
      if (opt.backups)
	rotate_backups (con->target);

      if (restval)
	fp = fopen (con->target, "ab");
      else if (opt.noclobber || opt.always_rest || opt.timestamping || opt.dirstruct
	       || opt.output_document)
	fp = fopen (con->target, "wb");
      else
	{
	  fp = fopen_excl (con->target, true);
	  if (!fp && errno == EEXIST)
	    {
	      /* We cannot just invent a new name and use it (which is
		 what functions like unique_create typically do)
		 because we told the user we'd use this name.
		 Instead, return and retry the download.  */
	      logprintf (LOG_NOTQUIET, _("%s has sprung into existence.\n"),
			 con->target);
	      fd_close (csock);
	      con->csock = -1;
	      fd_close (dtsock);
	      fd_close (local_sock);
	      return FOPEN_EXCL_ERR;
	    }
	}
      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target, strerror (errno));
	  fd_close (csock);
	  con->csock = -1;
	  fd_close (dtsock);
	  fd_close (local_sock);
	  return FOPENERR;
	}
    }
  else
    fp = output_stream;
