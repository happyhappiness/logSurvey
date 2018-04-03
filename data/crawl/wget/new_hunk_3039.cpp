  if (!silent)
    logprintf (LOG_NOTQUIET,
	       _("Syntax error in Set-Cookie: %s at position %d.\n"),
	       escnonprint (sc), p - sc);
  return NULL;
}

