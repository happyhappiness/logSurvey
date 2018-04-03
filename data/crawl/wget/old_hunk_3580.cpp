      mynewloc = construced_newloc;

      /* Now, see if this new location makes sense. */
      newloc_struct = newurl ();
      newloc_result = parseurl (mynewloc, newloc_struct, 1);
      if (newloc_result != URLOK)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc, uerrmsg (newloc_result));
	  freeurl (newloc_struct, 1);
	  freeurl (u, 1);
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
