  fp = fopen (file, "w");
  if (!fp)
    {
      logprintf (LOG_NOTQUIET, _("Cannot open cookies file %s: %s\n"),
                 quote (file), strerror (errno));
      return;
    }

