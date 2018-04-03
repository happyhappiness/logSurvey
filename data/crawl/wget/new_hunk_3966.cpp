	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc, uerrmsg (newloc_result));
	  freeurl (newloc_struct, 1);
	  freeurl (u, 1);
	  if (redirections)
	    string_set_free (redirections);
	  free (url);
	  free (mynewloc);
	  return result;
