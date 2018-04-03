  location_changed = (result == NEWLOCATION);
  if (location_changed)
    {
      if (mynewloc)
	{
	  /* The HTTP specs only allow absolute URLs to appear in
	     redirects, but a ton of boneheaded webservers and CGIs
	     out there break the rules and use relative URLs, and
	     popular browsers are lenient about this, so wget should
	     be too. */
	  char *construced_newloc = url_concat (url, mynewloc);
	  free (mynewloc);
	  mynewloc = construced_newloc;
	}
      /* Check for redirection to back to itself.  */
      if (url_equal (url, mynewloc))
	{
	  logprintf (LOG_NOTQUIET, _("%s: Redirection to itself.\n"),
		     mynewloc);
	  return WRONGCODE;
	}
      free (url);
      url = mynewloc;
      freeurl (u, 1);
      already_redirected = 1;
      goto again;
    }
  if (file)
    {
      if (u->local)
