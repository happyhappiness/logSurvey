	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc,
		     url_error (up_error_code));
	  url_free (u);
	  xfree (url);
	  xfree (mynewloc);
	  return result;
