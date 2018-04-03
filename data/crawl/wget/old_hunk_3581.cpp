	  string_set_add (redirections, u->url);
	}

      /* The new location is OK.  Let's check for redirection cycle by
         peeking through the history of redirections. */
      if (string_set_contains (redirections, newloc_struct->url))
	{
	  logprintf (LOG_NOTQUIET, _("%s: Redirection cycle detected.\n"),
		     mynewloc);
	  freeurl (newloc_struct, 1);
	  freeurl (u, 1);
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
