
      /* The new location is OK.  Check for redirection cycle by
         peeking through the history of redirections. */
      if (string_set_contains (redirections, newloc_parsed->url))
	{
	  logprintf (LOG_NOTQUIET, _("%s: Redirection cycle detected.\n"),
		     mynewloc);
	  url_free (newloc_parsed);
	  url_free (u);
	  if (redirections)
	    string_set_free (redirections);
