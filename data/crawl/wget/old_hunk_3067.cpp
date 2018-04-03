      mkalldirs (con->target);
      if (opt.backups)
	rotate_backups (con->target);
      /* #### Is this correct? */
      chmod (con->target, 0600);

      fp = fopen (con->target, restval ? "ab" : "wb");
      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target, strerror (errno));
