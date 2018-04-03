  if (!fp)
    {
      logprintf (LOG_NOTQUIET, _("Cannot open cookies file `%s': %s\n"),
		 file, strerror (errno));
      return;
    }
  cookies_now = time (NULL);
