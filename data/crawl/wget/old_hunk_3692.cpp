
  delete_cookie (cookie);
  if (state == S_ERROR)
    logprintf (LOG_NOTQUIET, _("Error in Set-Cookie, at character `%c'.\n"), c);
  else
    abort ();
  return NULL;
