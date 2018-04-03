  /* Open the file -- if opt.dfp is set, use it instead.  */
  if (!opt.dfp || con->cmd & DO_LIST)
    {
      mkalldirs (con->target);
      if (opt.backups)
	rotate_backups (con->target);
      /* #### Is this correct? */
      chmod (con->target, 0600);

      fp = fopen (con->target, restval ? "ab" : "wb");
      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target, strerror (errno));
	  CLOSE (csock);
	  rbuf_uninitialize (&con->rbuf);
	  closeport (dtsock);
