    *newloc = NULL;
  if (file)
    *file = NULL;

  redirections = NULL;

  u = newurl ();
  /* Parse the URL. */
  result = parseurl (url, u, 0);
  if (result != URLOK)
    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, uerrmsg (result));
      freeurl (u, 1);
      free_slist (redirections);
      return result;
    }

 redirected:

  /* Set the referer.  */
  if (refurl)
    u->referer = xstrdup (refurl);
