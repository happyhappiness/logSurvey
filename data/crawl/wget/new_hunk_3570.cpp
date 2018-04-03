  /* Open the local file.  */
  if (!opt.dfp)
    {
      mkalldirs (*hs->local_file);
      if (opt.backups)
	rotate_backups (*hs->local_file);
      fp = fopen (*hs->local_file, hs->restval ? "ab" : "wb");
      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", *hs->local_file, strerror (errno));
	  CLOSE_INVALIDATE (sock); /* would be CLOSE_FINISH, but there
				      might be more bytes in the body. */
	  FREE_MAYBE (all_headers);
