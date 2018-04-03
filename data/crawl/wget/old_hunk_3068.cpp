      mkalldirs (*hs->local_file);
      if (opt.backups)
	rotate_backups (*hs->local_file);
      fp = fopen (*hs->local_file, hs->restval ? "ab" : "wb");
      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", *hs->local_file, strerror (errno));
