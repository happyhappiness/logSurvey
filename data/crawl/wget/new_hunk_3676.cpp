	  logputs (LOG_NOTQUIET, _("End of file while parsing headers.\n"));
	  xfree (hdr);
	  FREE_MAYBE (type);
	  FREE_MAYBE (all_headers);
	  CLOSE_INVALIDATE (sock);
	  return HEOF;
