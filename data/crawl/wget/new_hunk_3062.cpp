	{
	  logprintf (LOG_VERBOSE,
		     _("Location: %s%s\n"),
		     hs->newloc ? escnonprint_uri (hs->newloc) : _("unspecified"),
		     hs->newloc ? _(" [following]") : "");
	  if (keep_alive)
	    skip_short_body (sock, contlen);
