 eof:
  delete_cookie (cookie);
  logprintf (LOG_NOTQUIET,
	     _("Syntax error in Set-Cookie: premature end of string.\n"));
  return NULL;
}

