	{
	  logprintf (LOG_VERBOSE,
		     _("Location: %s%s\n"),
		     hs->newloc ? hs->newloc : _("unspecified"),
		     hs->newloc ? _(" [following]") : "");
	  if (keep_alive)
	    skip_short_body (sock, contlen);
