  FILE *fp = fopen (file, "r");
  if (!fp)
    {
      logprintf (LOG_NOTQUIET, _("Cannot open cookies file %s: %s\n"),
                 quote (file), strerror (errno));
      return;
    }
  cookies_now = time (NULL);
