	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc, uerrmsg (newloc_result));
	  freeurl (newloc_struct, 1);
	  freeurl (u, 1);
	  free_slist (redirections);
	  free (url);
	  free (mynewloc);
	  return result;
