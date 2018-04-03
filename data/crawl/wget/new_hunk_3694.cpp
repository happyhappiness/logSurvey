  if (fclose (fp) < 0)
    logprintf (LOG_NOTQUIET, _("Error closing `%s': %s\n"),
	       file, strerror (errno));

  DEBUGP (("Done saving cookies.\n", file));
}

static int
