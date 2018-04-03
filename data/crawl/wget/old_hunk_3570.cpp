  /* Open the local file.  */
  if (!opt.dfp)
    {
      mkalldirs (u->local);
      if (opt.backups)
	rotate_backups (u->local);
      fp = fopen (u->local, hs->restval ? "ab" : "wb");
      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", u->local, strerror (errno));
	  CLOSE_INVALIDATE (sock); /* would be CLOSE_FINISH, but there
				      might be more bytes in the body. */
	  FREE_MAYBE (all_headers);
