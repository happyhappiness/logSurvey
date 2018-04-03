 error:
  if (!silent)
    logprintf (LOG_NOTQUIET,
	       _("Syntax error in Set-Cookie: %s at position %d.\n"),
	       escnonprint (set_cookie), (int) (ptr - set_cookie));
  delete_cookie (cookie);
  return NULL;
}
