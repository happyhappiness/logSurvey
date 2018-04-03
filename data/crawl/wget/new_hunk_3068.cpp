      mkalldirs (*hs->local_file);
      if (opt.backups)
	rotate_backups (*hs->local_file);
      if (hs->restval)
	fp = fopen (*hs->local_file, "ab");
      else if (opt.noclobber || opt.always_rest || opt.timestamping || opt.dirstruct
	       || opt.output_document)
	fp = fopen (*hs->local_file, "wb");
      else
	{
	  fp = fopen_excl (*hs->local_file, 0);
	  if (!fp && errno == EEXIST)
	    {
	      /* We cannot just invent a new name and use it (which is
		 what functions like unique_create typically do)
		 because we told the user we'd use this name.
		 Instead, return and retry the download.  */
	      logprintf (LOG_NOTQUIET,
			 _("%s has sprung into existence.\n"),
			 *hs->local_file);
	      CLOSE_INVALIDATE (sock);
	      return FOPEN_EXCL_ERR;
	    }
	}
      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", *hs->local_file, strerror (errno));
