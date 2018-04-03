      xfree (mynewloc);
      mynewloc = xstrdup (newloc_parsed->url);

      /* Check for max. number of redirections.  */
      if (++redirection_count > MAX_REDIRECTIONS)
	{
	  logprintf (LOG_NOTQUIET, _("%d redirections exceeded.\n"),
		     MAX_REDIRECTIONS);
	  url_free (newloc_parsed);
	  url_free (u);
	  xfree (url);
	  xfree (mynewloc);
	  return WRONGCODE;
	}

      xfree (url);
      url = mynewloc;
