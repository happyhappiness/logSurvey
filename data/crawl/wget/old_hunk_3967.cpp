      free (mynewloc);
      mynewloc = xstrdup (newloc_struct->url);

      /* Check for redirection to back to itself.  */
      if (!strcmp (u->url, newloc_struct->url))
	{
	  logprintf (LOG_NOTQUIET, _("%s: Redirection to itself.\n"),
		     mynewloc);
	  freeurl (newloc_struct, 1);
	  freeurl (u, 1);
	  free_slist (redirections);
	  free (url);
	  free (mynewloc);
	  return WRONGCODE;
	}

      /* The new location is OK.  Let's check for redirection cycle by
         peeking through the history of redirections. */
      if (in_slist (redirections, newloc_struct->url))
	{
	  logprintf (LOG_NOTQUIET, _("%s: Redirection cycle detected.\n"),
		     mynewloc);
	  freeurl (newloc_struct, 1);
	  freeurl (u, 1);
	  free_slist (redirections);
	  free (url);
	  free (mynewloc);
	  return WRONGCODE;
	}

      redirections = add_slist (redirections, newloc_struct->url, NOSORT);

      free (url);
      url = mynewloc;
