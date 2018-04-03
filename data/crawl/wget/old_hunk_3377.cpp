    return cookie;

  delete_cookie (cookie);
  if (state == S_ERROR)
    logprintf (LOG_NOTQUIET, _("Syntax error in Set-Cookie at character `%c'.\n"), c);
  else
    abort ();
  return NULL;

 eof:
  delete_cookie (cookie);
  logprintf (LOG_NOTQUIET,
	     _("Syntax error in Set-Cookie: premature end of string.\n"));
  return NULL;
}

