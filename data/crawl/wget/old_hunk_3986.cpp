    *newloc = NULL;
  if (file)
    *file = NULL;
  already_redirected = 0;

 again:
  u = newurl ();
  /* Parse the URL. */
  result = parseurl (url, u, already_redirected);
  if (result != URLOK)
    {
      freeurl (u, 1);
      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, uerrmsg (result));
      return result;
    }

  /* Set the referer.  */
  if (refurl)
    u->referer = xstrdup (refurl);
