      mynewloc = construced_newloc;

      /* Now, see if this new location makes sense. */
      newloc_struct = url_parse (mynewloc, NULL);
      if (!newloc_struct)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc, "UNKNOWN");
	  url_free (newloc_struct);
	  url_free (u);
	  if (redirections)
