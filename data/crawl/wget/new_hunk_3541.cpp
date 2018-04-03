      mynewloc = construced_newloc;

      /* Now, see if this new location makes sense. */
      newloc_struct = url_parse (mynewloc, &up_error_code);
      if (!newloc_struct)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc,
		     url_error (up_error_code));
	  url_free (newloc_struct);
	  url_free (u);
	  if (redirections)
