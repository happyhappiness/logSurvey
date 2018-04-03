      newloc_parsed = url_parse (mynewloc, &up_error_code);
      if (!newloc_parsed)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s.\n", escnonprint_uri (mynewloc),
		     url_error (up_error_code));
	  url_free (u);
	  xfree (url);
