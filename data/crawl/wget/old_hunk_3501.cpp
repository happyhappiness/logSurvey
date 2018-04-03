	  string_set_add (redirections, u->url);
	}

      /* The new location is OK.  Check for redirection cycle by
         peeking through the history of redirections. */
      if (string_set_contains (redirections, newloc_parsed->url))
	{
