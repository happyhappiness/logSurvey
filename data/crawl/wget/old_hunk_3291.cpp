  if (ferror (fp))
    logprintf (LOG_NOTQUIET, _("Error writing to `%s': %s\n"),
	       file, strerror (errno));

  if (fclose (fp) < 0)
    logprintf (LOG_NOTQUIET, _("Error closing `%s': %s\n"),
	       file, strerror (errno));
