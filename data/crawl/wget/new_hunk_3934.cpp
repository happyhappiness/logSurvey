	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET, _("Read error (%s) in headers.\n"),
		     strerror (errno));
	  xfree (hdr);
	  FREE_MAYBE (type);
	  FREE_MAYBE (hs->newloc);
	  FREE_MAYBE (all_headers);
